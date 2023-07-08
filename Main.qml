import QtQuick
import QtQuick.Controls
import QtMultimedia

Window {
  id: root
  width: 1364
  height: 768
  visible: true
  title: qsTr("Rose Memory")
  color: "#FFFFFF"

  property string current_music: "prelude"
  property string music_src: "file://" + applicationDirPath + "/audios/" + current_music + ".mp3"

  SeedSelectorModel {
      id: seedSelectorModel
      visible: AppManager.currentModel == "seedSelector"
      z: 100
      onBackClicked: {
          AppManager.currentModel = "none"
          AppManager.currentSeed = -1
      }
      onOkClicked: {
          AppManager.seedConfirm()
          AppManager.currentModel = "none"
          AppManager.currentSeed = -1
      }
  }

  WishResultModel {
      id: wishResultModel
      visible: AppManager.currentModel == "wishResult"
      z: 100
      onBackClicked: {
          AppManager.currentModel = "none"
          AppManager.currentSeed = -1
      }
      onOkClicked: {
          AppManager.seedConfirm()
          AppManager.currentModel = "none"
          AppManager.currentSeed = -1
      }
  }

  StartupWindow {
      id: startupWindow
      visible: AppManager.currentScene === "startup" ? true : false
      onCoverClicked: {
          AppManager.startGame()
      }
  }

  EndingWindow {
      id: endingWindow
      visible: AppManager.currentScene === "ending" ? true : false
      onVisibleChanged: {
          if (visible) root.current_music = "ending"
      }
  }

  MainWindow {
      id: mainWindow
      visible: AppManager.currentScene === "main" ? true : false
      onBagClicked: {
          AppManager.currentScene = "bag"
      }
      onStoreClicked: {
          AppManager.currentScene = "store"
      }
      onWishClicked: {
          AppManager.currentScene = "wish"
      }
      onVisibleChanged: {
          if (visible) root.current_music = "field"
          AppManager.currentTool = "none"
      }
  }

  BagWindow {
      id: bagWindow
      visible: AppManager.currentScene === "bag" ? true : false
      onBackClicked: {
          AppManager.currentScene = "main"
      }
      onVisibleChanged: {
          if (visible) root.current_music = "bag"
      }
  }

  StoreWindow {
      id: storeWindow
      visible: AppManager.currentScene === "store" ? true : false
      onBackClicked: {
          AppManager.currentScene = "main"
      }
      onVisibleChanged: {
          if (visible) root.current_music = "store"
      }
  }

  WishWindow {
      id: wishWindow
      visible: AppManager.currentScene === "wish" ? true : false
      onBackClicked: {
          AppManager.currentScene = "main"
      }
      onVisibleChanged: {
          if (visible) root.current_music = "wish"
      }
  }

  StoryWindow {
      id: storyWindow
      visible: AppManager.currentScene === "story" ? true : false
      onVisibleChanged: {
          if (visible) root.current_music = "story"
      }
  }

  Timer {
      interval: 100
      running: true
      triggeredOnStart: true
      repeat: true
      onTriggered: {
          AppManager.update()
      }
  }

  Image {
      id: popup
      x: 536
      y: 32
      width: 292
      height: 51
      source: "images/story对话框.png"
      fillMode: Image.Stretch
      visible: AppManager.popupMessage !== "" ? true : false
      Text {
        x: 0
        y: 0
        width: 292
        height: 51
        text: AppManager.popupMessage
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pointSize: 18
        font.family: "FZYanSongS-M-GB"
        onTextChanged: {
            timer.restart()
        }
      }
      Timer {
          id: timer
          interval: 2000
          onTriggered: {
              AppManager.popupMessage = ""
          }
      }
  }

  MediaPlayer {
      audioOutput: AudioOutput {}
      source: root.music_src
      Component.onCompleted: { play() }
      onSourceChanged: {
          play()
      }
      loops: MediaPlayer.Infinite
  }
}
