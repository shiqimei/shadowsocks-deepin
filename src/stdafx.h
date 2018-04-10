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

#ifndef STDAFX_H
#define STDAFX_H

#include <QtCore>
#include <QtGui>
#include <QtWidgets>

#include <DApplication>
#include <DMainWindow>
#include <DWidgetUtil>
#include <DHiDPIHelper>
#include <DSingleton>
#include <DTitlebar>
#include <DLog>
#include <DSimpleListItem>
#include <DSimpleListView>
#include <dsearchedit.h>
#include <dthememanager.h>
#include <ddialog.h>

#include <iostream>
#include <sys/types.h>
#include <thread>
#include <unistd.h>
#include <csignal>

#include <QtShadowsocks>

namespace Constant {
const int WINDOW_MIN_WIDTH = 900;
const int WINDOW_MIN_HEIGHT = 620;
};
#endif // STDAFX_H
