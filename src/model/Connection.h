//
// Created by pikachu on 17-8-19.
//

#ifndef SHADOWSOCKS_CLIENT_CONNECTION_H
#define SHADOWSOCKS_CLIENT_CONNECTION_H


#include "common/common.h"
#include "SQProfile.h"
#include <QtShadowsocks>

class Connection : public QObject {
Q_OBJECT
public:
    Connection(QObject *parent = 0);

    Connection(const SQProfile &_profile, QObject *parent = 0);

    Connection(QString uri, QObject *parent = 0);

    ~Connection();

    const SQProfile &getProfile() const;

    const QString &getName() const;

    const QString &getLog() const;

    QByteArray getURI() const;

    bool isValid() const;

    const bool &isRunning() const;

    void latencyTest();

signals:

    void stateChanged(bool started);

    void latencyAvailable(const int);

    void newLogAvailable(const QString &);

    void dataUsageChanged(const quint64 &current, const quint64 &total);

    void startFailed();

public slots:

    void start();

    void stop();

private:
    QSS::Controller *controller;
    SQProfile profile;
    bool running;
    QString log;

    void testAddressLatency(const QHostAddress &addr);

    friend class EditDialog;

    friend class ConfigHelper;

    friend class StatusDialog;

    friend class LogDialog;

    friend class ConnectionItem;

private slots:

    void onNewBytesTransmitted(const quint64 &);

    void onNewLog(const QString &);

    void onServerAddressLookedUp(const QHostInfo &host);

    void onLatencyAvailable(const int);

    void onConnectivityTestFinished(bool);
};

Q_DECLARE_METATYPE(Connection*)


#endif //SHADOWSOCKS_CLIENT_CONNECTION_H
