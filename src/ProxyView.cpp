/* -*- Mode: C++; indent-tabs-mode: nil; tab-width: 4 -*-
 * -*- coding: utf-8 -*-
 *
 * Copyright (C) 2011 ~ 2017 Deepin, Inc.
 *               2011 ~ 2017 Wang Yong
 *
 * Author:     Wang Yong <wangyong@deepin.com>
 * Maintainer: Wang Yong <wangyong@deepin.com>
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

// copy from deepin-system-monitor
#include "stdafx.h"
#include "dthememanager.h"
#include "ProxyView.h"
#include <QTimer>

DWIDGET_USE_NAMESPACE

ProxyView::ProxyView(QList<bool> columnHideFlags) {
    initTheme();

    connect(DThemeManager::instance(), &DThemeManager::themeChanged, this, &ProxyView::changeTheme);

    // Enable frame and radius.
    setFrame(true);
    setClipRadius(8);

    // Set row height.
    setRowHeight(36);

    // Set column widths.
    QList<QString> titles;
    titles << tr("Name") << tr("Server") << tr("Status") << tr("Latency") << tr("Local Port") << tr("Term Usage")
           << tr("Total") << tr("Reset Date") << tr("Last Used");
    QList<int> widths;
    widths << -1 << 200 << 70 << 80 << 80 << 70 << 70 << 70 << 150;
    setColumnTitleInfo(titles, widths, 36);

    // Set column hide flags.
    setColumnHideFlags(columnHideFlags, 0);

    // Focus keyboard when create.
    QTimer::singleShot(0, this, SLOT(setFocus()));
}

void ProxyView::initTheme() {
    if (DThemeManager::instance()->theme() == "light") {
        titleColor = "#000000";
        titleLineColor = "#000000";

        titleAreaColor = "#ffffff";
        titleAreaOpacity = 0.02;

        backgroundColor = "#ffffff";
        backgroundOpacity = 0.03;

        frameColor = "#000000";
        frameOpacity = 0.1;

        searchColor = "#D0D0D0";

        arrowUpNormalImage = arrowUpLightNormalImage;
        arrowUpHoverImage = arrowUpLightHoverImage;
        arrowUpPressImage = arrowUpLightPressImage;
        arrowDownNormalImage = arrowDownLightNormalImage;
        arrowDownHoverImage = arrowDownLightHoverImage;
        arrowDownPressImage = arrowDownLightPressImage;

        scrollbarColor = "#101010";

        scrollbarNormalOpacity = 0.5;
        scrollbarHoverOpacity = 0.7;
        scrollbarPressOpacity = 0.8;

        scrollbarFrameNormalOpacity = 0;
        scrollbarFrameHoverOpacity = 0;
        scrollbarFramePressOpacity = 0;
    } else {
        titleColor = "#9A9A9A";
        titleLineColor = "#ffffff";

        titleAreaColor = "#ffffff";
        titleAreaOpacity = 0.02;

        backgroundColor = "#ffffff";
        backgroundOpacity = 0.03;

        frameColor = "#000000";
        frameOpacity = 0;

        searchColor = "#666666";

        arrowUpNormalImage = arrowUpDarkNormalImage;
        arrowUpHoverImage = arrowUpDarkHoverImage;
        arrowUpPressImage = arrowUpDarkPressImage;
        arrowDownNormalImage = arrowDownDarkNormalImage;
        arrowDownHoverImage = arrowDownDarkHoverImage;
        arrowDownPressImage = arrowDownDarkPressImage;

        scrollbarColor = "#ffffff";

        scrollbarNormalOpacity = 0.2;
        scrollbarHoverOpacity = 0.4;
        scrollbarPressOpacity = 0.15;

        scrollbarFrameNormalOpacity = 0.05;
        scrollbarFrameHoverOpacity = 0.1;
        scrollbarFramePressOpacity = 0.05;
    }
}

void ProxyView::changeTheme(QString) {
    initTheme();
}


void ProxyView::contextMenuEvent(QContextMenuEvent *)
{
    emit rightClickBlank();
}
