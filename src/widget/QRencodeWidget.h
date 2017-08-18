//
// Created by pikachu on 17-7-25.
//

#ifndef DEEPIN_SHADOWSOCKS_CLIENT_QRENCODEWIDGET_H
#define DEEPIN_SHADOWSOCKS_CLIENT_QRENCODEWIDGET_H

#include <QWidget>
#include <QPainter>
#include <qrencode.h>
/**
 * 专门用来显示二维码
 */
class QRencodeWidget: public QWidget {
public:
    QRencodeWidget(QString string,QWidget *parent= nullptr);
    void setString(QString string);
protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QRcode* qRcode;
};


#endif //DEEPIN_SHADOWSOCKS_CLIENT_QRENCODEWIDGET_H
