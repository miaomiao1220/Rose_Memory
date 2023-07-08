import QtQuick

Item {
    id: root
    width: 200
    height: 200

    property int c_id: -1

    Image {
        id: image
        x: 0
        y: 0
        width: root.width
        height: root.height
        //        source: "images/rose萝卜.png"
        property string img_prefix: Conf.fieldImagePrefix
        property string img_name: ((AppManager.fieldPlantGrowStatus[root.c_id] !== "收获") ?
                                       ((root.c_id < 8 ? "小" : "") + AppManager.fieldPlantGrowStatus[root.c_id]):
                                       AppManager.fieldPlantName[root.c_id])
        property string img_suffix: (AppManager.fieldPlantWaterStatus[root.c_id] === "干旱" &&
                                     AppManager.fieldPlantGrowStatus[root.c_id] !== "收获" ? "缺水" : "") +
                                    Conf.fieldImageSuffix
        source: AppManager.fieldPlantName[root.c_id] !== "无作物" ? img_prefix + img_name + img_suffix : Conf.emptyFieldImg
        fillMode: Image.PreserveAspectFit
        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                AppManager.fieldStatusDisplayId = root.c_id
            }
            onExited: {
                AppManager.fieldStatusDisplayId = -1
            }
            onClicked: {
                AppManager.fieldClicked(c_id)
            }
        }
    }

}
