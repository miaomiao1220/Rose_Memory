import QtQuick

Rectangle {
    id: root

    property int current_selected: 0

    signal backClicked

    color: "#FFFFFF"
    height: 768
    width: 1364
    x: 0
    y: 0

    onVisibleChanged: {
        current_selected = 0;
    }

    ButtonDisplay {
        id: backButton

        hover_source: "images/菜单返回高亮.png"
        normal_source: "images/菜单返回.png"
        width: 92
        x: 1209
        y: 18

        onClicked: root.backClicked()
    }
    Image {
        id: image

        fillMode: Image.PreserveAspectFit
        height: 65
        source: "images/wish许愿.png"
        width: 120
        x: 618
        y: 100
    }
    MoneyUtil {
        id: moneyUtil

    }
    Image {
        id: image1

        fillMode: Image.PreserveAspectFit
        height: 461
        source: "images/wish女孩.png"
        width: 461
        x: -23
        y: 213
    }
    ButtonDisplay {
        id: wish1

        property int status: AppManager.wishStatus[0]

        always_on: current_selected === 0 ? true : false
        height: 96
        hover_source: status === 0 ? "images/许愿一.png" : "images/许愿一灰.png"
        normal_source: "images/许愿一灰.png"
        width: 286
        x: 280
        y: 248

        onClicked: {
            if (status === 0)
                current_selected = 0;
            else
                AppManager.popupMessage = "未解锁";
        }
    }
    ButtonDisplay {
        id: wish2

        property int status: AppManager.wishStatus[1]

        always_on: current_selected === 1 ? true : false
        height: 96
        hover_source: status === 0 ? "images/许愿二.png" : "images/许愿二灰.png"
        normal_source: "images/许愿二灰.png"
        width: 286
        x: 362
        y: 384

        onClicked: {
            if (status === 0)
                current_selected = 1;
            else
                AppManager.popupMessage = "未解锁";
        }
    }
    ButtonDisplay {
        id: wish3

        property int status: AppManager.wishStatus[2]

        always_on: current_selected == 2 ? true : false
        height: 96
        hover_source: status === 0 ? "images/许愿三.png" : "images/许愿三灰.png"
        normal_source: "images/许愿三灰.png"
        width: 286
        x: 337
        y: 542

        onClicked: {
            if (status === 0)
                current_selected = 2;
            else
                AppManager.popupMessage = "未解锁";
        }
    }
    Image {
        id: image5

        fillMode: Image.Stretch
        height: 266
        source: "images/story对话框.png"
        width: 578
        x: 715
        y: 235
    }
    Text {
        id: text1

        font.family: "FZYanSongS-M-GB"
        font.pixelSize: 24
        height: 40
        horizontalAlignment: Text.AlignHCenter
        text: qsTr("消耗")
        verticalAlignment: Text.AlignVCenter
        width: 55
        x: 791
        y: 542
    }
    Image {
        id: coin1

        fillMode: Image.PreserveAspectFit
        height: 36
        source: "images/金币.png"
        width: 36
        x: 848
        y: 544
    }
    Text {
        id: cost1

        font.family: "Futura"
        font.pixelSize: 28
        height: 43
        text: AppManager.wishPrice1[current_selected]
        verticalAlignment: Text.AlignVCenter
        width: 284
        x: 896
        y: 541
    }
    Text {
        id: text2

        font.family: "FZYanSongS-M-GB"
        font.pixelSize: 24
        height: 40
        horizontalAlignment: Text.AlignHCenter
        text: qsTr("消耗")
        verticalAlignment: Text.AlignVCenter
        width: 55
        x: 1023
        y: 542
    }
    Image {
        id: coin2

        fillMode: Image.PreserveAspectFit
        height: 36
        source: "images/金币.png"
        width: 36
        x: 1080
        y: 544
    }
    Text {
        id: cost2

        font.family: "Futura"
        font.pixelSize: 28
        height: 43
        text: AppManager.wishPrice10[current_selected]
        verticalAlignment: Text.AlignVCenter
        width: 284
        x: 1128
        y: 541
    }
    Text {
        id: description

        font.family: "FZYanSongS-M-GB"
        font.pixelSize: 24
        height: 200
        text: Conf.wishDescription[current_selected]
        verticalAlignment: Text.AlignVCenter
        width: 525
        wrapMode: Text.WordWrap
        x: 745
        y: 268
    }
    ButtonDisplay {
        id: goSingleWish

        height: 70
        hover_source: "images/许愿1次.png"
        normal_source: "images/许愿1次.png"
        width: 210
        x: 753
        y: 582

        onClicked: {
            AppManager.goSingleWish(root.current_selected);
        }
    }
    ButtonDisplay {
        id: go10Wish

        height: 70
        hover_source: "images/许愿10次.png"
        normal_source: "images/许愿10次.png"
        width: 210
        x: 995
        y: 582

        onClicked: {
            AppManager.go10Wish(root.current_selected);
        }
    }
}
