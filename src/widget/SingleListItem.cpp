//
// Created by pikachu on 18-4-10.
//

#include "SingleListItem.h"
#include <QColor>
#include <DThemeManager>

DWIDGET_USE_NAMESPACE

SingleListItem::SingleListItem(QString data)
{
    initTheme();

    connect(DThemeManager::instance(), &DThemeManager::themeChanged, this, &SingleListItem::changeTheme);
    // 初始化数据项
    this->data = data;
}

bool SingleListItem::sameAs(DSimpleListItem *item)
{
    // 根据两个Item的属性来判断两个Item是否是相同的？
    // DSimpleListView 内部都是按照 DSimpleListItem 类型来处理的，sameAS 中需要用 static_cast 进行一下类型转换
    return data == (static_cast<SingleListItem*>(item))->data;
}

void SingleListItem::drawBackground(QRect rect, QPainter *painter, int index, bool isSelect)
{
    drawBackground(rect,painter,index,isSelect,false);
}

void SingleListItem::drawBackground(QRect rect, QPainter *painter, int index, bool isSelect, bool isHover)
{
    Q_UNUSED(isHover)
    // Init draw path.
    QPainterPath path;
    path.addRect(QRectF(rect));

    // Draw selected effect.
    if (isSelect) {
        painter->setOpacity(selectOpacity);
        painter->fillPath(path, QColor(selectLineColor));
    }
        // Draw background effect.
    else {
        // Use different opacity with item index.
        if (index % 2 == 0) {
            painter->setOpacity(evenLineOpacity);
            painter->fillPath(path, QColor(evenLineColor));
        } else {
            painter->setOpacity(oddLineOpacity);
            painter->fillPath(path, QColor(oddLineColor));
        }
    }
}

void SingleListItem::drawForeground(QRect rect, QPainter *painter, int column, int index, bool isSelect)
{
    drawForeground(rect,painter,column,index,isSelect,false);
}

void SingleListItem::drawForeground(QRect rect, QPainter *painter, int column, int index, bool isSelect, bool isHover)
{
    Q_UNUSED(isHover)
    Q_UNUSED(column)
    Q_UNUSED(index)
    // 当行选中时使用白色文字，没有选中时使用黑色文字
    painter->setOpacity(1);
    if (isSelect) {
        painter->setPen(QPen(QColor("#FFFFFF")));
    } else {
        painter->setPen(QPen(QColor("#000000")));
    }

    // 绘制文字，左对齐，纵向居中对齐，文字左边留10像素的空白
    int padding = 10;
    painter->drawText(QRect(rect.x() + padding, rect.y(), rect.width() - padding * 2, rect.height()), Qt::AlignLeft | Qt::AlignVCenter, data);
    if(isSelect){
        emit selected();
    }
}

void SingleListItem::changeTheme(QString) {
    initTheme();
}

void SingleListItem::initTheme() {
    if (DThemeManager::instance()->theme() == "light") {
        evenLineColor = "#000000";
        evenLineOpacity = 0.02;

        oddLineColor = "#D8D8D8";
        oddLineOpacity = 0.02;

        selectLineColor = "#2CA7F8";
        selectOpacity = 1.0;

        textColor = "#303030";
        textLeftOpacity = 1.0;
        textRightOpacity = 0.8;
    } else {
        evenLineColor = "#D8D8D8";
        evenLineOpacity = 0.02;

        oddLineColor = "#000000";
        oddLineOpacity = 0.1;

        selectLineColor = "#006BBA";
        selectOpacity = 0.8;

        textColor = "#ffffff";
        textLeftOpacity = 0.6;
        textRightOpacity = 0.5;
    }

}
