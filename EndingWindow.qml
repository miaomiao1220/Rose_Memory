import QtQuick
import QtMultimedia

Rectangle {
    id: background
    x: 0
    y: 0
    width: 1364
    height: 768
    color: "#FFFFFF"
    signal coverClicked()
    Video {
        source: "file://" + applicationDirPath + "/videos/ending.webm"
        x: 0
        y: 0
        width: 1364
        height: 768
        MouseArea {
            id: mouseArea
            x: 0
            y: 0
            width: 1364
            height: 768
            onClicked: {
                background.coverClicked()
            }
        }
        onVisibleChanged: play()
    }
}
