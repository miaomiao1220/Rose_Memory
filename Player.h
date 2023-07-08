#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>
#include <FieldStatus.h>
#include <map>
#include <QFile>
#include <QStandardPaths>
#include <QDir>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

class Player {
    //public:Dictionary<int, int> SeedCount = new Dictionary<int, int>();
    //public Dictionary<int, int> GainCount = new Dictionary<int, int>();
    //public Dictionary<int, bool> IsPlantLock = new Dictionary<int, bool>();
    //public Dictionary<int, bool> IsWishLock = new Dictionary<int, bool>();
    //public Dictionary<int, bool> IsStoryUnLock = new Dictionary<int, bool>();
    //public Dictionary<int, bool> IsStoreLock = new Dictionary<int, bool>();
    //public List<FieldStatus> Field = new List<FieldStatus>();
    //public int Money;
public:
    std::map<int, int> SeedCount;
    std::map<int, int> GainCount;
    std::map<int, bool> IsPlantLock;
    std::map<int, bool> IsWishLock;
    std::map<int, bool> IsStoryUnLock;
    std::map<int, bool> IsStoreLock;
    QList<FieldStatus> Field;
    bool IsFirstEntrance;
    int Money;
    bool initialized=false;
    Player(QString config_file, bool force_new=false);
    Player();
    void exportProgress(QString archive_file);
};
#endif // PLAYER_H
