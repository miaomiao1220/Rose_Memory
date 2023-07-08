import QtQuick

Rectangle {
    id: root
    x: 0
    y: 0
    width: 1364
    height: 768
    color: "#FFFFFF"

    signal bagClicked()
    signal storeClicked()
    signal wishClicked()

    ButtonDisplay {
        id: bag
        x: 1209
        y: 18
        width: 92
        normal_source: "images/菜单仓库.png"
        hover_source: "images/菜单仓库高亮.png"
        onClicked: root.bagClicked()
    }

    ButtonDisplay {
        id: store
        x: 1025
        y: 18
        width: 92
        visible: AppManager.showStoreButton
        normal_source: "images/菜单商店.png"
        hover_source: "images/菜单商店高亮.png"
        onClicked: root.storeClicked()
    }

    ButtonDisplay {
        id: wish
        x: 1117
        y: 18
        width: 92
        visible: AppManager.showWishButton
        normal_source: "images/菜单许愿.png"
        hover_source: "images/菜单许愿高亮.png"
        onClicked: root.wishClicked()
    }


    FieldDisplay {
        id: field0
        x: 250
        y: 150
        c_id: 0
        width: 100
        height: 100
    }

    FieldDisplay {
        id: field1
        x: 187.5
        y: 275
        c_id: 1
        width: 100
        height: 100
    }

    FieldDisplay {
        id: field2
        x: 125
        y: 400
        c_id: 2
        width: 100
        height: 100
    }

    FieldDisplay {
        id: field3
        x: 62.5
        y: 525
        c_id: 3
        width: 100
        height: 100
    }


    MoneyUtil {
    }

    FieldDisplay {
        id: field4
        x: 485
        y: 150
        width: 100
        height: 100
        c_id: 4
    }

    FieldDisplay {
        id: field5
        x: 422
        y: 275
        width: 100
        height: 100
        c_id: 5
    }

    FieldDisplay {
        id: field6
        x: 360
        y: 400
        width: 100
        height: 100
        c_id: 6
    }

    FieldDisplay {
        id: field7
        x: 297
        y: 525
        width: 100
        height: 100
        c_id: 7
    }

    Image {
        id: split
        x: 175
        y: 110
        width: 295
        source: "images/split.png"
        fillMode: Image.PreserveAspectFit
    }

    Image {
        id: split1
        x: 410
        y: 110
        width: 295
        source: "images/split.png"
        fillMode: Image.PreserveAspectFit
    }

    Image {
        id: split2
        x: 721
        y: 110
        width: 295
        source: "images/split.png"
        fillMode: Image.PreserveAspectFit
    }

    FieldDisplay {
        id: field8
        x: 689
        y: 150
        width: 200
        height: 200
        c_id: 8
    }

    FieldDisplay {
        id: field9
        x: 552
        y: 425
        width: 200
        height: 200
        c_id: 9
    }

    FieldDisplay {
        id: field10
        x: 1004
        y: 150
        width: 200
        height: 200
        c_id: 10
    }

    FieldDisplay {
        id: field11
        x: 869
        y: 425
        width: 200
        height: 200
        c_id: 11
    }

    ToolBoxDisplay {
        x: 1215
        y: 234
        scale: 0.7

    }

    FieldStatusDisplay {
        x: 1063
        y: 643

    }
}
