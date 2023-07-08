#include <Player.h>
#include <Config.h>
extern ConfigClass Config;
Player::Player(QString config_file, bool force_new) {
    QFile file(config_file);
    if(file.exists() && !force_new) {
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QString val = file.readAll();
        file.close();
        QJsonDocument archive_doc = QJsonDocument::fromJson(val.toUtf8());
        QJsonObject res = archive_doc.object();
        for (int i = 0; i < 12; ++i) {
            qInfo() << i << Qt::endl;
            Field.push_back(FieldStatus(res["Field"].toArray()[i].toObject()));
        }
        for (auto &plant: Config.Plants)
        {
            SeedCount[plant.first] = res["SeedCount"].toObject()[QString::number(plant.first)].toInt();
            GainCount[plant.first] = res["GainCount"].toObject()[QString::number(plant.first)].toInt();
            IsPlantLock[plant.first] = res["IsPlantLock"].toObject()[QString::number(plant.first)].toBool();
            IsStoryUnLock[plant.first] = res["IsStoryUnLock"].toObject()[QString::number(plant.first)].toBool();
        }
        for (int i = 0; i <= 2; ++i)
        {
            IsWishLock[i] = res["IsWishLock"].toObject()[QString::number(i)].toBool();
        }

        for (int i = 0; i <= 3; ++i)
        {
            IsStoreLock[Config.StoreItems[i].Id] =
                res["IsStoreLock"].toObject()[QString::number(Config.StoreItems[i].Id)].toBool();
        }

        IsFirstEntrance = res["IsFirstEntrance"].toBool();

        Money = res["Money"].toInt();
    } else {
        for (int i = 0; i < 8; ++i)
        {
            Field.push_back(FieldStatus(false));
        }

        for (int i = 0; i < 4; ++i)
        {
            Field.push_back(FieldStatus(true));
        }

        for (auto &plant: Config.Plants)
        {
            SeedCount[plant.first] = 0;
            GainCount[plant.first] = 0;
            IsPlantLock[plant.first] = true;
            IsStoryUnLock[plant.first] = false;
        }

        IsPlantLock[11] = false;
        SeedCount[11] = 1;

        for (int i = 0; i <= 2; ++i)
        {
            IsWishLock[i] = true;
        }

        IsStoreLock[Config.StoreItems[0].Id] = false;
        for (int i = 0; i <= 3; ++i)
        {
            IsStoreLock[Config.StoreItems[i].Id] = true;
        }

        Money = Config.InitMoney;
    }
    initialized = true;
}

void Player::exportProgress(QString archive_file) {
    if (!initialized)
        return;
    QJsonObject res;

    QJsonArray field_arr;

    for (int i = 0; i < 12; ++i)
    {
        field_arr.push_back(Field[i].toJsonObject());
    }

    QJsonObject seedcount, gaincount, isplantlock, isstoryunlock;

    for (auto &plant: Config.Plants)
    {
        seedcount[QString::number(plant.first)] = SeedCount[plant.first];
        gaincount[QString::number(plant.first)] = GainCount[plant.first];
        isplantlock[QString::number(plant.first)] = IsPlantLock[plant.first];
        isstoryunlock[QString::number(plant.first)] = IsStoryUnLock[plant.first];
    }

    QJsonObject iswishlock, isstorelock;

    for (int i = 0; i <= 2; ++i)
    {
        iswishlock[QString::number(i)] = IsWishLock[i];
    }

    for (int i = 0; i <= 3; ++i)
    {
        isstorelock[QString::number(Config.StoreItems[i].Id)] = IsStoreLock[Config.StoreItems[i].Id];
    }

    res["Money"] = Money;
    res["SeedCount"] = seedcount;
    res["GainCount"] = gaincount;
    res["IsPlantLock"] = isplantlock;
    res["IsStoryUnLock"] = isstoryunlock;
    res["IsWishLock"] = iswishlock;
    res["IsStoreLock"] = isstorelock;
    res["Field"] = field_arr;
    res["IsFirstEntrance"] = IsFirstEntrance;

    QFile file(archive_file);
    file.open(QIODevice::WriteOnly);
    QJsonDocument res_doc(res);
    file.write(res_doc.toJson());
    file.close();
}

Player::Player() {

}
