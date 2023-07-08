import QtQuick

Image {
    id: root
    property string normal_source
    property string hover_source
    property bool always_on
    signal clicked()
    source: normal_source
    fillMode: Image.PreserveAspectFit
    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        onClicked: {
            root.clicked()
        }
        onEntered: {
            root.source = hover_source
        }
        onExited: {
            if(!always_on) {
                root.source = normal_source
            }
        }
    }
    onVisibleChanged: {
        if(always_on) {
            root.source = hover_source
        } else {
            root.source = normal_source
        }
    }
    onAlways_onChanged: {
        if(always_on) {
            root.source = hover_source
        } else {
            root.source = normal_source
        }
    }
    onNormal_sourceChanged: {
        if(always_on) {
            root.source = hover_source
        } else {
            root.source = normal_source
        }
    }
    onHover_sourceChanged: {
        if(always_on) {
            root.source = hover_source
        } else {
            root.source = normal_source
        }
    }
}
