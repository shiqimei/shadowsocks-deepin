#-------------------------------------------------
#
# Project created by QtCreator 2018-01-23T22:54:30
#
#-------------------------------------------------

QT       += core gui network dbus x11extras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = shadowsocks-client
TEMPLATE = app
CONFIG += link_pkgconfig
CONFIG += c++11
PKGCONFIG += dtkwidget QtShadowsocks dframeworkdbus libqrencode zbar
# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

PRECOMPILED_HEADER = stdafx.h
precompile_header:!isEmpty(PRECOMPILED_HEADER) {
DEFINES += USING_PCH
}
SOURCES += \
        main.cpp \
        MainWindow.cpp \
    stdafx.cpp \
    utils.cpp \
    ConfigDialog.cpp \
    ProxyDialog.cpp \
    LogMainWindow.cpp \
    PACUrlDialog.cpp \
    HotkeySettingsDialog.cpp \
    Toolbar.cpp \
    GuiConfig.cpp \
    ProxyManager.cpp \
    DDEProxyModeManager.cpp \
    interface/SystemProxyModeManager.cpp \
    dbusinterface/DBusStartManager.cpp \
    ConfigItem.cpp \
    ProxyThread.cpp \
    ProxyView.cpp \
    Settings.cpp \
    qrcodecapturer.cpp \
    qrwidget.cpp \
    urihelper.cpp \
    ssvalidator.cpp

HEADERS += \
        MainWindow.h \
    stdafx.h \
    utils.h \
    ConfigDialog.h \
    ProxyDialog.h \
    LogMainWindow.h \
    PACUrlDialog.h \
    HotkeySettingsDialog.h \
    Toolbar.h \
    GuiConfig.h \
    ProxyManager.h \
    DDEProxyModeManager.h \
    interface/SystemProxyModeManager.h \
    dbusinterface/DBusStartManager.h \
    constant.h \
    ConfigItem.h \
    ProxyThread.h \
    ProxyView.h \
    Settings.h \
    qrcodecapturer.h \
    qrwidget.h \
    urihelper.h \
    ssvalidator.h

FORMS += \
        MainWindow.ui \
    ConfigDialog.ui \
    ProxyDialog.ui \
    LogMainWindow.ui \
    PACUrlDialog.ui \
    HotkeySettingsDialog.ui

RESOURCES += \
    qrc.qrc
TRANSLATIONS += translations/shadowsocks-client_zh.ts \
               translations/shadowsocks-client_en.ts
