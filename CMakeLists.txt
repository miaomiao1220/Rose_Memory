cmake_minimum_required(VERSION 3.16)

project(rose-quick VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)


find_package(Qt6 REQUIRED COMPONENTS Multimedia)

qt_standard_project_setup()

#set(app_icon_resource_windows "${CMAKE_CURRENT_SOURCE_DIR}/icons/icon.rc")
set(MACOSX_BUNDLE_ICON_FILE icon.icns)

# And the following tells CMake where to find and install the file itself.
set(app_icon_macos "${CMAKE_CURRENT_SOURCE_DIR}/icons/icon.icns")
set_source_files_properties(${app_icon_macos} PROPERTIES
       MACOSX_PACKAGE_LOCATION "Resources")


qt_add_executable(approse-quick
        main.cpp
        AppManager.cpp
        AppManager.h
        Player.h
        Player.cpp
        FieldStatus.h
        FieldStatus.cpp
        Config.h
        Config.cpp
        StoryDialog.cpp
        StoryDialog.h
        PlantConf.h
        PlantConf.cpp
#        ${app_icon_resource_windows}
        ${app_icon_macos}
        )

target_link_libraries(approse-quick PRIVATE Qt6::Multimedia)

set_source_files_properties(AppManager.qml
        PROPERTIES
        QT_QML_SINGLETON_TYPE true
        )

set_source_files_properties(Conf.qml
        PROPERTIES
        QT_QML_SINGLETON_TYPE true
        )

qt_add_qml_module(approse-quick
        URI rose-quick
        VERSION 1.0
        QML_FILES
        Main.qml
        MainWindow.qml
        StartupWindow.qml
        BagWindow.qml
        WishWindow.qml
        WishResultModel.qml
        WishResultPlantDisplay.qml
        StoreWindow.qml
        MoneyUtil.qml
        PlantDisplay.qml
        FieldDisplay.qml
        FieldStatusDisplay.qml
        ButtonDisplay.qml
        ToolBoxDisplay.qml
        StoryWindow.qml
        SeedSelectorModel.qml
        SeedSelectorPlantDisplay.qml
        #    AppManager.qml
        EndingWindow.qml
        Conf.qml
        RESOURCE_PREFIX
        /
        RESOURCES
        resources.qrc
        )

set_target_properties(approse-quick PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER miaowey
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
        AUTOMOC ON
        )

target_link_libraries(approse-quick
        PRIVATE Qt6::Quick
        )

add_custom_command(TARGET approse-quick POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_SOURCE_DIR}/audios $<TARGET_FILE_DIR:approse-quick>/audios)

add_custom_command(TARGET approse-quick POST_BUILD
                  COMMAND ${CMAKE_COMMAND} -E copy_directory
                  ${CMAKE_SOURCE_DIR}/videos $<TARGET_FILE_DIR:approse-quick>/videos)

target_include_directories(approse-quick PUBLIC ${PROJECT_SOURCE_DIR})

install(TARGETS approse-quick
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
