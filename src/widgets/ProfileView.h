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

#ifndef PROCESSVIEW_H
#define PROCESSVIEW_H

#include <DSimpleListView>

DWIDGET_USE_NAMESPACE

class ProfileView : public DSimpleListView {
    Q_OBJECT

public:
    ProfileView(QList<bool> columnHideFlags);

public slots:

    void changeTheme(QString theme);

    void initTheme();

    // QWidget interface
protected:
    void contextMenuEvent(QContextMenuEvent *event) override;
signals:
    void rightClickBlank();
};

#endif
