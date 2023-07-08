pragma Singleton
import QtQuick

Item {
    id: root
    property int money: 2000
    property int fieldStatusDisplayId: -1
    property int currentSeed: -1
    property string currentTool: "none"
    property int storyActivePanel: 1
    property string currentScene: "startup"
    property string currentModel: "wishResult"
    property var bagVisible: [
        true, true, true, true, true, true, true, true,
        true, true, true, true, true, true, true, true
    ]
    property var bagPlantName: [
        "萝卜","香蕉","萝卜","萝卜","萝卜","萝卜","萝卜","萝卜",
        "萝卜","萝卜","萝卜","茄子","萝卜","萝卜","芝樱","萝卜"
    ]
    property var seedCount: [
        25, 14, 15, 16, 13, 15, 16, 16,
        16, 14, 16, 17,11, 3, 15, 6
    ]
    property var gainCount: [
        1, 2, 3, 4, 5, 6, 7, 7,
        2, 2, 3, 4, 5, 6, 7, 7
    ]
    property var seedSelectorVisible: [
        true, true, true, true, true, true, true, true,
        true, true, true, true, true, true, true, true
    ]
    property var seedSelectorPlantName: [
        "萝卜","香蕉","萝卜","萝卜","萝卜","萝卜","萝卜","萝卜",
        "萝卜","萝卜","萝卜","茄子","萝卜","萝卜","芝樱","萝卜"
    ]
    property var fieldHeight: [
        "低","低","低","低","低","低","低","低",
        "高","高","高","高"
    ]
    property var fieldPlantName: [
        "无作物","萝卜","萝卜","萝卜","无作物","萝卜","萝卜","萝卜",
        "香蕉","香蕉","香蕉","香蕉"
    ]
    property var fieldPlantGrowStatus: [
        "种子","收获","成长","成长","成长","成长","成长","发芽",
        "收获","成长","种子","成长"
    ]
    property var fieldPlantWaterStatus: [
        "干旱","干旱","干旱","正常","干旱","干旱","干旱","干旱",
        "正常","干旱","干旱","干旱"
    ]
    property var fieldPlantTTN: [
        1, 3, 2, 1, 4, 5, 1, 3, 1, 1, 3, 1
    ]
    property var wishResultVisible: [
        true, true, true, true, true, true, true, true, true, true, false
    ]
    property var wishResultPlantName: [
        "萝卜","萝卜","萝卜","萝卜","萝卜","萝卜","茄子","萝卜","萝卜","萝卜","萝卜"
    ]
    signal update()
    signal fieldClicked(int f_id)
    signal goSingleWish()
    signal go10Wish()
    signal seedConfirm()
    onUpdate: {
        money += 1
    }
    onFieldClicked: {
        console.log(f_id)
    }
    onGoSingleWish: {
        console.log("single wish")
    }
    onGo10Wish: {
        console.log("10 wish")
    }
    onSeedConfirm: {
        console.log("seed confirm")
    }
}
