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

#ifndef CONFIGITEM_H
#define CONFIGITEM_H

#include "stdafx.h"

DWIDGET_USE_NAMESPACE

class ProfileItem : public DSimpleListItem {
    Q_OBJECT
public:
    ProfileItem(QJsonObject o);

    bool sameAs(DSimpleListItem *item);
    void drawBackground(QRect rect, QPainter *painter, int index, bool isSelect, bool isHover);
    void drawForeground(QRect rect, QPainter *painter, int column, int index, bool isSelect, bool isHover);

    static bool search(const DSimpleListItem *item, QString searchContent);

    static bool sortByName(const DSimpleListItem *item1, const DSimpleListItem *item2, bool descendingSort);

    static bool sortByServer(const DSimpleListItem *item1, const DSimpleListItem *item2, bool descendingSort);

    static bool sortByTotalUsager(const DSimpleListItem *item1, const DSimpleListItem *item2, bool descendingSort);

    QString getId();

    QString getName() const;

    QString getServer() const;

    QString getStatus();

    QString getLatency();

    QString getLocalPort();

    QString getTermUsage();

    QString getTotalUsage() const;

    QString getResetDate();

    QString getLastUsed();

public slots:

    void changeTheme(QString theme);

    void initTheme();

private:
    QJsonObject config;
    QString name;
    QString server;
    QString status;
    QString latency;
    QString local_port;
    QString term_usage;
    QString total_usage;
    QString last_used;
    QStringList texts;
    // copy from deepin-system-moniter
    QPixmap iconPixmap;
    QString displayName;
    QString evenLineColor;
    QString oddLineColor;
    QString path;
    QString selectLineColor;
    QString textColor;
    QString user;
    bool displayNameComplete;
    char state;
    double cpu;
    double evenLineOpacity;
    double oddLineOpacity;
    double selectOpacity;
    double textLeftOpacity;
    double textRightOpacity;
    int iconSize;
    int padding;
    int pid;
    int textPadding;
    long memory;

    void drawCell(bool isSelect, QRect rect, QPainter *painter, QString text);
};

#endif // CONFIGITEM_H
