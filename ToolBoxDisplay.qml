import QtQuick

Item {
    width: 150
    height: 300
    ButtonDisplay {
        id: toolSeedButton
        x: 0
        y: 0
        width: 150
        height: 60
        normal_source: "images/工具播种.png"
        hover_source: "images/工具播种高亮.png"
        always_on: AppManager.currentTool == "seed" ? true : false
        onClicked: AppManager.currentTool = "seed"
    }

    ButtonDisplay {
        id: toolWaterButton
        x: 0
        y: 80
        width: 150
        height: 60
        normal_source: "images/工具浇水.png"
        hover_source: "images/工具浇水高亮.png"
        always_on: AppManager.currentTool == "water" ? true : false
        onClicked: AppManager.currentTool = "water"
    }

    ButtonDisplay {
        id: toolHarvestButton
        x: 0
        y: 160
        width: 150
        height: 60
        normal_source: "images/工具收获.png"
        hover_source: "images/工具收获高亮.png"
        always_on: AppManager.currentTool == "harvest" ? true : false
        onClicked: AppManager.currentTool = "harvest"
    }

    ButtonDisplay {
        id: toolCloseButton
        x: 0
        y: 240
        width: 150
        height: 60
        normal_source: "images/工具关闭.png"
        hover_source: "images/工具关闭高亮.png"
        onClicked: AppManager.currentTool = "none"
    }
}
