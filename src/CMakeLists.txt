
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
file(GLOB_RECURSE TRANSLATIONS "../translations/*.ts")
file(GLOB_RECURSE SRCS ${HEADERS} ${SOURCES} ${FORMS})
set(RESOURCES ${RESOURCES} "../icons.qrc")
find_package(PkgConfig REQUIRED)
set(QT Core Gui Widgets Network DBus LinguistTools)
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
qt5_create_translation(TRANSLATION_MESSAGES ${SRCS} ${TRANSLATIONS})
add_custom_target(translations_update DEPENDS ${TRANSLATION_MESSAGES})
# Install settings
if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX /usr)
endif ()
# Install qm files
file(GLOB QM_FILES "../translations/*.qm")
install(FILES ${QM_FILES}
        DESTINATION share/${PROJECT_NAME}/translations)
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
install(FILES ../${PROJECT_NAME}.desktop DESTINATION ${CMAKE_INSTALL_PREFIX}/share/applications)
install(FILES ../Resources/shadowsocks-client.png DESTINATION /usr/share/icons/hicolor/128x128/apps)