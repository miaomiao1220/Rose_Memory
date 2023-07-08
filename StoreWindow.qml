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

    Image {
        id: image
        x: 618
        y: 100
        width: 120
        height: 65
        source: "images/store商店.png"
        fillMode: Image.PreserveAspectFit
    }

    ButtonDisplay {
        id: item0
        x: 88
        y: 208
        width: 600
        height: 240
        normal_source: AppManager.storeStatus[0] === 0 ?
                           "images/商店南瓜种子.png":
                           AppManager.storeStatus[0] === 1 ?
                               "images/商店南瓜种子缺材料.png":
                               "images/商店南瓜种子未解锁.png"
        hover_source: AppManager.storeStatus[0] === 0 ?
                          "images/商店南瓜种子高亮.png":
                          AppManager.storeStatus[0] === 1 ?
                              "images/商店南瓜种子缺材料.png":
                              "images/商店南瓜种子未解锁.png"
        onClicked: AppManager.storeClicked(0)
    }


    ButtonDisplay {
        id: item1
        x: 696
        y: 208
        width: 600
        height: 240
        normal_source: AppManager.storeStatus[1] === 0 ?
                           "images/商店石榴种子.png":
                           AppManager.storeStatus[1] === 1 ?
                               "images/商店石榴种子缺材料.png":
                               "images/商店石榴种子未解锁.png"
        hover_source: AppManager.storeStatus[1] === 0 ?
                          "images/商店石榴种子高亮.png":
                          AppManager.storeStatus[1] === 1 ?
                              "images/商店石榴种子缺材料.png":
                              "images/商店石榴种子未解锁.png"
        onClicked: AppManager.storeClicked(1)
    }

    ButtonDisplay {
        id: item2
        x: 88
        y: 472
        width: 600
        height: 240
        normal_source: AppManager.storeStatus[2] === 0 ?
                           "images/商店葡萄风信子种子.png":
                           AppManager.storeStatus[2] === 1 ?
                               "images/商店葡萄风信子种子缺材料.png":
                               "images/商店葡萄风信子种子未解锁.png"
        hover_source: AppManager.storeStatus[2] === 0 ?
                          "images/商店葡萄风信子种子高亮.png":
                          AppManager.storeStatus[2] === 1 ?
                              "images/商店葡萄风信子种子缺材料.png":
                              "images/商店葡萄风信子种子未解锁.png"
        onClicked: AppManager.storeClicked(2)
    }

    ButtonDisplay {
        id: item3
        x: 696
        y: 472
        width: 600
        height: 240
        normal_source: AppManager.storeStatus[3] === 0 ?
                           "images/商店金蔷薇种子.png":
                           AppManager.storeStatus[3] === 1 ?
                               "images/商店金蔷薇种子缺材料.png":
                               "images/商店金蔷薇种子未解锁.png"
        hover_source: AppManager.storeStatus[3] === 0 ?
                          "images/商店金蔷薇种子高亮.png":
                          AppManager.storeStatus[3] === 1 ?
                              "images/商店金蔷薇种子缺材料.png":
                              "images/商店金蔷薇种子未解锁.png"
        onClicked: AppManager.storeClicked(3)
    }

    MoneyUtil {
    }
}
