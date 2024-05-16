cmake_minimum_required(VERSION 3.5)

project(qosbrowser VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(qosbrowser
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET qosbrowser APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(qosbrowser SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(qosbrowser
            ${PROJECT_SOURCES}
            logo.rc
            logo.ico
            res.qrc
            src/uilogin/logindialog.cpp src/uilogin/logindialog.h src/uilogin/logindialog.ui
            src/uimain/mainwidget.h src/uimain/mainwidget.cpp src/uimain/mainwidget.ui
            src/uimain/bucketswidget.h src/uimain/bucketswidget.cpp src/uimain/bucketswidget.ui
            src/uimain/objectswidget.h src/uimain/objectswidget.cpp src/uimain/objectswidget.ui
            src/uimain/toolbarwidget.h src/uimain/toolbarwidget.cpp src/uimain/toolbarwidget.ui
            src/uicom/breadwidget.h src/uicom/breadwidget.cpp src/uicom/breadwidget.ui
            src/uicom/pagewidget.h src/uicom/pagewidget.cpp src/uicom/pagewidget.ui
            src/uidelegate/bucketdeleagte.h src/uidelegate/bucketdeleagte.cpp
            src/helper/commonformat.h src/helper/FileHelper.h src/helper/gateway.cpp src/helper/gateway.h src/helper/Singleton.h

            src/model/bucket.h src/model/bucketmodel.cpp src/model/bucketmodel.h
            src/dao/DaoClouds.h
            src/dao/daocloudmock.h src/dao/daocloudmock.cpp
            src/plugins/qosplugin.h src/plugins/qosplugin.cpp
        )
    endif()
endif()

target_link_libraries(qosbrowser PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

include_directories(${PROJECT_SOURCE_DIR}/src/uimain)
include_directories(${PROJECT_SOURCE_DIR}/src/uicom)
include_directories(${PROJECT_SOURCE_DIR}/src/uilogin)
include_directories(${PROJECT_SOURCE_DIR}/src/uidelegate)
include_directories(${PROJECT_SOURCE_DIR}/src/helper)
include_directories(${PROJECT_SOURCE_DIR}/src/dao)
include_directories(${PROJECT_SOURCE_DIR}/src/model)
include_directories(${PROJECT_SOURCE_DIR}/src/plugins)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.qosbrowser)
endif()
set_target_properties(qosbrowser PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS qosbrowser
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(qosbrowser)
endif()
