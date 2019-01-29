include(CPack)

cmake_minimum_required(VERSION 3.7)
project(shadowsocks-deepin VERSION 1.3.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS forms)

set(CMAKE_INSTALL_PREFIX /usr)
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "lolimay")

# generate *.qm files
if (NOT (${CMAKE_BUILD_TYPE} MATCHES "Debug"))
    set(CMAKE_CXX_FLAGS -O3)
    execute_process(COMMAND bash "translate_generation.sh"
                    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/src/utils)
else ()
    set(CMAKE_CXX_COMPILER "clang++")
endif ()

# collect all source files
file(GLOB_RECURSE SOURCES "*.cpp")
file(GLOB_RECURSE HEADERS "*.h")
file(GLOB_RECURSE FORMS "*.ui")
file(GLOB_RECURSE RESOURCES "*.qrc")

find_package(PkgConfig REQUIRED)
set(QT Core Gui Widgets Network DBus Sql LinguistTools)
find_package(Qt5 REQUIRED ${QT})

# add 3rd_party libs
pkg_check_modules(lib REQUIRED
    dtkwidget dframeworkdbus
    dtkcore
    libqrencode zbar
)

#add_dependencies(../libQtShadowsocks)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${FORMS} ${RESOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}/src/3rdparty/include/botan-2
    ${CMAKE_SOURCE_DIR}/src/3rdparty/include/QtShadowsocks)
target_link_libraries(${PROJECT_NAME}
    ${CMAKE_SOURCE_DIR}/src/3rdparty/libQtShadowsocks.a
    ${CMAKE_SOURCE_DIR}/src/3rdparty/lib/libbotan-2.a
)



qt5_use_modules(${PROJECT_NAME} ${QT})

### Installation && Package ###
# Install *.qm files
file(GLOB QM_FILES "translations/*.qm")
install(FILES ${QM_FILES} DESTINATION share/shadowsocks-deepin/translations)

# Install icons
foreach (ICON_SIZE 16 24 32 48 64 96 128 256)
    install(FILES Resources/ssw${ICON_SIZE}.svg
            RENAME shadowsocks-deepin.svg
            DESTINATION share/icons/hicolor/${ICON_SIZE}x${ICON_SIZE}/apps)
endforeach ()

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES ../shadowsocks-deepin.desktop DESTINATION share/applications)
