#include <FieldStatus.h>
#include <QObject>
#include <limits>
#include <Config.h>
extern ConfigClass Config;

static const qint64 qint64_max = 1e18;

FieldStatus::FieldStatus(bool myIsTall) // 构造函数
{
    isLock = false;
    isDry = true;
    isPlant = false;
    isTall = myIsTall;
    lastWater = qint64_max;
    plantId = -1;
    plantGrow = PlantGrow::种子阶段;
}

FieldStatus::FieldStatus(QJsonObject status)
{
    isLock = status["isLock"].toBool();
    isDry = status["isDry"].toBool();
    isPlant = status["isPlant"].toBool();
    isTall = status["isTall"].toBool();
    lastWater = status["lastWater"].toInteger();
    plantId = status["plantId"].toInt();
    plantGrow = PlantGrow(status["plantGrow"].toInt());
}

void FieldStatus::UpdateFieldStatus(qint64 myTime) // 田地状态更新函数
{
    if (!isPlant || plantGrow == PlantGrow::收获阶段)
        return;
    if (plantGrow == PlantGrow::种子阶段 && !isDry)
    {
        qInfo() << plantId;
        if (myTime - lastWater > Config.Plants[plantId].GrowTime[0])
        {
            plantGrow = PlantGrow::发芽阶段;
            isDry = true;
            lastWater = qint64_max;
        }
    }
    else if (plantGrow == PlantGrow::发芽阶段 && !isDry)
    {
        if (myTime - lastWater > Config.Plants[plantId].GrowTime[1])
        {
            plantGrow = PlantGrow::成长阶段;
            isDry = true;
            lastWater = qint64_max;
        }
    }
    else if (plantGrow == PlantGrow::成长阶段 && !isDry)
    {
        if (myTime - lastWater > Config.Plants[plantId].GrowTime[2])
        {
            plantGrow = PlantGrow::收获阶段;
            isDry = false;
            lastWater = qint64_max;
        }
    }
}

int FieldStatus::TimeToNextStage(qint64 myTime)
{
    if (isDry)
        return 2147483647;
    auto passed = myTime - lastWater;
    switch (plantGrow)
    {
    case PlantGrow::种子阶段:
            return Config.Plants[plantId].GrowTime[0] - passed;
    case PlantGrow::发芽阶段:
            return Config.Plants[plantId].GrowTime[1] - passed;
    case PlantGrow::成长阶段:
            return Config.Plants[plantId].GrowTime[2] - passed;
    case PlantGrow::收获阶段:
        case PlantGrow::植物展示:
        default:
            return 0;
    }
}

void FieldStatus::WaterField(qint64 myTime) //田地灌溉函数
{
    if (!isDry || !isPlant)
        return;
    isDry = false;
    lastWater = myTime;
    qInfo() << "K" << Qt::endl;
}

void FieldStatus::OpenField() // 田地解锁函数
{
    isLock = false;
}

int FieldStatus::GatherField() //田地收获函数，返回收获植物类型
{
    if (isLock || isPlant == false || plantGrow != PlantGrow::收获阶段) return -1;

    isDry = true;
    isPlant = false;
    lastWater = qint64_max;
    auto res = plantId;
    plantId = -1;
    plantGrow = PlantGrow::种子阶段;

    return res;
}

bool FieldStatus::PlantSeed(int myPlant, qint64 myTime) // 田地播种函数，返回是否成功播种
{
    if (isLock || isPlant) return false;
    if (Config.Plants[myPlant].IsTall != isTall) return false;

    isPlant = true;
    plantId = myPlant;
    plantGrow = PlantGrow::种子阶段;
    return true;
}

QJsonObject FieldStatus::toJsonObject()
{
    QJsonObject res;
    res["isLock"] = isLock;
    res["isDry"] = isDry;
    res["isPlant"] = isPlant;
    res["lastWater"] = lastWater;
    res["isTall"] = isTall;
    res["plantId"] = plantId;
    res["plantGrow"] = plantGrow;
    return res;
}
