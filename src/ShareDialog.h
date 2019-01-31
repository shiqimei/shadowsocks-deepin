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

#ifndef SHAREDIALOG_H
#define SHAREDIALOG_H
#include "stdafx.h"
#include "widgets/QRWidget.h"
#include "widgets/SingleListView.h"

class ShareDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShareDialog(QWidget *parent = 0);
    virtual ~ShareDialog();
    void closeEvent(QCloseEvent *);
private slots:
    void onItemSelected();
    void onSaveQRCodeImage();
private:
    SingleListView* listView;
    QRWidget* qrWidget;
    QLabel* uriLabel;
    QPlainTextEdit* uriText;
    QPushButton* saveButton;

    QString currentURI;

    void setCurrentURI(QString uri);
};

#endif // SHAREDIALOG_H
