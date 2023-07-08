import QtQuick

Rectangle {
    id: root
    x: 0
    y: 0
    width: 100
    height: 120
    color: "#FFFFFF"
    property int c_id: 0
    property bool height_match: AppManager.seedSelectorHeightMatch[c_id]
    visible: AppManager.seedSelectorVisible[c_id]
    Image {
        id: image
        source: Conf.seedSelectorImagePrefix +
                AppManager.seedSelectorPlantName[c_id] +
                Conf.seedSelectorImageSuffix
        fillMode: Image.PreserveAspectFit
        width: 100
        height: 100
    }
    Text {
        id: name
        text: AppManager.seedSelectorPlantName[c_id]
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.family: "FZYanSongS-B-GB"
        font.pointSize: 16
        width: 100
        height: 20
        x: 0
        y: 100
    }
    Image {
        id: selection
        source: "images/选中状态.png"
        visible: AppManager.currentSeed === c_id ? true : false
        x: 71
        y: 2
        width: 25
        height: 25
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if (height_match)
                AppManager.currentSeed = c_id
        }
    }

    Rectangle {
        id: rectangle
        x: 0
        y: 39
        width: 100
        height: 23
        color: "#62000000"
        visible: !root.height_match

        Text {
            id: text1
            x: 14
            y: 4
            width: 72
            height: 18
            text: "高度不匹配"
            font.pixelSize: 14
            font.family: "FZYanSongS-M-GB"
            color: "#FFFFFFFF"
        }
    }
}
