/**
 * Copyright (C) 2017 ~ 2018 PikachuHy
 *
 * Author:     PikachuHy <pikachuhy@163.com>
 * Maintainer: PikachuHy <pikachuhy@163.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
