//
// Created by pikachu on 18-1-1.
//

#include <DThemeManager>
#include "SingleListItem.h"
DWIDGET_USE_NAMESPACE

SingleListItem::SingleListItem(QString itemName)
{
    initTheme();
    // 初始化文本属性
    name = itemName;
}

bool SingleListItem::sameAs(DSimpleListItem *item)
{
    // 根据两个Item的属性来判断两个Item是否是相同的？
    // DSimpleListView 内部都是按照 DSimpleListItem 类型来处理的，sameAS 中需要用 static_cast 进行一下类型转换
    return name == (static_cast<SingleListItem*>(item))->name;
}

void SingleListItem::drawBackground(QRect rect, QPainter *painter, int index, bool isSelect)
{
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
    // 当行选中时使用白色文字，没有选中时使用黑色文字
    painter->setOpacity(1);
    if (isSelect) {
        painter->setPen(QPen(QColor("#FFFFFF")));
    } else {
        painter->setPen(QPen(QColor("#000000")));
    }

    // 绘制文字，左对齐，纵向居中对齐，文字左边留10像素的空白
    int padding = 10;
    painter->drawText(QRect(rect.x() + padding, rect.y(), rect.width() - padding * 2, rect.height()), Qt::AlignLeft | Qt::AlignVCenter, name);
}

void SingleListItem::changeTheme(QString theme) {
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

    } else {
        evenLineColor = "#D8D8D8";
        evenLineOpacity = 0.02;

        oddLineColor = "#000000";
        oddLineOpacity = 0.1;

        selectLineColor = "#006BBA";
        selectOpacity = 0.8;

    }
}

SingleListItem::SingleListItem(ProxyConfig *config) {
    initTheme();
    this->config = config;
    QString remarks = config->property("remarks").toString();
    if(remarks.isEmpty()){
        this->name = config->property("server").toString();
    } else{
        this->name = remarks;
    }
}
