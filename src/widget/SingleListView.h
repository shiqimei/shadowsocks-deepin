//
// Created by pikachu on 18-1-1.
//

#ifndef SHADOWSOCKS_CLIENT_SINGLELISTVIEW_H
#define SHADOWSOCKS_CLIENT_SINGLELISTVIEW_H

#include "stdafx.h"
#include <DSimpleListView>
DWIDGET_USE_NAMESPACE  // 这句话主要强调使用 dtkwidget 的命名空间，以使用其控件

class SingleListView : public DSimpleListView
{
    Q_OBJECT
protected:
    QString scrollbarColor = "#000000";
public:
    SingleListView(DSimpleListView *parent=0);
};


#endif //SHADOWSOCKS_CLIENT_SINGLELISTVIEW_H
