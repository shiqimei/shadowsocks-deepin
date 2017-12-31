//
// Created by pikachu on 17-12-31.
//

#ifndef SHADOWSOCKS_CLIENT_MULTILISTITEM_H
#define SHADOWSOCKS_CLIENT_MULTILISTITEM_H

#include "stdafx.h"
#include <DSimpleListItem>
#include <interface/ProxyConfig.h>

DWIDGET_USE_NAMESPACE
class MultiListItem : public DSimpleListItem{
Q_OBJECT
public:
    MultiListItem();
    MultiListItem(ProxyConfig* config);
    MultiListItem(QString artistName, QString songName, QString songLength);
    // DSimpleListItem 接口函数，用于区分两个Item是否是同一个Item?
    bool sameAs(DSimpleListItem *item);

    // 绘制Item背景的接口函数，参数依次为表格矩形、绘制QPainter对象、行索引、当前行是否选中？
    void drawBackground(QRect rect, QPainter *painter, int index, bool isSelect);

    // 绘制Item前景的接口函数，参数依次为表格矩形、绘制QPainter对象、行索引、当前行是否选中？
    void drawForeground(QRect rect, QPainter *painter, int column, int index, bool isSelect);
public slots:
    void changeTheme(QString theme);
    void initTheme();
private:
    ProxyConfig* config;
    QString artist;
    QString song;
    QString length;

    QString evenLineColor;
    QString name;
    QString oddLineColor;
    QString selectLineColor;
    double evenLineOpacity;
    double oddLineOpacity;
    double selectOpacity;
};


#endif //SHADOWSOCKS_CLIENT_MULTILISTITEM_H
