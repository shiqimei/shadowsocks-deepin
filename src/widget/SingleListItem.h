//
// Created by pikachu on 18-1-1.
//

#ifndef SHADOWSOCKS_CLIENT_SINGLELISTITEM_H
#define SHADOWSOCKS_CLIENT_SINGLELISTITEM_H

#include "stdafx.h"
#include <DSimpleListItem>
#include <interface/ProxyConfig.h>

DWIDGET_USE_NAMESPACE

class SingleListItem : public DSimpleListItem
{
Q_OBJECT

public:
    explicit SingleListItem(QString itemName);
    SingleListItem(ProxyConfig* config);

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
    // 名字属性，这里用于绘制文本列的内容
    QString name;
    ProxyConfig* config;

    QString evenLineColor;
    QString oddLineColor;
    QString selectLineColor;
    double evenLineOpacity;
    double oddLineOpacity;
    double selectOpacity;
};


#endif //SHADOWSOCKS_CLIENT_SINGLELISTITEM_H
