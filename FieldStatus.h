#ifndef FIELDSTATUS_H
#define FIELDSTATUS_H
#include <QObject>
#include <QJsonObject>
enum PlantGrow
{
    种子阶段 = 0,
    发芽阶段 = 1,
    成长阶段 = 2,
    收获阶段 = 3,
    植物展示 = 4,
};

class FieldStatus
{
public:
    bool isLock, isPlant, isTall, isDry; // 田地是否开垦；田地上是否有作物； 田地是否干旱
    qint64 lastWater; // 上一次浇水的时间
    int plantId; // 田地上的植物类型
    PlantGrow plantGrow; // 田地上的植物成长状态
    FieldStatus(bool myIsTall); // 构造函数
    FieldStatus(QJsonObject status);
    void UpdateFieldStatus(qint64 myTime); // 田地状态更新函数
    int TimeToNextStage(qint64 myTime);
    void WaterField(qint64 myTime); //田地灌溉函数
    void OpenField(); // 田地解锁函数
    int GatherField(); //田地收获函数，返回收获植物类型
    bool PlantSeed(int myPlant, qint64 myTime); // 田地播种函数，返回是否成功播种
    QJsonObject toJsonObject();
};
#endif // FIELDSTATUS_H
