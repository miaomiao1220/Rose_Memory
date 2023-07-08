import QtQuick

Rectangle {
    width: 280
    height: 104
    color: "#f7f7f7"
    visible: AppManager.fieldStatusDisplayId !== -1 ? true : false
    Text {
        id: text1
        x: 8
        y: 4
        width: 245
        height: 96
        text: AppManager.fieldStatusDisplayId >= 0 ?
                  "[" + AppManager.fieldHeight[AppManager.fieldStatusDisplayId] + "田地] " +
                  AppManager.fieldPlantName[AppManager.fieldStatusDisplayId] + "\n" +
                  (AppManager.fieldPlantName[AppManager.fieldStatusDisplayId] !== "无作物" ?
                       AppManager.fieldPlantGrowStatus[AppManager.fieldStatusDisplayId] + "阶段\n" +
                       (AppManager.fieldPlantWaterStatus[AppManager.fieldStatusDisplayId] === "干旱" ?
                            "缺水，请及时浇水":
                            (AppManager.fieldPlantGrowStatus[AppManager.fieldStatusDisplayId] === "收获" ?
                                 "使用收获工具收获！":
                                 "距离下一阶段还有" + AppManager.fieldPlantTTN[AppManager.fieldStatusDisplayId] + "秒")):
                       ""
                   )
                :
                  ""
        font.pixelSize: 20
        verticalAlignment: Text.AlignVCenter
        font.family: "FZYanSongS-M-GB"
    }

}
