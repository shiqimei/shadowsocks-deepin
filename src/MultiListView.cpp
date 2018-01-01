//
// Created by pikachu on 17-12-31.
//

#include <interface/ProxyConfig.h>
#include <dao/ConfigDAO.h>
#include "MultiListView.h"
#include "MultiListItem.h"

MultiListView::MultiListView(QWidget *parent) : DSimpleListView(parent) {
    // 设置为true时绘制边框
    setFrame(true);
    // 设置边框的圆角是 8像素
    setClipRadius(8);
//    MultiListItem *item1 = new MultiListItem("Bob Dylan", "Like A Rolling Stone", "5:56");
//    MultiListItem *item2 = new MultiListItem("Neil Young", "Old Man", "4:08");
//    MultiListItem *item3 = new MultiListItem("Eric Clapton", "Tears In Heaven", "4:34");
//    MultiListItem *item4 = new MultiListItem("John Lennon", "Imagine", "3:56");
//
//    items << item1;
//    items << item2;
//    items << item3;
//    items << item4;

    auto list = ConfigDAO::instance()->findAll();
    for(auto&it:list){
        auto item = new MultiListItem(it);
        items<<item;
    }
    // 初始化标题列的名字
    QList<QString> titles;
    titles<<"remarks"<<"server"<<"status"<<"latency"<<"local_port"<<"term_usage"<<"total_usage"<<"last_used";
    // 初始化每一列的宽度，-1表示当前列自动撑开，其他数字表示固定像素值，一个列表只允许有一个自动撑开的列
    QList<int> widths;
    widths<<100;
    widths<<150;
    widths<<150;
    widths<<100;
    widths<<100;
    widths<<150;
    widths<<150;
    widths<<150;
    // 设置列表的标题、宽度和标题栏的高度
    setColumnTitleInfo(titles, widths, 36);

    addItems(items);

}