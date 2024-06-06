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
            src/uilogin/uilogindialog.cpp src/uilogin/uilogindialog.h src/uilogin/uilogindialog.ui
            src/uimain/uimainwidget.h src/uimain/uimainwidget.cpp src/uimain/uimainwidget.ui
            src/uimain/uibucketswidget.h src/uimain/uibucketswidget.cpp src/uimain/uibucketswidget.ui
            src/uimain/uiobjectstablewidget.h src/uimain/uiobjectstablewidget.cpp src/uimain/uiobjectstablewidget.ui
            src/uimain/toolbarwidget.h src/uimain/toolbarwidget.cpp src/uimain/toolbarwidget.ui
            src/uicom/uibreadwidget.h src/uicom/uibreadwidget.cpp src/uicom/uibreadwidget.ui
            src/uicom/uipagewidget.h src/uicom/uipagewidget.cpp src/uicom/uipagewidget.ui
            src/uidelegate/uibucketdeleagte.h src/uidelegate/uibucketdeleagte.cpp
            src/uicom/uiqosdialog.h src/uicom/uiqosdialog.cpp src/uicom/uiqosdialog.ui
            src/uicom/uicomboline.h src/uicom/uicomboline.cpp
            src/uicom/uibasedialog.h src/uicom/uibasedialog.cpp src/uicom/uibasedialog.ui
            src/uimain/uibucketstablewidget.h src/uimain/uibucketstablewidget.cpp src/uimain/uibucketstablewidget.ui
            src/dao/daocloudmock.cpp src/dao/DaoCloudMock.h src/dao/DaoClouds.h src/dao/entityclass.h
            src/center/gateway.cpp src/center/gateway.h src/center/managermodel.cpp src/center/managermodel.h src/center/qosplugin.cpp src/center/qosplugin.h
            src/helper/FileHelper.h src/helper/Public.h src/helper/Singleton.h

            src/center/osmockdata.h src/center/osmockdata.cpp
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
include_directories(${PROJECT_SOURCE_DIR}/src/center)

include_directories(${PROJECT_SOURCE_DIR}/third)

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
