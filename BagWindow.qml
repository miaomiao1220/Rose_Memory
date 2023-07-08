import QtQuick

Rectangle {
    id: root
    x: 0
    y: 0
    width: 1364
    height: 768
    color: "#FFFFFF"
    signal backClicked()

    ButtonDisplay {
        id: backButton
        x: 1209
        y: 18
        width: 92
        normal_source: "images/菜单返回.png"
        hover_source: "images/菜单返回高亮.png"
        onClicked: root.backClicked()
    }

    MoneyUtil {}

    Image {
        id: image
        x: 618
        y: 100
        width: 120
        height: 65
        source: "images/bag仓库.png"
        fillMode: Image.PreserveAspectFit
    }

    PlantDisplay {
        id: plant00
        x: 166
        y: 227
        c_id: 0
    }

    PlantDisplay {
        id: plant01
        x: 313
        y: 227
        c_id: 1
    }

    PlantDisplay {
        id: plant02
        x: 458
        y: 227
        c_id: 2
    }

    PlantDisplay {
        id: plant03
        x: 592
        y: 227
        c_id: 3
    }

    PlantDisplay {
        id: plant04
        x: 725
        y: 227
        c_id: 4
    }

    PlantDisplay {
        id: plant05
        x: 856
        y: 227
        c_id: 5
    }

    PlantDisplay {
        id: plant06
        x: 981
        y: 227
        c_id: 6
    }

    PlantDisplay {
        id: plant07
        x: 1117
        y: 227
        c_id: 7
    }

    PlantDisplay {
        id: plant08
        x: 166
        y: 462
        c_id: 8
    }

    PlantDisplay {
        id: plant09
        x: 313
        y: 462
        c_id: 9
    }

    PlantDisplay {
        id: plant10
        x: 458
        y: 462
        c_id: 10
    }

    PlantDisplay {
        id: plant11
        x: 592
        y: 462
        c_id: 11
    }

    PlantDisplay {
        id: plant12
        x: 725
        y: 462
        c_id: 12
    }

    PlantDisplay {
        id: plant13
        x: 856
        y: 462
        c_id: 13
    }

    PlantDisplay {
        id: plant14
        x: 981
        y: 462
        c_id: 14
    }

    PlantDisplay {
        id: plant15
        x: 1117
        y: 462
        c_id: 15
    }
}
