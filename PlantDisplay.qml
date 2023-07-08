import QtQuick

Item {
    width: 100
    height: 200

    property int c_id: 0
    property bool show_info: true
    visible: AppManager.bagVisible[c_id]

    Image {
        id: image
        x: 0
        y: 0
        width: 100
        height: 100
        source: Conf.bagTitlePrefix + AppManager.bagPlantName[c_id] + Conf.bagTitleSuffix
        fillMode: Image.PreserveAspectFit
    }

    Image {
        id: info
        visible: show_info
        x: 0
        y: 100
        width: 100
        height: 100
        source: Conf.bagLabelPrefix + AppManager.bagPlantName[c_id] + Conf.bagLabelSuffix
        fillMode: Image.PreserveAspectFit
    }

    Text {
        id: seedCount
        visible: show_info
        x: 41
        y: 142
        width: 52
        height: 22
        text: AppManager.seedCount[c_id]
        font.pixelSize: 16
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.family: "Tahoma"
    }

    Text {
        id: gainCount
        visible: show_info
        x: 41
        y: 166
        width: 52
        height: 22
        text: AppManager.gainCount[c_id]
        font.pixelSize: 16
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.family: "Tahoma"
    }

}
