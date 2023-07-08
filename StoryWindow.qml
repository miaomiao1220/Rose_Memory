import QtQuick

Rectangle {
    id: root
    x: 0
    y: 0
    width: 1364
    height: 768
    color: "#FFFFFF"

    ButtonDisplay {
        id: continueButton
        x: 1205
        y: 704
        width: 92
        normal_source: "images/菜单继续.png"
        hover_source: "images/菜单继续高亮.png"
        onClicked: AppManager.storyContinue()
    }

    Image {
        id: image0
        x: 27
        y: 354
        width: 300
        height: 400
        source: Conf.storyImagePrefix + AppManager.storyImage[0] + Conf.storyImageSuffix
    }

    Image {
        id: image1
        x: 1017
        y: 18
        width: 300
        height: 400
        source: Conf.storyImagePrefix + AppManager.storyImage[1] + Conf.storyImageSuffix
        mirror: true
    }

    Image {
        id: box0
        x: 326
        y: 467
        width: 930
        height: 200
        visible: AppManager.storyText[0] !== "" ? true : false
        source: "images/story对话框.png"
    }

    Image {
        id: box1
        x: 83
        y: 127
        width: 930
        height: 200
        visible: AppManager.storyText[1] !== "" ? true : false
        source: "images/story对话框.png"
    }

    Text {
        id: name0
        x: 381
        y: 496
        width: 263
        height: 46
        font.pointSize: 32
        font.family: "FZYanSongS-B-GB"
        text: AppManager.storyName[0]
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        id: name1
        x: 726
        y: 155
        width: 219
        height: 46
        font.pointSize: 32
        font.family: "FZYanSongS-B-GB"
        text: AppManager.storyName[1]
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        id: text0
        x: 381
        y: 558
        width: 824
        height: 89
        color: AppManager.storyActivePanel===0 ? "#000000" : "#888888"
        font.pointSize: 28
        font.family: "FZYanSongS-M-GB"
        text: AppManager.storyText[0]
        verticalAlignment: Text.AlignVCenter
        wrapMode: Text.WordWrap
    }

    Text {
        id: text1
        x: 131
        y: 204
        width: 824
        height: 89
        color: AppManager.storyActivePanel===1 ? "#000000" : "#888888"
        font.pointSize: 28
        font.family: "FZYanSongS-M-GB"
        text: AppManager.storyText[1]
        verticalAlignment: Text.AlignVCenter
        wrapMode: Text.WordWrap
    }
}
