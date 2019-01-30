cmake_minimum_required(VERSION 3.13.3)
project(shadowsocks-deepin VERSION 1.3.0)

# Debug
# set(CMAKE_BUILD_TYPE Debug)

# Set Environment Variables
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS forms)
set(QT Core Gui Widgets Network DBus Sql LinguistTools)
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "lolimay")

# Generate tranlation(*.qm) files
if(NOT (${CMAKE_BUILD_TYPE} MATCHES "Debug"))
    set(CMAKE_CXX_FLAGS -O3)
    execute_process(COMMAND           "./translate_generation.sh"
                    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/src/utils")
else()
    set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
endif()

# load modules
find_package(PkgConfig REQUIRED)
find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Network CONFIG REQUIRED)
find_package(Qt5DBus CONFIG REQUIRED)

pkg_search_module(DTKCORE REQUIRED dtkcore)
pkg_search_module(DTKWIDGET REQUIRED dtkwidget)
pkg_search_module(DFRAMEWORKDBUS REQUIRED dframeworkdbus)
pkg_search_module(QRENCODE REQUIRED libqrencode)
pkg_search_module(ZBAR REQUIRED zbar)
pkg_search_module(QTSHADOWSOCKS REQUIRED QtShadowsocks)

include_directories(AFTER ${DTKCORE_INCLUDE_DIRS})
include_directories(AFTER ${DTKWIDGET_INCLUDE_DIRS})
include_directories(AFTER ${DFRAMEWORKDBUS_INCLUDE_DIRS})
include_directories(AFTER ${QRENCODE_INCLUDE_DIRS})
include_directories(AFTER ${ZBAR_INCLUDE_DIRS})
include_directories(AFTER ${QTSHADOWSOCKS_INCLUDE_DIRS})

set(SOURCE_FILES main.cpp
                 MainWindow.h          MainWindow.cpp
                 GuiConfig.h           GuiConfig.cpp
                 Settings.h            Settings.cpp
                 ConfigDialog.h        ConfigDialog.cpp
                 ProxyDialog.h         ProxyDialog.cpp
                 ProxyManager.h        ProxyManager.cpp
                 utils.h               utils.cpp
                 ShareDialog.h         ShareDialog.cpp
                 SSValidator.h         SSValidator.cpp
                 QRCodeCapturer.h      QRCodeCapturer.cpp
                 PACUrlDialog.h        PACUrlDialog.cpp
                 Toolbar.h             Toolbar.cpp
                 DDEProxyModeManager.h DDEProxyModeManager.cpp
                 LogMainWindow.h       LogMainWindow.cpp
                 URIHelper.h           URIHelper.cpp
)

set(WIDGETS
    widgets/ProfileItem.h    widgets/ProfileItem.cpp
    widgets/ProfileView.h    widgets/ProfileView.cpp
    widgets/QRWidget.h       widgets/QRWidget.cpp
    widgets/SingleListItem.h widgets/SingleListItem.cpp
    widgets/SingleListView.h widgets/SingleListView.cpp
)

set(INTERFACE
    interface/SystemProxyModeManager.h
    interface/SystemProxyModeManager.cpp
    dbusinterface/DBusStartManager.h
    dbusinterface/DBusStartManager.cpp
)

set(LINK_LIBS
    Qt5::Core
    Qt5::Widgets
    Qt5::Network
    Qt5::DBus
    ${DTKCORE_LIBRARIES}
    ${DTKWIDGET_LIBRARIES}
    ${DFRAMEWORKDBUS_LIBRARIES}
    ${QRENCODE_LIBRARIES}
    ${ZBAR_LIBRARIES}
    ${QTSHADOWSOCKS_LIBRARIES}
)

add_executable(${PROJECT_NAME}
               ${SOURCE_FILES}
               ${WIDGETS}
               ${INTERFACE}
)
target_link_libraries(${PROJECT_NAME} ${LINK_LIBS})

### Installation && Package ###
file(GLOB QM_FILES "translations/*.qm")
install(FILES ${QM_FILES} DESTINATION share/shadowsocks-deepin/translations)
foreach (ICON_SIZE 16 24 32 48 64 96 128 256)
    install(FILES       "resources/ssw${ICON_SIZE}.svg"
            RENAME      "shadowsocks-deepin.svg"
            DESTINATION "/usr/share/icons/hicolor/${ICON_SIZE}x${ICON_SIZE}/apps")
endforeach ()
install(TARGETS     ${PROJECT_NAME}
        DESTINATION "/usr/bin")
install(FILES       "resources/shadowsocks-deepin.desktop"
        DESTINATION "/usr/share/applications")
include(CPack)