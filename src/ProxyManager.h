#ifndef PROXYMANAGER_H
#define PROXYMANAGER_H

#include "stdafx.h"

class ProxyManager : public QObject {
Q_OBJECT
public:
    ProxyManager(QObject *parent = nullptr);

    void setConfig(const QJsonObject &config);

signals:

    void runningStateChanged(bool);

    void newBytesReceived(quint64);

    void newBytesSent(quint64);

    void bytesReceivedChanged(quint64);

    void bytesSentChanged(quint64);

    void tcpLatencyAvailable(int);

public slots:

    bool start();

    void stop();

private:
    QSS::Controller *controller;
    bool isRunning;

    void disconnectController();

    void connectController();

    void getProfile(const QJsonObject &config, QSS::Profile &profile);
};

#endif // PROXYMANAGER_H
