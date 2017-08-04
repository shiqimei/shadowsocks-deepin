cmake_minimum_required(VERSION 3.7)
project(shadowsocks-client)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_FLAGS -Wall)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "set build type to debug")
#set(CMAKE_BUILD_TYPE Release CACHE STRING "set build type to Release")
include_directories(${CMAKE_CURRENT_BINARY_DIR})
if (NOT (${CMAKE_BUILD_TYPE} MATCHES "Debug"))
    set(CMAKE_CXX_FLAGS -O3)
endif ()

file(GLOB SRCS "*.h" "*.cpp" "*.qrc" "*.ui")
find_package(PkgConfig REQUIRED)
find_package(Qt5 REQUIRED Core Gui Widgets Network DBus)
pkg_check_modules(3rd_lib REQUIRED
        QtShadowsocks
        botan-1.10
        dtkbase dtkwidget dframeworkdbus
        libqrencode zbar
        )
include_directories(/usr/include/qwt)
add_executable(${PROJECT_NAME} ${SRCS})
target_include_directories(${PROJECT_NAME} PUBLIC ${3rd_lib_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${3rd_lib_LIBRARIES} /usr/lib/libqwt-qt5.so)
qt5_use_modules(${PROJECT_NAME} Core Gui Widgets Network DBus)
# Install settings
if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX /usr)
endif ()

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
install(FILES ${PROJECT_NAME}.desktop DESTINATION ${CMAKE_INSTALL_PREFIX}/share/applications)
install(FILES shadowsocks.ico DESTINATION /opt/${PROJECT_NAME})
