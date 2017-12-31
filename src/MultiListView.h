//
// Created by pikachu on 17-12-31.
//

#ifndef SHADOWSOCKS_CLIENT_MULTILISTVIEW_H
#define SHADOWSOCKS_CLIENT_MULTILISTVIEW_H

#include "stdafx.h"
#include <DSimpleListView>
DWIDGET_USE_NAMESPACE
class MultiListView : public DSimpleListView{
Q_OBJECT
public:
    MultiListView(QWidget* parent = nullptr);
};


#endif //SHADOWSOCKS_CLIENT_MULTILISTVIEW_H
