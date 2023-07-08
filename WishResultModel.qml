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
        text: qsTr("获得种子")
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
        x: 630
        y: 549
        width: 92
        height: 47
        normal_source: "images/菜单返回.png"
        hover_source: "images/菜单返回高亮.png"
        onClicked: root.backClicked()
    }

    WishResultPlantDisplay {
        id: plant0
        x: 403
        y: 234
        c_id: 0
    }

    WishResultPlantDisplay {
        id: plant1
        x: 513
        y: 234
        c_id: 1
    }

    WishResultPlantDisplay {
        id: plant2
        x: 623
        y: 234
        c_id: 2
    }

    WishResultPlantDisplay {
        id: plant3
        x: 733
        y: 234
        c_id: 3
    }

    WishResultPlantDisplay {
        id: plant4
        x: 843
        y: 234
        c_id: 4
    }

    WishResultPlantDisplay {
        id: plant5
        x: 403
        y: 384
        c_id: 5
    }

    WishResultPlantDisplay {
        id: plant6
        x: 513
        y: 384
        c_id: 6
    }

    WishResultPlantDisplay {
        id: plant7
        x: 623
        y: 384
        c_id: 7
    }

    WishResultPlantDisplay {
        id: plant8
        x: 733
        y: 384
        c_id: 8
    }

    WishResultPlantDisplay {
        id: plant9
        x: 843
        y: 384
        c_id: 9
    }

    WishResultPlantDisplay {
        id: plantOne
        x: 622
        y: 296
        c_id: 10
    }
}
