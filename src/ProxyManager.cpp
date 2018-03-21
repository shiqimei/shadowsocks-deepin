#include "ProxyManager.h"
#include "utils.h"
#include "ProxyThread.h"

ProxyManager::ProxyManager(QObject *parent) : QObject(parent) {
    isRunning = false;
    controller = nullptr;
}

void ProxyManager::setConfig(const QJsonObject &config) {
    if (controller != nullptr) {
        if (isRunning) {
            controller->stop();
            isRunning = false;
        }
        disconnectController();
        delete controller;
    }
    qDebug() << config;
    QSS::Profile profile;
    getProfile(config, profile);
    profile.enableDebug();
    controller = new QSS::Controller(profile, true, true, this);
    connectController();
}

bool ProxyManager::start() {
    bool flag = controller->start();
    if (!flag) {
        Utils::critical("start fail");
    } else {
        isRunning = true;
    }
    return flag;
//    auto t = new ProxyThread(controller);
//    t->start();
//    // async
//    return true;
}

void ProxyManager::stop() {
    if (isRunning) {
        controller->stop();
        isRunning = false;
    }
}

void ProxyManager::disconnectController() {
    disconnect(controller);
}

void ProxyManager::connectController() {
    connect(controller, &QSS::Controller::bytesReceivedChanged, this, &ProxyManager::bytesReceivedChanged);
    connect(controller, &QSS::Controller::bytesSentChanged, this, &ProxyManager::bytesSentChanged);
    connect(controller, &QSS::Controller::newBytesReceived, this, &ProxyManager::newBytesReceived);
    connect(controller, &QSS::Controller::newBytesSent, this, &ProxyManager::newBytesSent);
    connect(controller, &QSS::Controller::runningStateChanged, this, &ProxyManager::runningStateChanged);
    connect(controller, &QSS::Controller::tcpLatencyAvailable, this, &ProxyManager::tcpLatencyAvailable);
}

void ProxyManager::getProfile(const QJsonObject &config, QSS::Profile &profile) {
    QString server = config.value("server").toString();
    if (server.isEmpty()) {
        Utils::critical("server is empty.");
    }
    profile.setServerAddress(server.toStdString());
    QString password = config.value("password").toString();
    if (password.isEmpty()) {
        Utils::warning("password is empty.");
    }
    profile.setPassword(password.toStdString());
    int server_port = config.value("server_port").toInt();
    if (server_port == 0) {
        Utils::warning("server port is 0.");
    }
    profile.setServerPort(server_port);
    QString method = config.value("method").toString();
    if (method.isEmpty()) {
        Utils::warning("method is empty.");
    }
    profile.setMethod(method.toStdString());
    int timeout = config.value("timeout").toInt() * 10;
    if (timeout == 0) {
        Utils::warning("timeout is 0. we will change the value to 6.");
        timeout = 6;
    }
    profile.setTimeout(timeout);
    int local_port = config.value("local_port").toInt();
    if (local_port == 0) {
        Utils::warning("local_port is 0. we will change the value to 1080.");
        local_port = 1080;
    }
    profile.setLocalPort(local_port);
    QString local_addr = config.value("local_address").toString();
    if (local_addr.isEmpty()) {
        Utils::warning("local address is empty. we will change the value to 127.0.0.1.");
        local_addr = "127.0.0.1";
    }
    profile.setLocalAddress(local_addr.toStdString());
}
