/**
 * Copyright (C) 2017 ~ 2018 PikachuHy
 *               2018 ~ 2019 lolimay
 *
 * Author:     PikachuHy <pikachuhy@163.com>
 * Maintainer: lolimay   <lolimay@lolimay.cn>
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

#ifndef DSIMPLELISTDEMO_SINGLELISTVIEW_H
#define DSIMPLELISTDEMO_SINGLELISTVIEW_H

#include <DSimpleListView>

DWIDGET_USE_NAMESPACE  // 这句话主要强调使用 dtkwidget 的命名空间，以使用其控件
class SingleListView : public DSimpleListView
{
    Q_OBJECT

public:
    SingleListView(QWidget *parent=0);
    virtual ~SingleListView();
public slots:

    void changeTheme(QString theme);

    void initTheme();
signals:
    void currentRowChanged(int currentRow);
private:
    int currentRow = -1;
};

#endif //DSIMPLELISTDEMO_SINGLELISTVIEW_H
