pragma Singleton
import QtQuick

Item {
    property string fieldImagePrefix: "images/rose"
    property string fieldImageSuffix: ".png"
    property string bagTitlePrefix: "images/rose"
    property string bagTitleSuffix: ".png"
    property string bagLabelPrefix: "images/bag"
    property string bagLabelSuffix: ".png"
    property string emptyFieldImg: "images/空地.png"
    property string seedSelectorImagePrefix: "images/rose"
    property string seedSelectorImageSuffix: ".png"
    property string wishResultImagePrefix: "images/rose"
    property string wishResultImageSuffix: ".png"
    property string storyImagePrefix: "images/story"
    property string storyImageSuffix: ".png"
    property string enFontPath: "fonts/Futura-Medium-01.ttf"
    property string cnFontPath: "fonts/FZYanSJW_Zhun.ttf"
    property var wishDescription: [
        qsTr("可通过本许愿获得6种蔬菜之一，其中萝卜种子、白菜种子的获得概率各为30%，茄子种子、番茄种子的获得概率各为15%，辣椒种子、黄瓜种子的获得概率各为5%。"),
        qsTr("可通过本许愿获得6种蔬菜之一或4种水果之一，其中有40%的概率获得蔬菜种子，此时各种蔬菜的获得概率与许愿一相同，另各有20%的概率获得橘子种子、蓝莓种子，各有10%的概率获得草莓种子、香蕉种子。"),
        qsTr("可通过本许愿获得6种蔬菜之一、4种水果之一或2种花朵之一，其中有40%的概率获得蔬菜种子，另有30%的概率获得水果种子，在此基础上各种子概率和许愿一、许愿二相同，另有20%的概率获得茉莉种子、有10%的概率获得芝樱种子。")
    ]
}
