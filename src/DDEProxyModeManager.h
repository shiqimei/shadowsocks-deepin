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

#ifndef SHADOWSOCKS_CLIENT_DDEPROXYMODEMANAGER_H
#define SHADOWSOCKS_CLIENT_DDEPROXYMODEMANAGER_H

#include "stdafx.h"
#include "interface/SystemProxyModeManager.h"
#include <com_deepin_daemon_network.h>

using NetworkInter = com::deepin::daemon::Network;

class DDEProxyModeManager : public SystemProxyModeManager {
    Q_OBJECT
public:
    explicit DDEProxyModeManager(QObject *parent = nullptr);

    void switchToNone() override;

    void switchToAuto(QString pacURI) override;

    void switchToManual(QString localAddress, int port) override;

private:
    NetworkInter networkInter;

    void setProxyMethod(QString proxyMethod);
};


#endif //SHADOWSOCKS_CLIENT_DDEPROXYMODEMANAGER_H
