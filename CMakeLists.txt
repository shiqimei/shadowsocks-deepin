cmake_minimum_required(VERSION 3.7)
project(ss)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
find_package(Qt5Core)
find_package(Qt5Widgets)
find_package(Qt5DBus)
find_package(Qt5Network)
get_target_property(QtCore_location Qt5::Core LOCATION)
set(CMAKE_CXX_FLAGS_COVERAGE "${CMAKE_CXX_FLAGS_RELEASE} -fprofile-arcs -ftest-coverage")
set_target_properties(Qt5::Core PROPERTIES MAP_IMPORTED_CONFIG_COVERAGE "RELEASE")
foreach(plugin ${Qt5Network_PLUGINS})
    get_target_property(_loc ${plugin} LOCATION)
    message("Plugin ${plugin} is at location ${_loc}")
endforeach()
include_directories(
        /usr/include/qtshadowsocks
        /usr/include/botan-1.10
)
set(SOURCE_FILES main.cpp)
add_executable(ss ${SOURCE_FILES})
target_link_libraries(ss
        QtShadowsocks
        Qt5::Core
        Qt5::Widgets
        Qt5::DBus
        Qt5::Network
        )