import QtQuick

Item {
    width: 1364
    height: 768

    Image {
        id: image
        x: 24
        y: 21
        width: 36
        height: 36
        source: "images/金币.png"
        fillMode: Image.PreserveAspectFit
    }

    Text {
        id: text1
        x: 70
        y: 18
        width: 284
        height: 43
        text: AppManager.money
        font.pixelSize: 28
        verticalAlignment: Text.AlignVCenter
        font.family: "Futura"
    }

    FontLoader {
        id: enFont
        source: Conf.enFontPath
    }
}
