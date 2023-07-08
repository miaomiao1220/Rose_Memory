import QtQuick

Rectangle {
    id: root
    x: 0
    y: 0
    width: 1364
    height: 768
    color: "#d5212121"
    border.width: 0
    signal backClicked()
    signal okClicked()
    Image {
        id: image
        x: 122
        y: 54
        width: 1127
        height: 627
        source: "images/选择种子画板 1.png"
        fillMode: Image.Stretch
    }
    Text {
        id: text1
        x: 545
        y: 125
        width: 244
        height: 54
        text: qsTr("选择种子")
        font.pixelSize: 32
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.family: "FZYanSongS-M-GB"
    }

    MouseArea {
        anchors.fill: parent
    }

    ButtonDisplay {
        id: backButton
        x: 545
        y: 560
        width: 92
        height: 47
        normal_source: "images/菜单返回.png"
        hover_source: "images/菜单返回高亮.png"
        onClicked: root.backClicked()
    }

    ButtonDisplay {
        id: okButton
        x: 709
        y: 560
        width: 92
        height: 47
        normal_source: "images/菜单确认.png"
        hover_source: "images/菜单确认高亮.png"
        onClicked: root.okClicked()
    }

    SeedSelectorPlantDisplay {
        id: plant0
        x: 250
        y: 224
        c_id: 0
    }

    SeedSelectorPlantDisplay {
        id: plant1
        x: 360
        y: 224
        c_id: 1
    }

    SeedSelectorPlantDisplay {
        id: plant2
        x: 470
        y: 224
        c_id: 2
    }

    SeedSelectorPlantDisplay {
        id: plant3
        x: 580
        y: 224
        c_id: 3
    }

    SeedSelectorPlantDisplay {
        id: plant4
        x: 690
        y: 224
        c_id: 4
    }

    SeedSelectorPlantDisplay {
        id: plant5
        x: 800
        y: 224
        c_id: 5
    }

    SeedSelectorPlantDisplay {
        id: plant6
        x: 910
        y: 224
        c_id: 6
    }

    SeedSelectorPlantDisplay {
        id: plant7
        x: 1020
        y: 224
        c_id: 7
    }

    SeedSelectorPlantDisplay {
        id: plant8
        x: 250
        y: 388
        c_id: 8
    }

    SeedSelectorPlantDisplay {
        id: plant9
        x: 360
        y: 388
        c_id: 9
    }

    SeedSelectorPlantDisplay {
        id: plant10
        x: 470
        y: 388
        c_id: 10
    }

    SeedSelectorPlantDisplay {
        id: plant11
        x: 580
        y: 388
        c_id: 11
    }

    SeedSelectorPlantDisplay {
        id: plant12
        x: 690
        y: 388
        c_id: 12
    }

    SeedSelectorPlantDisplay {
        id: plant13
        x: 800
        y: 388
        c_id: 13
    }

    SeedSelectorPlantDisplay {
        id: plant14
        x: 910
        y: 388
        c_id: 14
    }

    SeedSelectorPlantDisplay {
        id: plant15
        x: 1020
        y: 388
        c_id: 15
    }
}
