cmake_minimum_required(VERSION 3.7)
project(ss)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_FLAGS -Wall)
if (NOT (${CMAKE_BUILD_TYPE} MATCHES "Debug"))
    set(CMAKE_CXX_FLAGS -O3)
endif ()

file(GLOB SRCS "*.h" "*.cpp")

find_package(PkgConfig REQUIRED)
find_package(Qt5 REQUIRED Core Gui Widgets Network)
pkg_check_modules(QtShadowsocks REQUIRED QtShadowsocks)
pkg_check_modules(Botan REQUIRED botan-1.10)
pkg_check_modules(DtkBase REQUIRED dtkbase)
pkg_check_modules(DtkWidget REQUIRED dtkwidget)
add_executable(ss ${SRCS})
target_include_directories(ss PUBLIC
        ${QtShadowsocks_INCLUDE_DIRS}
        ${Botan_INCLUDE_DIRS}
        ${DtkBase_INCLUDE_DIRS}
        ${DtkWidget_INCLUDE_DIRS}
        )
target_link_libraries(ss
        ${QtShadowsocks_LIBRARIES}
        ${Botan_LIBRARIES}
        ${DtkBase_LIBRARIES}
        ${DtkWidget_LIBRARIES}
        )
qt5_use_modules(${PROJECT_NAME} Core Gui Widgets Network)