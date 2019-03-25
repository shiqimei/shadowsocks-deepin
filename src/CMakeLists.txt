cmake_minimum_required(VERSION 3.11.2)
project(shadowsocks-deepin
    VERSION 1.3.0
    DESCRIPTION "a powful shadowsocks client for deepin"
)

# Set Environment Variables
# set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS forms)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "lolimay")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION ${PROJECT_DESCRIPTION})
set(CPACK_DEBIAN_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libqtshadowsocks (>=2.0.1-1), libqrencode3 (>=3.4.4-1+b2), libzbar0 (>=0.10+doc-10.1+b2)")
set(CPACK_DEBIAN_FILE_NAME ${PROJECT_NAME}_${PROJECT_VERSION}.deb)

# Generate tranlation(*.qm) files
if(NOT (${CMAKE_BUILD_TYPE} MATCHES "Debug"))
    set(CMAKE_CXX_FLAGS -O3)
    execute_process(COMMAND           "./translate_generation.sh"
                    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/src/utils")
else()
    set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
endif()

# Load modules
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

file(GLOB_RECURSE SOURCES "*.cpp")
file(GLOB_RECURSE HEADERS "*.h")
file(GLOB_RECURSE FORMS "*.ui")
file(GLOB_RECURSE RESOURCES "*.qrc")
file(GLOB QM_FILES "i18n/*.qm")
set(SOURCE_FILES ${SOURCES} ${HEADERS} ${FORMS} ${RESOURCES})

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

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${LINK_LIBS})

# Installation
install(FILES ${QM_FILES} DESTINATION share/shadowsocks-deepin/translations)
foreach (ICON_SIZE 16 24 32 48 64 96 128 256)
    install(FILES       "resources/icons/ssw${ICON_SIZE}.svg"
            RENAME      "shadowsocks-deepin.svg"
            DESTINATION "/usr/share/icons/hicolor/${ICON_SIZE}x${ICON_SIZE}/apps")
endforeach ()
install(TARGETS     ${PROJECT_NAME}
        DESTINATION "/usr/bin")
install(FILES       "resources/shadowsocks-deepin.desktop"
        DESTINATION "/usr/share/applications")
include(CPack)
