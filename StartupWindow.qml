import QtQuick
import QtQuick.Dialogs

Rectangle {
    id: background
    x: 0
    y: 0
    width: 1364
    height: 768
    color: "#FFFFFF"
    signal coverClicked()
    Image {
        source: "images/封面.png"
        x: 0
        y: 0
        width: 1364
        height: 768
    }

    Text {
        id: text1
        x: 726
        y: 246
        width: 297
        height: 36
        color: "#343434"
        text: "当前游戏模式：" + (AppManager.currentConfig === 0 ? "快速测试" : "沉浸体验")
        font.pixelSize: 24
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        z: 100
        font.family: "FZYanSongS-M-GB"
    }
    ButtonDisplay {
        id: modeButton
        x: 1003
        y: 246
        width: 115
        height: 36
        normal_source: "images/切换模式.png"
        hover_source: "images/切换模式高亮.png"
        onClicked: AppManager.switchConfig()
    }
    ButtonDisplay {
        id: continueButton
        x: 711
        y: 288
        width: 200
        height: 60
        normal_source: AppManager.hasArchive ? "images/继续游戏.png" : "images/继续游戏灰.png"
        hover_source: AppManager.hasArchive ? "images/继续游戏高亮.png" : "images/继续游戏灰.png"
        onClicked: AppManager.hasArchive ? AppManager.startGame() : {}
    }
    ButtonDisplay {
        id: newButton
        x: 941
        y: 288
        width: 200
        height: 60
        normal_source: "images/开始游戏.png"
        hover_source: "images/开始游戏高亮.png"
        onClicked: {
            if(AppManager.hasArchive)
                newGameConfirm.open()
            else
                AppManager.newGame()
        }
    }
    MessageDialog {
        id: newGameConfirm
        text: "确认"
        informativeText: "将丢失现有游戏进度，是否继续？"
        buttons: MessageDialog.Ok | MessageDialog.Cancel
        onButtonClicked: function(button, role) {
            if(button === MessageDialog.Ok)
                AppManager.newGame()
        }
    }
}
