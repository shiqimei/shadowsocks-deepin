//
// Created by pikachu on 18-4-10.
//

#include "SingleListView.h"
#include "SingleListItem.h"
#include <DThemeManager>
#include "stdafx.h"
DWIDGET_USE_NAMESPACE

SingleListView::SingleListView(QWidget *parent) : DSimpleListView(parent)
{
    initTheme();

    connect(DThemeManager::instance(), &DThemeManager::themeChanged, this, &SingleListView::changeTheme);

    // Enable frame and radius.
    setFrame(true);
    setClipRadius(8);

    // Set row height.
    setRowHeight(36);
}

SingleListView::~SingleListView()
{
    qDebug()<<"SingleListView::~SingleListView()";
}

void SingleListView::changeTheme(QString theme) {
    Q_UNUSED(theme)
    initTheme();
}

void SingleListView::initTheme() {
    if (DThemeManager::instance()->theme() == "light") {
        titleColor = "#000000";
        titleLineColor = "#000000";

        titleAreaColor = "#ffffff";
        titleAreaOpacity = 0.02;

        backgroundColor = "#ffffff";
        backgroundOpacity = 0.03;

        frameColor = "#000000";
        frameOpacity = 0.1;

        searchColor = "#D0D0D0";

        arrowUpNormalImage = arrowUpLightNormalImage;
        arrowUpHoverImage = arrowUpLightHoverImage;
        arrowUpPressImage = arrowUpLightPressImage;
        arrowDownNormalImage = arrowDownLightNormalImage;
        arrowDownHoverImage = arrowDownLightHoverImage;
        arrowDownPressImage = arrowDownLightPressImage;

        scrollbarColor = "#101010";

        scrollbarNormalOpacity = 0.5;
        scrollbarHoverOpacity = 0.7;
        scrollbarPressOpacity = 0.8;

        scrollbarFrameNormalOpacity = 0;
        scrollbarFrameHoverOpacity = 0;
        scrollbarFramePressOpacity = 0;
    } else {
        titleColor = "#9A9A9A";
        titleLineColor = "#ffffff";

        titleAreaColor = "#ffffff";
        titleAreaOpacity = 0.02;

        backgroundColor = "#ffffff";
        backgroundOpacity = 0.03;

        frameColor = "#000000";
        frameOpacity = 0;

        searchColor = "#666666";

        arrowUpNormalImage = arrowUpDarkNormalImage;
        arrowUpHoverImage = arrowUpDarkHoverImage;
        arrowUpPressImage = arrowUpDarkPressImage;
        arrowDownNormalImage = arrowDownDarkNormalImage;
        arrowDownHoverImage = arrowDownDarkHoverImage;
        arrowDownPressImage = arrowDownDarkPressImage;

        scrollbarColor = "#ffffff";

        scrollbarNormalOpacity = 0.2;
        scrollbarHoverOpacity = 0.4;
        scrollbarPressOpacity = 0.15;

        scrollbarFrameNormalOpacity = 0.05;
        scrollbarFrameHoverOpacity = 0.1;
        scrollbarFramePressOpacity = 0.05;
    }
}
