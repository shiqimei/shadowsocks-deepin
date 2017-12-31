//
// Created by pikachu on 17-7-25.
//

#ifndef DEEPIN_SHADOWSOCKS_CLIENT_SHARESERVERCONFIGWIDGET_H
#define DEEPIN_SHADOWSOCKS_CLIENT_SHARESERVERCONFIGWIDGET_H

#include <QDialog>
#include <QLineEdit>
#include <QtWidgets/QListWidget>
#include "QRencodeWidget.h"

class ShareServerConfigWidget : public QDialog {
public:
    explicit ShareServerConfigWidget(QWidget *parent = nullptr);

private:
    QRencodeWidget* qRencodeWidget;
    QListView *listView;
    QLineEdit* lineEdit;
    QString ssUri;
};


#endif //DEEPIN_SHADOWSOCKS_CLIENT_SHARESERVERCONFIGWIDGET_H
