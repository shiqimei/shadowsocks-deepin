cmake_minimum_required(VERSION 3.5.1)
project(shadowsocks-client)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_FLAGS -Wall)
#set(CMAKE_BUILD_TYPE Debug CACHE STRING "set build type to debug")
set(CMAKE_BUILD_TYPE Release CACHE STRING "set build type to Release")
include_directories(${CMAKE_CURRENT_BINARY_DIR})
if (NOT (${CMAKE_BUILD_TYPE} MATCHES "Debug"))
    set(CMAKE_CXX_FLAGS -O3)

    # generate qm files
    execute_process(COMMAND bash "translate_generation.sh"
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
else ()
    set(CMAKE_CXX_COMPILER "clang++")
endif ()

add_subdirectory(src)