//
// Created by pikachu on 18-4-10.
//

#ifndef DSIMPLELISTDEMO_SINGLELISTITEM_H
#define DSIMPLELISTDEMO_SINGLELISTITEM_H


#include <DSimpleListItem>

DWIDGET_USE_NAMESPACE
// Deepin系统上和Deepin的Runtime，Dtk的版本不同，真是巨坑
class SingleListItem : public DSimpleListItem
{
    Q_OBJECT

public:
    SingleListItem(QString data);

    // DSimpleListItem 接口函数，用于区分两个Item是否是同一个Item?
    bool sameAs(DSimpleListItem *item);

    // 绘制Item背景的接口函数，参数依次为表格矩形、绘制QPainter对象、行索引、当前行是否选中？
    void drawBackground(QRect rect, QPainter *painter, int index, bool isSelect);
    void drawBackground(QRect rect, QPainter *painter, int index, bool isSelect, bool isHover);

    // 绘制Item前景的接口函数，参数依次为表格矩形、绘制QPainter对象、行索引、当前行是否选中？
    void drawForeground(QRect rect, QPainter *painter, int column, int index, bool isSelect);
    void drawForeground(QRect rect, QPainter *painter, int column, int index, bool isSelect, bool isHover);

    // 名字属性，这里用于绘制文本列的内容
    QString data;
public slots:

    void changeTheme(QString theme);

    void initTheme();
signals:
    void selected();
private:
    QString evenLineColor;
    QString oddLineColor;
    QString selectLineColor;
    QString textColor;
    double evenLineOpacity;
    double oddLineOpacity;
    double selectOpacity;
    double textLeftOpacity;
    double textRightOpacity;
};


#endif //DSIMPLELISTDEMO_SINGLELISTITEM_H
