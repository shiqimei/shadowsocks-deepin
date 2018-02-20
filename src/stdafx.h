#ifndef STDAFX_H
#define STDAFX_H

#include <QtCore>
#include <QtGui>
#include <QtWidgets>

#include <DApplication>
#include <DMainWindow>
#include <DWidgetUtil>
#include <DHiDPIHelper>
#include <DSingleton>
#include <DTitlebar>
#include <DLog>
#include <DSimpleListItem>
#include <DSimpleListView>
#include <dsearchedit.h>
#include <dthememanager.h>
#include <ddialog.h>

#include <iostream>
#include <sys/types.h>
#include <thread>
#include <unistd.h>
#include <csignal>

#include <QtShadowsocks>

namespace Constant {
    const int WINDOW_MIN_WIDTH = 900;
    const int WINDOW_MIN_HEIGHT = 620;
};
#endif // STDAFX_H
