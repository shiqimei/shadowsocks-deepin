#include "ProxyThread.h"

ProxyThread::ProxyThread(QSS::Controller *controller) {
    this->controller = controller;
}

void ProxyThread::run() {
    qDebug() << "start proxy";
    auto flag = controller->start();
    qDebug() << "result" << flag;
}
