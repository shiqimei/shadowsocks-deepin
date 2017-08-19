
#message(${CMAKE_CURRENT_SOURCE_DIR})
#file(GLOB_RECURSE SRCS "*.h" "*.cpp" "*.qrc" "*.ui")
#aux_source_directory(. SRCS)
#foreach(it ${SRCS})
#    message(${it})
#endforeach()
file(GLOB_RECURSE SOURCES "*.cpp")
file(GLOB_RECURSE HEADERS "*.h")
file(GLOB_RECURSE FORMS "*.ui")
file(GLOB_RECURSE RESOURCES "*.qrc")
set(RESOURCES ${RESOURCES} "../icons.qrc")
find_package(PkgConfig REQUIRED)
set(QT Core Gui Widgets Network DBus)
find_package(Qt5 REQUIRED ${QT})
pkg_check_modules(3rd_lib REQUIRED
        QtShadowsocks
        botan-1.10
        dtkbase dtkwidget dframeworkdbus
        libqrencode zbar
        )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${FORMS} ${RESOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${3rd_lib_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${3rd_lib_LIBRARIES})
qt5_use_modules(${PROJECT_NAME} ${QT})

# Install settings
if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX /usr)
endif ()
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
install(FILES ../${PROJECT_NAME}.desktop DESTINATION ${CMAKE_INSTALL_PREFIX}/share/applications)
install(FILES ../Resources/shadowsocks-client.png DESTINATION /usr/share/icons/hicolor/128x128/apps)