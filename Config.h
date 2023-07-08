#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
#include <map>
#include <utility>
#include <PlantConf.h>

class StoreItem {
public:
    int Id;
    QList<QPair<int, int>> Price;
    enum StoreItemStatus {
        正常 = 1,
        材料不足 = 2,
        未解锁 = 3
    };
    StoreItem(int id, QList<QPair<int, int>> price);
};

class WishItem {
public:
    QString Info;
    std::map<int, int> Prob;
    int Price, Price10;
    WishItem(QString info, std::map<int, int> prob, int price, int price10);
};

class ConfigClass {
public:
    std::map<int, PlantConf> Plants;
    std::map<QString, int> PlantNameToId;
    QList<StoreItem> StoreItems;
    QList<WishItem> WishItems;
    int InitMoney;
    ConfigClass(int type=0);
};

#endif // CONFIG_H
