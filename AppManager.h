#ifndef APPMANAGER_H
#define APPMANAGER_H
#include <QObject>
#include <QVariant>
#include <QList>
#include <vector>
#include <Player.h>
#include <QCursor>
#include <QGuiApplication>
#include <QDir>
#include <QStandardPaths>
class AppManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int money READ money NOTIFY moneyChanged)

    Q_PROPERTY(int fieldStatusDisplayId READ fieldStatusDisplayId
                   WRITE setFieldStatusDisplayId NOTIFY fieldStatusDisplayIdChanged)

    Q_PROPERTY(QString currentTool READ currentTool
                   WRITE setCurrentTool NOTIFY currentToolChanged)

    Q_PROPERTY(int storyActivePanel READ storyActivePanel NOTIFY storyActivePanelChanged)

    Q_PROPERTY(QString currentScene READ currentScene
                   WRITE setCurrentScene NOTIFY currentSceneChanged)

    Q_PROPERTY(QString currentModel READ currentModel
                   WRITE setCurrentModel NOTIFY currentModelChanged)

    Q_PROPERTY(int currentSeed READ currentSeed
                   WRITE setCurrentSeed NOTIFY currentSeedChanged)

    Q_PROPERTY(QList<QVariant> bagVisible READ bagVisible NOTIFY bagVisibleChanged)

    Q_PROPERTY(QStringList bagPlantName READ bagPlantName NOTIFY bagPlantNameChanged)

    Q_PROPERTY(QList<QVariant> seedCount READ seedCount NOTIFY seedCountChanged)

    Q_PROPERTY(QList<QVariant> gainCount READ gainCount NOTIFY gainCountChanged)

    Q_PROPERTY(QList<QVariant> seedSelectorVisible READ seedSelectorVisible NOTIFY seedSelectorVisibleChanged)

    Q_PROPERTY(QList<QVariant> seedSelectorHeightMatch READ seedSelectorHeightMatch NOTIFY seedSelectorHeightMatchChanged)

    Q_PROPERTY(QStringList seedSelectorPlantName READ seedSelectorPlantName NOTIFY seedSelectorPlantNameChanged)

    Q_PROPERTY(QStringList fieldHeight READ fieldHeight NOTIFY fieldHeightChanged)

    Q_PROPERTY(QStringList fieldPlantName READ fieldPlantName NOTIFY fieldPlantNameChanged)

    Q_PROPERTY(QStringList fieldPlantGrowStatus READ fieldPlantGrowStatus NOTIFY fieldPlantGrowStatusChanged)

    Q_PROPERTY(QStringList fieldPlantWaterStatus READ fieldPlantWaterStatus NOTIFY fieldPlantWaterStatusChanged)

    Q_PROPERTY(QList<QVariant> fieldPlantTTN READ fieldPlantTTN NOTIFY fieldPlantTTNChanged)

    Q_PROPERTY(QList<QVariant> wishResultVisible READ wishResultVisible NOTIFY wishResultVisibleChanged)

    Q_PROPERTY(QStringList wishResultPlantName READ wishResultPlantName NOTIFY wishResultPlantNameChanged)

    Q_PROPERTY(QString popupMessage READ popupMessage WRITE setPopupMessage NOTIFY popupMessageChanged)

    Q_PROPERTY(QList<QVariant> storeStatus READ storeStatus NOTIFY storeStatusChanged)

    Q_PROPERTY(QList<QVariant> wishStatus READ wishStatus NOTIFY wishStatusChanged)

    Q_PROPERTY(int currentField READ currentField NOTIFY currentFieldChanged)

    Q_PROPERTY(QList<QVariant> wishPrice1 READ wishPrice1 NOTIFY wishPrice1Changed)

    Q_PROPERTY(QList<QVariant> wishPrice10 READ wishPrice10 NOTIFY wishPrice10Changed)

    Q_PROPERTY(QStringList storyImage READ storyImage NOTIFY storyImageChanged)

    Q_PROPERTY(QStringList storyName READ storyName NOTIFY storyNameChanged)

    Q_PROPERTY(QStringList storyText READ storyText NOTIFY storyTextChanged)

    Q_PROPERTY(bool hasArchive READ hasArchive NOTIFY hasArchiveChanged)

    Q_PROPERTY(int currentConfig READ currentConfig NOTIFY currentConfigChanged)

    Q_PROPERTY(bool showStoreButton READ showStoreButton NOTIFY showStoreButtonChanged)

    Q_PROPERTY(bool showWishButton READ showWishButton NOTIFY showWishButtonChanged)

public:
    explicit AppManager(QObject *parent = nullptr);
    int money() const;
    void setMoney(int x);

    int fieldStatusDisplayId() const;
    void setFieldStatusDisplayId(int x);

    QString currentTool() const;
    void setCurrentTool(QString x);

    int storyActivePanel() const;
    void setStoryActivePanel(int x);

    QString currentScene() const;
    void setCurrentScene(QString x);

    QString currentModel() const;
    void setCurrentModel(QString x);

    int currentSeed() const;
    void setCurrentSeed(int x);

    QList<QVariant> bagVisible();
    void setBagVisible(QList<QVariant> x);

    QStringList bagPlantName() const;
    void setBagPlantName(QStringList x);

    QList<QVariant> seedCount() const;
    void setSeedCount(QList<QVariant> x);

    QList<QVariant> gainCount() const;
    void setGainCount(QList<QVariant> x);

    QList<QVariant> seedSelectorVisible() const;
    void setSeedSelectorVisible(QList<QVariant> x);

    QList<QVariant> seedSelectorHeightMatch() const;
    void setSeedSelectorHeightMatch(QList<QVariant> x);

    QStringList fieldHeight();
    void setFieldHeight(QStringList x);

    QStringList fieldPlantName() const;
    void setFieldPlantName(QStringList x);

    QStringList fieldPlantGrowStatus() const;
    void setFieldPlantGrowStatus(QStringList x);

    QStringList fieldPlantWaterStatus() const;
    void setFieldPlantWaterStatus(QStringList x);

    QList<QVariant> fieldPlantTTN() const;
    void setFieldPlantTTN(QList<QVariant> x);

    QList<QVariant> wishResultVisible() const;
    void setWishResultVisible(QList<QVariant> x);

    QStringList wishResultPlantName() const;
    void setWishResultPlantName(QStringList x);

    QStringList seedSelectorPlantName() const;
    void setSeedSelectorPlantName(QStringList x);

    QString popupMessage() const;
    void setPopupMessage(QString x);

    QList<QVariant> storeStatus() const;
    void setStoreStatus(QList<QVariant> x);

    QList<QVariant> wishStatus() const;
    void setWishStatus(QList<QVariant> x);

    int currentField() const;
    void setCurrentField(int x);

    QList<QVariant> wishPrice1() const;
    void setWishPrice1(QList<QVariant> x);

    QList<QVariant> wishPrice10() const;
    void setWishPrice10(QList<QVariant> x);

    QStringList storyImage() const;
    void setStoryImage(QStringList x);

    QStringList storyName() const;
    void setStoryName(QStringList x);

    QStringList storyText() const;
    void setStoryText(QStringList x);

    bool hasArchive();

    int currentConfig();

    bool showWishButton();

    bool showStoreButton();

    Q_INVOKABLE void update();
    Q_INVOKABLE void fieldClicked(int f_id);
    Q_INVOKABLE void goSingleWish(int w_id);
    Q_INVOKABLE void go10Wish(int w_id);
    Q_INVOKABLE void seedConfirm();
    Q_INVOKABLE void storeClicked(int s_id);
    Q_INVOKABLE void storyContinue();
    Q_INVOKABLE void startGame();
    Q_INVOKABLE void soundEffect(QString x);
    Q_INVOKABLE void newGame();
    Q_INVOKABLE void switchConfig();

    void storyNextStep();
    int goWish(std::map<int, int> prob);
    void playStory(QList<QList<QString>> story);
    QString getArchiveFile();

signals:
    void moneyChanged();
    void fieldStatusDisplayIdChanged();
    void currentToolChanged();
    void storyActivePanelChanged();
    void currentModelChanged();
    void currentSeedChanged();
    void currentSceneChanged();
    void bagVisibleChanged();
    void bagPlantNameChanged();
    void seedCountChanged();
    void gainCountChanged();
    void seedSelectorVisibleChanged();
    void seedSelectorHeightMatchChanged();
    void seedSelectorPlantNameChanged();
    void fieldHeightChanged();
    void fieldPlantNameChanged();
    void fieldPlantGrowStatusChanged();
    void fieldPlantWaterStatusChanged();
    void fieldPlantTTNChanged();
    void wishResultVisibleChanged();
    void wishResultPlantNameChanged();
    void popupMessageChanged();
    void storeStatusChanged();
    void wishStatusChanged();
    void currentFieldChanged();
    void wishPrice1Changed();
    void wishPrice10Changed();
    void storyImageChanged();
    void storyNameChanged();
    void storyTextChanged();
    void hasArchiveChanged();
    void currentConfigChanged();
    void showWishButtonChanged();
    void showStoreButtonChanged();
private:
    int m_money{};
    int m_fieldStatusDisplayId{};
    QString m_currentTool;
    int m_storyActivePanel{};
    QString m_currentScene;
    QString m_currentModel;
    int m_currentSeed{};
    QList<QVariant> m_bagVisible;
    QStringList m_bagPlantName;
    QList<QVariant> m_seedCount;
    QList<QVariant> m_gainCount;
    QList<QVariant> m_seedSelectorVisible;
    QList<QVariant> m_seedSelectorHeightMatch;
    QStringList m_seedSelectorPlantName;
    QStringList m_fieldHeight;
    QStringList m_fieldPlantName;
    QStringList m_fieldPlantGrowStatus;
    QStringList m_fieldPlantWaterStatus;
    QList<QVariant> m_fieldPlantTTN;
    QList<QVariant> m_wishResultVisible;
    QStringList m_wishResultPlantName;
    QString m_popupMessage;
    QList<QVariant> m_storeStatus;
    QList<QVariant> m_wishStatus;
    int m_currentField;
    QList<QVariant> m_wishPrice1;
    QList<QVariant> m_wishPrice10;
    QStringList m_storyName;
    QStringList m_storyText;
    QStringList m_storyImage;
    int archive_id;
    bool m_hasArchive;
    int m_currentConfig;


    Player player;
    QList<QList<QString>> _story;
    int story_progress;
    QCursor cursor[4];
    QGuiApplication* app;
};
#endif // APPMANAGER_H
