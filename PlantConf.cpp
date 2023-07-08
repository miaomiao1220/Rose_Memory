#include <PlantConf.h>

PlantConf::PlantConf(QString name, int id, int cost, QList<int> growTime, int wishType, bool isTall)
{
    Name = name;
    Id = id;
    Cost = cost;
    GrowTime = growTime;
    WishType = wishType;
    IsTall = isTall;
}

PlantConf::PlantConf(QString name, int id, QList<QPair<int, int>> exchange, QList<int> growTime, int wishType, bool isTall) {
    Name = name;
    Id = id;
    Cost = -1;
    Exchange = exchange;
    GrowTime = growTime;
    WishType = wishType;
    IsTall = isTall;
}
