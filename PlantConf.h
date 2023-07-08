#ifndef PLANTCONF_H
#define PLANTCONF_H

#include <QObject>
#include <QList>

class PlantConf {
public:
    QString Name;
    int Id; // 该植物的类型
    int Cost; // 该植物的对应货币价值
    QList<int> GrowTime; // 该植物的成长时间
    int WishType; // 许愿类型
    QList<QPair<int, int>> Exchange; // 兑换
    bool IsTall; // 是否为高植物

    PlantConf() = default;

    PlantConf(QString name, int id, int cost, QList<int> growTime, int wishType, bool isTall);

    PlantConf(QString name, int id, QList<QPair<int, int>> exchange, QList<int> growTime, int wishType, bool isTall);
};

#endif //PLANTCONF_H
