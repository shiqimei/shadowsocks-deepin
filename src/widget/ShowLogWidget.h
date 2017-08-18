//
// Created by pikachu on 17-8-3.
//

#ifndef SHADOWSOCKS_CLIENT_SHOWLOGWIDGET_H
#define SHADOWSOCKS_CLIENT_SHOWLOGWIDGET_H


#include <QtWidgets/QPlainTextEdit>
#include <QDebug>
#include <dwidget_global.h>
#include <dutil_global.h>

DWIDGET_USE_NAMESPACE
        DUTIL_USE_NAMESPACE
class ShowLogWidget: public QWidget {
public:
    ShowLogWidget(QWidget *parent= nullptr);

private:
    QPlainTextEdit* plainTextEdit;

};


#endif //SHADOWSOCKS_CLIENT_SHOWLOGWIDGET_H
