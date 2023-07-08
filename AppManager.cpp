#include "AppManager.h"
#include "StoryDialog.h"
#include <QtLogging>
#include <QObject>
#include <QVariant>
#include <QDateTime>
#include <Player.h>
#include <Config.h>
#include <QRandomGenerator>
#include <QCursor>
#include <QPixmap>
#include <QGuiApplication>
#include <QMediaPlayer>
#include <QAudioOutput>

extern ConfigClass Config;
extern StoryDialogC StoryDialog;

AppManager::AppManager(QObject *parent) : QObject(parent) {
    m_currentConfig = 0;
    archive_id = 0;
    app = (QGuiApplication*)parent;
    setCurrentScene("startup");
    setCurrentModel("none");
    setCurrentSeed(-1);
    setCurrentTool("none");
    setFieldStatusDisplayId(-1);
    setStoryActivePanel(0);
    setBagPlantName(QStringList({"香蕉", "香蕉", "萝卜", "萝卜", "萝卜", "萝卜", "萝卜", "萝卜",
                                 "萝卜", "萝卜", "萝卜", "茄子", "萝卜", "萝卜", "芝樱", "萝卜"}));
    setBagVisible(QList<QVariant>({false, false, false, false, false, false, false, false,
                                   false, false, false, false, false, false, false, false}));
    setFieldHeight(QStringList({"低", "低", "低", "低", "低", "低", "低", "低",
                                "高", "高", "高", "高"}));
    setFieldPlantName(QStringList({"无作物", "无作物", "无作物", "无作物", "无作物", "无作物", "无作物", "无作物",
                                   "无作物", "无作物", "无作物", "无作物"}));
    setFieldPlantGrowStatus(QStringList({"", "", "", "", "", "", "", "",
                                         "", "", "", ""}));
    setFieldPlantWaterStatus(QStringList({"", "", "", "", "", "", "", "",
                                          "", "", "", ""}));
    setSeedSelectorHeightMatch(QList<QVariant>({true,true,true,true,true,true,true,true,
                                                true,true,true,true,true,true,true,true,}));
    setSeedCount(QList<QVariant>({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}));
    setGainCount(QList<QVariant>({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}));
    setFieldPlantTTN(QList<QVariant>({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
    auto t_wishPrice1 = QList<QVariant>();
    auto t_wishPrice10 = QList<QVariant>();
    for(int i = 0; i < 3; ++i) {
        t_wishPrice1.push_back(Config.WishItems[i].Price);
        t_wishPrice10.push_back(Config.WishItems[i].Price10);
    }
    setWishPrice1(t_wishPrice1);
    setWishPrice10(t_wishPrice10);
    setWishResultVisible(
            QList<QVariant>({false, false, false, false, false, false, false, false, false, false, false}));
    setWishResultPlantName(
            QStringList({"萝卜", "萝卜", "萝卜", "萝卜", "萝卜", "萝卜", "萝卜", "萝卜", "萝卜", "萝卜", "萝卜"}));
    auto normal_mouse = QPixmap(":/rose-quick/images/工具普通鼠标.png");
    auto seed_mouse = QPixmap(":/rose-quick/images/工具播种鼠标.png");
    auto water_mouse = QPixmap(":/rose-quick/images/工具浇水鼠标.png");
    auto tool_mouse = QPixmap(":/rose-quick/images/工具收获鼠标.png");
    normal_mouse.setDevicePixelRatio(2.0);
    seed_mouse.setDevicePixelRatio(2.0);
    water_mouse.setDevicePixelRatio(2.0);
    tool_mouse.setDevicePixelRatio(2.0);
    cursor[0] = QCursor(normal_mouse);
    cursor[1] = QCursor(seed_mouse);
    cursor[2] = QCursor(water_mouse);
    cursor[3] = QCursor(tool_mouse);
    app->setOverrideCursor(cursor[0]);
    qInfo() << getArchiveFile();
}

int AppManager::money() const {
    return m_money;
}

void AppManager::setMoney(int x) {
    m_money = x;
    emit moneyChanged();
}

static QString PlantGrowToName(PlantGrow x) {
    switch(x) {
    case 0:
        return QString("种子");
    case 1:
        return QString("发芽");
    case 2:
        return QString("成长");
    case 3:
        return QString("收获");
    case 4:
        return QString("植物展示");
    }
}

void AppManager::update() {
    if (player.initialized) {
        emit showStoreButtonChanged();
        emit showWishButtonChanged();
        setMoney(player.Money);
        auto t_bagVisible = QList<QVariant>();
        auto t_bagPlantName = QStringList();
        auto t_seedSelectorVisible = QList<QVariant>();
        auto t_seedSelectorPlantName = QStringList();
        auto t_seedSelectorHeightMatch = QList<QVariant>();
        auto t_seedCount = QList<QVariant>();
        auto t_gainCount = QList<QVariant>();
        auto t_storeStatus = QList<QVariant>();
        auto t_wishStatus = QList<QVariant>();
        auto t_fieldPlantName = QStringList();
        auto t_fieldGrowStatus = QStringList();
        auto t_fieldWaterStatus = QStringList();
        auto t_fieldTTN = QList<QVariant>();
        qint64 ctime = QDateTime::currentSecsSinceEpoch();
        int bag_visible_count = 0, seedSelector_count = 0;
        for (auto &x: player.IsPlantLock) {
            if (!x.second) {
                bag_visible_count += 1;
                t_bagVisible.push_back(true);
                t_bagPlantName.append(Config.Plants[x.first].Name);
                t_seedCount.push_back(player.SeedCount[x.first]);
                t_gainCount.push_back(player.GainCount[x.first]);
                if (currentField() >= 0 &&
                    player.SeedCount[x.first] > 0 &&
                    player.Field[currentField()].isTall == Config.Plants[x.first].IsTall) {
                    seedSelector_count += 1;
                    t_seedSelectorVisible.push_back(true);
                    t_seedSelectorHeightMatch.push_back(true);
                    t_seedSelectorPlantName.append(Config.Plants[x.first].Name);
                }
            }
        }
        for (auto &x: player.IsPlantLock) {
            if (!x.second) {
                if (currentField() >= 0 &&
                    player.SeedCount[x.first] > 0 &&
                    player.Field[currentField()].isTall != Config.Plants[x.first].IsTall) {
                    seedSelector_count += 1;
                    t_seedSelectorVisible.push_back(true);
                    t_seedSelectorHeightMatch.push_back(false);
                    t_seedSelectorPlantName.append(Config.Plants[x.first].Name);
                }
            }
        }
        for (int i = bag_visible_count; i < m_bagVisible.count(); ++i) {
            t_bagVisible.push_back(false);
            t_bagPlantName.push_back("萝卜");
            t_seedCount.push_back(0);
            t_gainCount.push_back(0);
        }
        for (int i = seedSelector_count; i < m_bagVisible.count(); ++i) {
            t_seedSelectorVisible.push_back(false);
            t_seedSelectorPlantName.push_back("萝卜");
            t_seedSelectorHeightMatch.push_back(true);
        }
        for (int i = 0; i < Config.StoreItems.count(); ++i) {
            int c_status = 2;
            if (!player.IsStoreLock[Config.StoreItems[i].Id]) {
                c_status = 0;
                for (int j = 0; j < Config.StoreItems[i].Price.count(); ++j) {
                    int price_item_id = Config.StoreItems[i].Price[j].first;
                    int price_item_count = Config.StoreItems[i].Price[j].second;
                    if (player.GainCount[price_item_id] < price_item_count) {
                        c_status = 1;
                        break;
                    }
                }
            }
            t_storeStatus.push_back(c_status);
        }
        for (int i = 0; i < player.Field.count(); ++i) {
            player.Field[i].UpdateFieldStatus(ctime);
            if (player.Field[i].isPlant && player.Field[i].plantId != -1) {
                t_fieldPlantName.append(Config.Plants[player.Field[i].plantId].Name);
                t_fieldGrowStatus.append(PlantGrowToName(player.Field[i].plantGrow));
                t_fieldWaterStatus.append(player.Field[i].isDry ? QString("干旱") : QString("正常"));
                t_fieldTTN.append(player.Field[i].TimeToNextStage(ctime));
            } else {
                t_fieldPlantName.append(QString("无作物"));
                t_fieldGrowStatus.append(QString(""));
                t_fieldWaterStatus.append(QString(""));
                t_fieldTTN.append(player.Field[i].TimeToNextStage(ctime));
            }
        }
        for (int i = 0; i < 3; ++i) {
            t_wishStatus.push_back(player.IsWishLock[i] ? 1 : 0);
        }
        setBagVisible(t_bagVisible);
        setBagPlantName(t_bagPlantName);
        setSeedSelectorVisible(t_seedSelectorVisible);
        setSeedSelectorHeightMatch(t_seedSelectorHeightMatch);
        setSeedSelectorPlantName(t_seedSelectorPlantName);
        setSeedCount(t_seedCount);
        setGainCount(t_gainCount);
        setStoreStatus(t_storeStatus);
        setWishStatus(t_wishStatus);
        setFieldPlantName(t_fieldPlantName);
        setFieldPlantGrowStatus(t_fieldGrowStatus);
        setFieldPlantWaterStatus(t_fieldWaterStatus);
        setFieldPlantTTN(t_fieldTTN);
        player.exportProgress(getArchiveFile());
    }
    QFile file(getArchiveFile());
    m_hasArchive = file.exists();
    emit hasArchiveChanged();
}

int AppManager::fieldStatusDisplayId() const {
    return m_fieldStatusDisplayId;
}

void AppManager::setFieldStatusDisplayId(int x) {
    m_fieldStatusDisplayId = x;
    emit fieldStatusDisplayIdChanged();
}

QString AppManager::currentTool() const {
    return m_currentTool;
}

void AppManager::setCurrentTool(QString x) {
    m_currentTool = x;
    if(x == "none")
        app->setOverrideCursor(cursor[0]);
    else if(x == "seed")
        app->setOverrideCursor(cursor[1]);
    else if(x == "water")
        app->setOverrideCursor(cursor[2]);
    else if(x == "harvest")
        app->setOverrideCursor(cursor[3]);
    else
        app->setOverrideCursor(cursor[0]);
    emit currentToolChanged();
}

int AppManager::storyActivePanel() const {
    return m_storyActivePanel;
}

void AppManager::setStoryActivePanel(int x) {
    m_storyActivePanel = x;
    emit storyActivePanelChanged();
}

QString AppManager::currentScene() const {
    return m_currentScene;
}

void AppManager::setCurrentScene(QString x) {
    m_currentScene = x;
    emit currentSceneChanged();
}

QString AppManager::currentModel() const {
    return m_currentModel;
}

void AppManager::setCurrentModel(QString x) {
    m_currentModel = x;
    emit currentModelChanged();
}

int AppManager::currentSeed() const {
    return m_currentSeed;
}

void AppManager::setCurrentSeed(int x) {
    m_currentSeed = x;
    emit currentSeedChanged();
}

QList<QVariant> AppManager::bagVisible() {
    return m_bagVisible;
}

void AppManager::setBagVisible(QList<QVariant> x) {
    m_bagVisible = x;
    emit bagVisibleChanged();
}

QStringList AppManager::bagPlantName() const {
    return m_bagPlantName;
}

void AppManager::setBagPlantName(QStringList x) {
    m_bagPlantName = x;
    emit bagPlantNameChanged();
}

QList<QVariant> AppManager::seedCount() const {
    return m_seedCount;
}

void AppManager::setSeedCount(QList<QVariant> x) {
    m_seedCount = x;
    emit seedCountChanged();
}

QList<QVariant> AppManager::gainCount() const {
    return m_gainCount;
}

void AppManager::setGainCount(QList<QVariant> x) {
    m_gainCount = x;
    emit gainCountChanged();
}

QList<QVariant> AppManager::seedSelectorVisible() const {
    return m_seedSelectorVisible;
}

void AppManager::setSeedSelectorVisible(QList<QVariant> x) {
    m_seedSelectorVisible = x;
    emit seedSelectorVisibleChanged();
}

QList<QVariant> AppManager::seedSelectorHeightMatch() const {
    return m_seedSelectorHeightMatch;
}

void AppManager::setSeedSelectorHeightMatch(QList<QVariant> x) {
    m_seedSelectorHeightMatch = x;
    emit seedSelectorHeightMatchChanged();
}

QStringList AppManager::fieldHeight() {
    return m_fieldHeight;
}

void AppManager::setFieldHeight(QStringList x) {
    m_fieldHeight = x;
    emit fieldHeightChanged();
}

QStringList AppManager::fieldPlantName() const {
    return m_fieldPlantName;
}

void AppManager::setFieldPlantName(QStringList x) {
    m_fieldPlantName = x;
    emit fieldPlantNameChanged();
}

QStringList AppManager::fieldPlantGrowStatus() const {
    return m_fieldPlantGrowStatus;
}

void AppManager::setFieldPlantGrowStatus(QStringList x) {
    m_fieldPlantGrowStatus = x;
    emit fieldPlantGrowStatusChanged();
}

QStringList AppManager::fieldPlantWaterStatus() const {
    return m_fieldPlantWaterStatus;
}

void AppManager::setFieldPlantWaterStatus(QStringList x) {
    m_fieldPlantWaterStatus = x;
    emit fieldPlantWaterStatusChanged();
}

QList<QVariant> AppManager::fieldPlantTTN() const {
    return m_fieldPlantTTN;
}

void AppManager::setFieldPlantTTN(QList<QVariant> x) {
    m_fieldPlantTTN = x;
    emit fieldPlantTTNChanged();
}

QList<QVariant> AppManager::wishResultVisible() const {
    return m_wishResultVisible;
}

void AppManager::setWishResultVisible(QList<QVariant> x) {
    m_wishResultVisible = x;
    emit wishResultVisibleChanged();
}

QStringList AppManager::wishResultPlantName() const {
    return m_wishResultPlantName;
}

void AppManager::setWishResultPlantName(QStringList x) {
    m_wishResultPlantName = x;
    emit wishResultPlantNameChanged();
}

QStringList AppManager::seedSelectorPlantName() const {
    return m_seedSelectorPlantName;
}

void AppManager::setSeedSelectorPlantName(QStringList x) {
    m_seedSelectorPlantName = x;
    emit seedSelectorPlantNameChanged();
}

QString AppManager::popupMessage() const {
    return m_popupMessage;
}

void AppManager::setPopupMessage(QString x) {
    m_popupMessage = x;
    emit popupMessageChanged();
}

QList<QVariant> AppManager::storeStatus() const {
    return m_storeStatus;
}

void AppManager::setStoreStatus(QList<QVariant> x) {
    m_storeStatus = x;
    emit storeStatusChanged();
}

QList<QVariant> AppManager::wishStatus() const {
    return m_wishStatus;
}

void AppManager::setWishStatus(QList<QVariant> x) {
    m_wishStatus = x;
    emit wishStatusChanged();
}

int AppManager::currentField() const {
    return m_currentField;
}

void AppManager::setCurrentField(int x) {
    m_currentField = x;
    emit currentFieldChanged();
}

QList<QVariant> AppManager::wishPrice1() const {
    return m_wishPrice1;
}

void AppManager::setWishPrice1(QList<QVariant> x) {
    m_wishPrice1 = x;
    emit wishPrice1Changed();
}

QList<QVariant> AppManager::wishPrice10() const {
    return m_wishPrice10;
}

void AppManager::setWishPrice10(QList<QVariant> x) {
    m_wishPrice10 = x;
    emit wishPrice10Changed();
}

QStringList AppManager::storyName() const {
    return m_storyName;
}

void AppManager::setStoryName(QStringList x) {
    m_storyName = x;
    emit storyNameChanged();
}

QStringList AppManager::storyImage() const {
    return m_storyImage;
}

void AppManager::setStoryImage(QStringList x) {
    m_storyImage = x;
    emit storyImageChanged();
}

QStringList AppManager::storyText() const {
    return m_storyText;
}

void AppManager::setStoryText(QStringList x) {
    m_storyText = x;
    emit storyTextChanged();
}

bool AppManager::hasArchive() {
    return m_hasArchive;
}

int AppManager::currentConfig() {
    return m_currentConfig;
}

void AppManager::fieldClicked(int f_id) {
    if (currentTool() == "seed") {
        setCurrentSeed(-1);
        setCurrentField(f_id);
        update();
        setCurrentModel("seedSelector");
    } else if (currentTool() == "water") {
        player.Field[f_id].WaterField(QDateTime::currentSecsSinceEpoch());
    } else if (currentTool() == "harvest") {
        auto res = player.Field[f_id].GatherField();
        if (res == -1) {
            setPopupMessage("收获失败");
        } else {
            player.GainCount[res] += 1;
            player.Money += Config.Plants[res].Cost;
            if (res == 11 && player.IsWishLock[0]) {
                player.IsWishLock[0] = false;
                setPopupMessage("许愿 已解锁");
            } else if (res == 16 && player.IsStoreLock[25]) {
                player.IsStoreLock[25] = false;
                player.IsWishLock[1] = false;
                setPopupMessage("许愿二 & 商店新商品 已解锁");
            } else if (res == 25 && player.IsStoreLock[33]) {
                player.IsStoreLock[33] = false;
                player.IsWishLock[2] = false;
                setPopupMessage("许愿三 & 商店新商品 已解锁");
            } else if (res == 33 && player.IsStoreLock[41]) {
                player.IsStoreLock[41] = false;
                setPopupMessage("商店新商品 已解锁");
            } else if (res == 41) {
                setCurrentScene("ending");
            }
            if (res != 11 && player.IsStoreLock[16]) {
                player.IsStoreLock[16] = false;
                setPopupMessage("商店 已解锁");
            }
            if (res != 41 && !player.IsStoryUnLock[res]) {
                player.IsStoryUnLock[res] = true;
                playStory(StoryDialog.Dialogs[res]);
            }
        }
    }
}

void AppManager::goSingleWish(int w_id) {
    if (Config.WishItems[w_id].Price <= player.Money)
    {
        player.Money -= Config.WishItems[w_id].Price;
    }
    else
    {
        setPopupMessage("金币不足");
        return;
    }

    int res = goWish(Config.WishItems[w_id].Prob);
    player.SeedCount[res] += 1;
    player.IsPlantLock[res] = false;
    auto t_name = QStringList();
    auto t_visible = QList<QVariant>();
    for (int i = 0; i < 10; ++i) {
        t_name.push_back("萝卜");
        t_visible.push_back(false);
    }
    t_name.push_back(Config.Plants[res].Name);
    t_visible.push_back(true);
    setWishResultPlantName(t_name);
    setWishResultVisible(t_visible);
    setCurrentModel("wishResult");
}

void AppManager::go10Wish(int w_id) {
    if (Config.WishItems[w_id].Price10 <= player.Money)
    {
        player.Money -= Config.WishItems[w_id].Price10;
    }
    else
    {
        setPopupMessage("金币不足");
        return;
    }

    auto t_name = QStringList();
    auto t_visible = QList<QVariant>();
    for (int i = 0; i < 10; ++i)
    {
        int res = goWish(Config.WishItems[w_id].Prob);
        player.SeedCount[res] += 1;
        player.IsPlantLock[res] = false;
        t_name.push_back(Config.Plants[res].Name);
        t_visible.push_back(true);
    }
    t_name.push_back("萝卜");
    t_visible.push_back(false);
    setWishResultPlantName(t_name);
    setWishResultVisible(t_visible);
    setCurrentModel("wishResult");
}

QString AppManager::getArchiveFile() {
    QString path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dir(path);
    if (!dir.exists())
        dir.mkpath(path);
    if (!dir.exists("archives"))
        dir.mkdir("archives");

    dir.cd("archives");
    path = dir.absoluteFilePath(QString::number(archive_id) + ".json");
    return path;
}

void AppManager::seedConfirm() {
    if (currentField() == -1)
    {
        setPopupMessage("未选择菜地");
        return;
    }
    if (currentSeed() == -1)
    {
        setPopupMessage("未选择种子");
        return;
    }
    auto seedId = Config.PlantNameToId[seedSelectorPlantName()[currentSeed()]];
    if (Config.Plants[seedId].IsTall != player.Field[currentField()].isTall)
    {
        setPopupMessage("高度不匹配");
        return;
    }
    if (player.SeedCount[seedId] <= 0)
    {
        setPopupMessage("没有足够的种子");
        return;
    }

    player.SeedCount[seedId] -= 1;
    if (!player.Field[currentField()].PlantSeed(seedId, QDateTime::currentSecsSinceEpoch()))
    {
        setPopupMessage("其他错误");
    }
}

int AppManager::goWish(std::map<int, int> prob)
{
    std::map<int, int> maxRoll;
    int tot_cnt = 0;
    for (auto &t: prob) {
        tot_cnt += t.second;
        maxRoll[t.first] = tot_cnt;
    }
    auto rInt = QRandomGenerator::global()->bounded(100);
    for (auto &t: prob)
    {
        if (rInt <= maxRoll[t.first])
            return t.first;
    }
    return 11;
}

void AppManager::storeClicked(int s_id) {
    if (player.IsStoreLock[Config.StoreItems[s_id].Id]) {
        setPopupMessage("未解锁");
        return;
    }
    int itemId = Config.StoreItems[s_id].Id;
    auto price = Config.StoreItems[s_id].Price;
    for (auto &priceItem: price)
    {
        auto priceId = priceItem.first;
        auto priceCount = priceItem.second;
        if (player.GainCount[priceId] < priceCount)
        {
            setPopupMessage("材料不足");
            return;
        }
    }
    for (auto &priceItem: price)
    {
        auto priceId = priceItem.first;
        auto priceCount = priceItem.second;
        player.GainCount[priceId] -= priceCount;
    }
    player.SeedCount[itemId] += 1;
    player.IsPlantLock[itemId] = false;
    setPopupMessage("兑换成功");
}

void AppManager::storyContinue() {
    storyNextStep();
}

void AppManager::playStory(QList<QList<QString>> story) {
    _story = std::move(story);
    story_progress = 0;
    setStoryImage(QStringList({"00", "00"}));
    setStoryName(QStringList({"", ""}));
    setStoryText(QStringList({"", ""}));
    setCurrentScene("story");
    setStoryActivePanel(0);
    storyNextStep();
}

void AppManager::storyNextStep() {
    if (story_progress < _story.count())
    {
        auto cur = _story[story_progress];
        story_progress += 1;
        int v = cur[0].toInt();
        auto t_storyName = storyName();
        auto t_storyImage = storyImage();
        auto t_storyText = storyText();
        t_storyName[v] = cur[2];
        t_storyImage[v] = cur[1];
        t_storyText[v] = cur[3];
        setStoryName(t_storyName);
        setStoryImage(t_storyImage);
        setStoryText(t_storyText);
        setStoryActivePanel(v);
    }
    else
    {
        if (player.IsFirstEntrance) {
            player.IsFirstEntrance = false;
            setPopupMessage("获得：萝卜种子*1");
        }
        setCurrentScene("main");
    }
}

void AppManager::startGame() {
    player = Player(getArchiveFile());
    if(!player.IsFirstEntrance) {
        setCurrentScene("main");
    } else {
        playStory(StoryDialog.Dialogs[0]);
    }
}

void AppManager::newGame() {

    player = Player(getArchiveFile(), true);
    playStory(StoryDialog.Dialogs[0]);
}

void AppManager::soundEffect(QString x) {
    if (x == "pick") {
        auto player = new QMediaPlayer;
        auto audioOutput = new QAudioOutput;
        player->setAudioOutput(audioOutput);
        player->setSource(QUrl("file://" + QGuiApplication::applicationDirPath() + "/audios/pick.mp3"));
        audioOutput->setVolume(50);
        player->play();
    }
}

void AppManager::switchConfig() {
    m_currentConfig ^= 1;
    Config = ConfigClass(m_currentConfig);
    emit currentConfigChanged();
}

bool AppManager::showStoreButton() {
    return !player.IsStoreLock[Config.StoreItems[0].Id];
}

bool AppManager::showWishButton() {
    return !player.IsWishLock[0];
}
