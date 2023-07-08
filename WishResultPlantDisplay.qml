import QtQuick

Rectangle {
    id: root
    x: 0
    y: 0
    width: 100
    height: 120
    color: "#FFFFFF"
    property int c_id: 0
    visible: AppManager.wishResultVisible[c_id]
    Image {
        id: image
        source: Conf.wishResultImagePrefix +
                AppManager.wishResultPlantName[c_id] +
                Conf.wishResultImageSuffix
        fillMode: Image.PreserveAspectFit
        width: 100
        height: 100
    }
    Text {
        id: name
        text: AppManager.wishResultPlantName[c_id]
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.family: "FZYanSongS-B-GB"
        font.pointSize: 16
        width: 100
        height: 20
        x: 0
        y: 100
    }
}
