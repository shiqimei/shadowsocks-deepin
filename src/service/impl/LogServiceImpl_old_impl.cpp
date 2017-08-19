//
// Created by pikachu on 17-8-18.
//

#include <util/Util.h>
#include "LogServiceImpl_old_impl.h"

void LogServiceImpl_old_impl::showLog() {
    showLogWidget.show();
}

void LogServiceImpl_old_impl::setVerboseLogging(bool b) {
    Util::guiConfig.isVerboseLogging = b;
}

LogServiceImpl_old_impl::LogServiceImpl_old_impl(QObject *parent) : LogService(parent) {

    for (int i = 0; i < maxLenth; ++i) {
        inBytes.append(0);
        outBytes.append(0);
    }
    auto timer = new QTimer();
    connect(timer, &QTimer::timeout, [=]() {
        int type = 0;
        if (!Util::guiConfig.global) {
            type = type | Util::Type::Pac;
        } else {
            type = type | Util::Type::Global;
        }
        if (inByte > 0) {
            type = type | Util::Type::In;
        }
        inBytes.append(inByte);
        inByte = 0;
        if (inBytes.size() > maxLenth) {
            inBytes.pop_front();
        }

        if (outByte > 0) {
            type = type | Util::Type::Out;
        }
        outBytes.append(outByte);
        outByte = 0;
        if (outBytes.size() > maxLenth) {
            outBytes.pop_front();
        }
        emit requestUpdateIcon(QPixmap::fromImage(Util::proxyIconImage(type)));
        // 如果显示流量监控窗口 触发重绘
    });
    timer->start(300);

}

bool LogServiceImpl_old_impl::isVerboseLogging() {
    return Util::guiConfig.isVerboseLogging;
}

void LogServiceImpl_old_impl::newController(Controller *controller) {

    QObject::connect(controller, &QSS::Controller::debug, [=](QString log) {
        qDebug() << "[QSS::Controller::debug]" << log;
    });
    QObject::connect(controller, &QSS::Controller::info, [=](QString log) {
        qDebug() << "[QSS::Controller::info]" << log;
    });
    connect(controller, &QSS::Controller::runningStateChanged, [=](bool flag) {
        qDebug() << "QSS::Controller::runningStateChanged" << flag;
    });
    connect(controller, &QSS::Controller::newBytesReceived, [=](const qint64 bytes) {
//        qDebug() << "QSS::Controller::newBytesReceived" << bytes;
        inByte += bytes;
    });
    connect(controller, &QSS::Controller::newBytesSent, [=](const qint64 bytes) {
//        qDebug() << "QSS::Controller::newBytesSent" << bytes;
        outByte += bytes;
    });

}
