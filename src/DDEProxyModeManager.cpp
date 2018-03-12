#include "DDEProxyModeManager.h"

void DDEProxyModeManager::switchToNone() {
    setProxyMethod("none");
}

void DDEProxyModeManager::switchToAuto(QString pacURI) {
    auto w = new QDBusPendingCallWatcher(networkInter.SetAutoProxy(pacURI), this);
    QObject::connect(w, &QDBusPendingCallWatcher::finished, [=]() {
        qDebug() << "set pac URI " << pacURI;
        setProxyMethod("auto");
    });
}

void DDEProxyModeManager::switchToManual(QString localAddress, int _port) {
    QString type = "socks";
    QString addr = localAddress;
    QString port = QString::number(_port);
    auto w = new QDBusPendingCallWatcher(networkInter.SetProxy(type, addr, port), this);
    QObject::connect(w, &QDBusPendingCallWatcher::finished, [=] {
        qDebug() << "set proxy" << type << addr << port;
        setProxyMethod("manual");
    });
    connect(w, &QDBusPendingCallWatcher::finished, w, &QDBusPendingCallWatcher::deleteLater);
}

DDEProxyModeManager::DDEProxyModeManager(QObject *parent)
        : SystemProxyModeManager(parent),
          networkInter("com.deepin.daemon.Network", "/com/deepin/daemon/Network", QDBusConnection::sessionBus(),
                       this) {}

void DDEProxyModeManager::setProxyMethod(QString proxyMethod) {
    QDBusPendingCallWatcher *w = new QDBusPendingCallWatcher(networkInter.SetProxyMethod(proxyMethod), this);
    QObject::connect(w, &QDBusPendingCallWatcher::finished, [=] {
        qDebug() << "success to set proxy method " << proxyMethod;
    });
    connect(w, &QDBusPendingCallWatcher::finished, w, &QDBusPendingCallWatcher::deleteLater);
}
