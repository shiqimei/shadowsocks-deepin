//
// Created by pikachu on 18-1-1.
//

#include "SingleListView.h"
#include "SingleListItem.h"

DWIDGET_USE_NAMESPACE

SingleListView::SingleListView(DSimpleListView *parent) : DSimpleListView(parent)
{
    // 设置为true时绘制边框
    setFrame(true);
    // 设置边框的圆角是 8像素
    setClipRadius(8);
    QStringList rockStars;
    rockStars << "Bob Dylan" << "Neil Young" << "Eric Clapton" << "John Lennon";
    for (int i = 0; i < 100; ++i) {
        rockStars << "pikachu"+QString::number(i);
    }
    QList<DSimpleListItem*> items;
    for (auto rockStarName : rockStars){
        SingleListItem *item = new SingleListItem(rockStarName);
        items << item;
    }

    addItems(items);
}
