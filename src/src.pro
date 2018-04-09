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
    ConfigDialog.cpp \
    ConfigItem.cpp \
    DDEProxyModeManager.cpp \
    GuiConfig.cpp \
    HotkeySettingsDialog.cpp \
    LogMainWindow.cpp \
    main.cpp \
    MainWindow.cpp \
    PACUrlDialog.cpp \
    ProxyDialog.cpp \
    ProxyManager.cpp \
    ProxyThread.cpp \
    ProxyView.cpp \
    Settings.cpp \
    stdafx.cpp \
    Toolbar.cpp \
    utils.cpp \
    dbusinterface/DBusStartManager.cpp \
    interface/SystemProxyModeManager.cpp \
    ShareDialog.cpp \
    QRCodeCapturer.cpp \
    SSValidator.cpp \
    URIHelper.cpp \
    QRWidget.cpp

HEADERS += \
    ConfigDialog.h \
    ConfigItem.h \
    constant.h \
    DDEProxyModeManager.h \
    GuiConfig.h \
    HotkeySettingsDialog.h \
    LogMainWindow.h \
    MainWindow.h \
    PACUrlDialog.h \
    ProxyDialog.h \
    ProxyManager.h \
    ProxyThread.h \
    ProxyView.h \
    Settings.h \
    stdafx.h \
    Toolbar.h \
    utils.h \
    dbusinterface/DBusStartManager.h \
    interface/SystemProxyModeManager.h \
    ShareDialog.h \
    URIHelper.h \
    SSValidator.h \
    QRWidget.h \
    QRCodeCapturer.h

FORMS += \
    ConfigDialog.ui \
    HotkeySettingsDialog.ui \
    LogMainWindow.ui \
    MainWindow.ui \
    PACUrlDialog.ui \
    ProxyDialog.ui \
    ShareDialog.ui
RESOURCES += \
    qrc.qrc
TRANSLATIONS += translations/shadowsocks-client_zh.ts \
               translations/shadowsocks-client_en.ts

DISTFILES += \
    translate_generation.sh \
    dbusinterface/com.deepin.StartManager.xml

