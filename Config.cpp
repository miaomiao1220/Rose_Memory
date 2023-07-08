#include <QObject>
#include <map>
#include "Config.h"

StoreItem::StoreItem(int id, QList <QPair<int, int>> price) {
    Id = id;
    Price = std::move(price);
}

WishItem::WishItem(QString info, std::map<int, int> prob, int price, int price10) {
    Info = std::move(info);
    Prob = std::move(prob);
    Price = price;
    Price10 = price10;
}

ConfigClass::ConfigClass(int type) {
    if (type == 0) {
        Plants[11] = PlantConf("萝卜", 11, 10, QList < int > {1, 2, 4}, 1, false);
        Plants[12] = PlantConf("白菜", 12, 10, QList < int > {1, 2, 4}, 1, false);
        Plants[13] = PlantConf("茄子", 13, 10, QList < int > {1, 2, 4}, 1, false);
        Plants[14] = PlantConf("番茄", 14, 10, QList < int > {1, 2, 4}, 1, false);
        Plants[15] = PlantConf("辣椒", 15, 10, QList < int > {1, 2, 4}, 1, false);
        Plants[16] = PlantConf("南瓜", 16, 10, QList < int > {1, 2, 4}, 1, false);
        Plants[17] = PlantConf("黄瓜", 17, 10, QList < int > {1, 2, 4}, 1, true);
        Plants[21] = PlantConf("橘子", 21, 30, QList < int > {2, 4, 8}, 2, true);
        Plants[22] = PlantConf("蓝莓", 22, 30, QList < int > {2, 4, 8}, 2, false);
        Plants[23] = PlantConf("草莓", 23, 30, QList < int > {2, 4, 8}, 2, false);
        Plants[24] = PlantConf("香蕉", 24, 30, QList < int > {2, 4, 8}, 2, true);
        Plants[25] = PlantConf("石榴", 25, 30, QList < int > {2, 4, 8}, 2, true);
        Plants[31] = PlantConf("茉莉", 31, 100, QList < int > {3, 6, 12}, 3, true);
        Plants[32] = PlantConf("芝樱", 32, 100, QList < int > {3, 6, 12}, 3, true);
        Plants[33] = PlantConf("葡萄风信子", 33, 100, QList < int > {3, 6, 12}, 3, true);
        Plants[41] = PlantConf("金蔷薇", 41, -1, QList < int > {4, 8, 16}, 3, true);

        for (auto &plant: Plants) {
            PlantNameToId[plant.second.Name] = plant.first;
        }

        StoreItems.push_back(StoreItem(16, QList < QPair < int, int >> (
                {
                    QPair<int, int>(11, 1),
                            QPair<int, int>(12, 1),
                            QPair<int, int>(13, 1),
                            QPair<int, int>(14, 1),
                            QPair<int, int>(15, 1),
                            QPair<int, int>(17, 1)
                })));

        StoreItems.push_back(StoreItem(25, QList < QPair < int, int >> (
                {
                    QPair<int, int>(16, 1),
                            QPair<int, int>(21, 2),
                            QPair<int, int>(22, 2),
                            QPair<int, int>(23, 2),
                            QPair<int, int>(24, 2),
                })));

        StoreItems.push_back(StoreItem(33, QList < QPair < int, int >> (
                {
                    QPair<int, int>(25, 1),
                            QPair<int, int>(31, 2),
                            QPair<int, int>(32, 2),
                })));

        StoreItems.push_back(StoreItem(41, QList < QPair < int, int >> (
                {
                    QPair<int, int>(33, 5),
                            QPair<int, int>(25, 2),
                            QPair<int, int>(16, 1)
                })));

        WishItems.push_back(WishItem(
                "可通过本许愿获得6种蔬菜之一，其中萝卜种子、白菜种子的获得概率各为30%，茄子种子、番茄种子的获得概率各为15%，辣椒种子、黄瓜种子的获得概率各为5%。",
                std::map<int, int>(
                        {
                                {11, 30},
                                {12, 30},
                                {13, 15},
                                {14, 15},
                                {15, 5},
                                {17, 5}
                        }), 3, 27));

        WishItems.push_back(WishItem(
                "可通过本许愿获得6种蔬菜之一或4种水果之一，其中有40%的概率获得蔬菜种子，此时各种蔬菜的获得概率与许愿一相同，另各有20%的概率获得橘子种子、蓝莓种子，各有10%的概率获得草莓种子、香蕉种子。",
                std::map<int, int>(
                        {
                                {11, 12},
                                {12, 12},
                                {13, 6},
                                {14, 6},
                                {15, 3},
                                {17, 3},
                                {21, 20},
                                {22, 20},
                                {23, 10},
                                {24, 10}
                        }), 10, 90));

        WishItems.push_back(WishItem(
                "可通过本许愿获得6种蔬菜之一、4种水果之一或2种花朵之一，其中有40%的概率获得蔬菜种子，另有30%的概率获得水果种子，在此基础上各种子概率和许愿一、许愿二相同，另有20%的概率获得茉莉种子、有10%的概率获得芝樱种子。",
                std::map<int, int>(
                        {
                                {11, 12},
                                {12, 12},
                                {13, 6},
                                {14, 6},
                                {15, 3},
                                {17, 3},
                                {21, 6},
                                {22, 6},
                                {23, 3},
                                {24, 3},
                                {31, 20},
                                {32, 10}
                        }), 20, 180));
        InitMoney = 99999;
    } else {
        Plants[11] = PlantConf("萝卜", 11, 10, QList < int > {3600, 7200, 14400}, 1, false);
        Plants[12] = PlantConf("白菜", 12, 10, QList < int > {3600, 7200, 14400}, 1, false);
        Plants[13] = PlantConf("茄子", 13, 10, QList < int > {3600, 7200, 14400}, 1, false);
        Plants[14] = PlantConf("番茄", 14, 10, QList < int > {3600, 7200, 14400}, 1, false);
        Plants[15] = PlantConf("辣椒", 15, 10, QList < int > {3600, 7200, 14400}, 1, false);
        Plants[16] = PlantConf("南瓜", 16, 10, QList < int > {3600, 7200, 14400}, 1, false);
        Plants[17] = PlantConf("黄瓜", 17, 10, QList < int > {3600, 7200, 14400}, 1, true);
        Plants[21] = PlantConf("橘子", 21, 30, QList < int > {7200, 14400, 28800}, 2, true);
        Plants[22] = PlantConf("蓝莓", 22, 30, QList < int > {7200, 14400, 28800}, 2, false);
        Plants[23] = PlantConf("草莓", 23, 30, QList < int > {7200, 14400, 28800}, 2, false);
        Plants[24] = PlantConf("香蕉", 24, 30, QList < int > {7200, 14400, 28800}, 2, true);
        Plants[25] = PlantConf("石榴", 25, 30, QList < int > {7200, 14400, 28800}, 2, true);
        Plants[31] = PlantConf("茉莉", 31, 100, QList < int > {10800, 21600, 43200}, 3, true);
        Plants[32] = PlantConf("芝樱", 32, 100, QList < int > {10800, 21600, 43200}, 3, true);
        Plants[33] = PlantConf("葡萄风信子", 33, 100, QList < int > {10800, 21600, 43200}, 3, true);
        Plants[41] = PlantConf("金蔷薇", 41, -1, QList < int > {14400, 28800, 57600}, 3, true);

        for (auto &plant: Plants) {
            PlantNameToId[plant.second.Name] = plant.first;
        }

        StoreItems.push_back(StoreItem(16, QList < QPair < int, int >> (
                {
                    QPair<int, int>(11, 1),
                            QPair<int, int>(12, 1),
                            QPair<int, int>(13, 1),
                            QPair<int, int>(14, 1),
                            QPair<int, int>(15, 1),
                            QPair<int, int>(17, 1)
                })));

        StoreItems.push_back(StoreItem(25, QList < QPair < int, int >> (
                {
                    QPair<int, int>(16, 1),
                            QPair<int, int>(21, 2),
                            QPair<int, int>(22, 2),
                            QPair<int, int>(23, 2),
                            QPair<int, int>(24, 2),
                })));

        StoreItems.push_back(StoreItem(33, QList < QPair < int, int >> (
                {
                    QPair<int, int>(25, 1),
                            QPair<int, int>(31, 2),
                            QPair<int, int>(32, 2),
                })));

        StoreItems.push_back(StoreItem(41, QList < QPair < int, int >> (
                {
                    QPair<int, int>(33, 5),
                            QPair<int, int>(25, 2),
                            QPair<int, int>(16, 1)
                })));

        WishItems.push_back(WishItem(
                "可通过本许愿获得6种蔬菜之一，其中萝卜种子、白菜种子的获得概率各为30%，茄子种子、番茄种子的获得概率各为15%，辣椒种子、黄瓜种子的获得概率各为5%。",
                std::map<int, int>(
                        {
                                {11, 30},
                                {12, 30},
                                {13, 15},
                                {14, 15},
                                {15, 5},
                                {17, 5}
                        }), 3, 27));

        WishItems.push_back(WishItem(
                "可通过本许愿获得6种蔬菜之一或4种水果之一，其中有40%的概率获得蔬菜种子，此时各种蔬菜的获得概率与许愿一相同，另各有20%的概率获得橘子种子、蓝莓种子，各有10%的概率获得草莓种子、香蕉种子。",
                std::map<int, int>(
                        {
                                {11, 12},
                                {12, 12},
                                {13, 6},
                                {14, 6},
                                {15, 3},
                                {17, 3},
                                {21, 20},
                                {22, 20},
                                {23, 10},
                                {24, 10}
                        }), 10, 90));

        WishItems.push_back(WishItem(
                "可通过本许愿获得6种蔬菜之一、4种水果之一或2种花朵之一，其中有40%的概率获得蔬菜种子，另有30%的概率获得水果种子，在此基础上各种子概率和许愿一、许愿二相同，另有20%的概率获得茉莉种子、有10%的概率获得芝樱种子。",
                std::map<int, int>(
                        {
                                {11, 12},
                                {12, 12},
                                {13, 6},
                                {14, 6},
                                {15, 3},
                                {17, 3},
                                {21, 6},
                                {22, 6},
                                {23, 3},
                                {24, 3},
                                {31, 20},
                                {32, 10}
                        }), 20, 180));
        InitMoney = 0;
    }
}

ConfigClass Config = ConfigClass();
