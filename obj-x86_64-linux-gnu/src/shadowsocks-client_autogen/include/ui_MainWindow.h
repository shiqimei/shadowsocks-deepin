/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionEnable_System_Proxy;
    QAction *actionPAC;
    QAction *actionGlobal;
    QAction *actionEdit_Servers;
    QAction *actionStatistics_Config;
    QAction *actionStart_on_Boot;
    QAction *actionForward_Proxy;
    QAction *actionAllow_Clients_from_LAN;
    QAction *actionLocal_PAC;
    QAction *actionOnline_PAC;
    QAction *actionEdit_Local_PAC_File;
    QAction *actionUpdate_Local_PAC_from_GFWList;
    QAction *action_Edit_User_Rule_for_GFWList;
    QAction *actionSecure_Local_PAC;
    QAction *actionCopy_Local_PAC_URL;
    QAction *actionShare_Server_Config;
    QAction *actionScan_QRCode_from_Screen;
    QAction *actionImport_URL_from_Clipboard;
    QAction *actionAvailability_Statistics;
    QAction *actionShow_Logs;
    QAction *actionVerbose_Logging;
    QAction *actionCheck_for_Updates;
    QAction *actionCheck_for_Updates_at_Startup;
    QAction *actionCheck_Pre_release_Version;
    QAction *actionEdit_Hotkeys;
    QAction *actionAbout;
    QAction *actionQuit;
    QAction *actionLoad_Balance;
    QAction *actionHigh_Availability;
    QAction *actionChoose_by_statistics;
    QAction *actionEdit_Online_PAC_URL;
    QAction *actionImport_from_gui_config_json;
    QAction *actionExport_as_gui_config_json;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QMenu *menuTray;
    QMenu *menuMode;
    QMenu *menuServers;
    QMenu *menuPAC;
    QMenu *menuHelp;
    QMenu *menuUpdates;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(782, 445);
        actionEnable_System_Proxy = new QAction(MainWindow);
        actionEnable_System_Proxy->setObjectName(QStringLiteral("actionEnable_System_Proxy"));
        actionEnable_System_Proxy->setCheckable(true);
        actionPAC = new QAction(MainWindow);
        actionPAC->setObjectName(QStringLiteral("actionPAC"));
        actionPAC->setCheckable(true);
        actionGlobal = new QAction(MainWindow);
        actionGlobal->setObjectName(QStringLiteral("actionGlobal"));
        actionGlobal->setCheckable(true);
        actionEdit_Servers = new QAction(MainWindow);
        actionEdit_Servers->setObjectName(QStringLiteral("actionEdit_Servers"));
        actionStatistics_Config = new QAction(MainWindow);
        actionStatistics_Config->setObjectName(QStringLiteral("actionStatistics_Config"));
        actionStatistics_Config->setVisible(false);
        actionStart_on_Boot = new QAction(MainWindow);
        actionStart_on_Boot->setObjectName(QStringLiteral("actionStart_on_Boot"));
        actionStart_on_Boot->setCheckable(true);
        actionForward_Proxy = new QAction(MainWindow);
        actionForward_Proxy->setObjectName(QStringLiteral("actionForward_Proxy"));
        actionForward_Proxy->setVisible(false);
        actionAllow_Clients_from_LAN = new QAction(MainWindow);
        actionAllow_Clients_from_LAN->setObjectName(QStringLiteral("actionAllow_Clients_from_LAN"));
        actionAllow_Clients_from_LAN->setVisible(false);
        actionLocal_PAC = new QAction(MainWindow);
        actionLocal_PAC->setObjectName(QStringLiteral("actionLocal_PAC"));
        actionLocal_PAC->setCheckable(true);
        actionOnline_PAC = new QAction(MainWindow);
        actionOnline_PAC->setObjectName(QStringLiteral("actionOnline_PAC"));
        actionOnline_PAC->setCheckable(true);
        actionEdit_Local_PAC_File = new QAction(MainWindow);
        actionEdit_Local_PAC_File->setObjectName(QStringLiteral("actionEdit_Local_PAC_File"));
        actionUpdate_Local_PAC_from_GFWList = new QAction(MainWindow);
        actionUpdate_Local_PAC_from_GFWList->setObjectName(QStringLiteral("actionUpdate_Local_PAC_from_GFWList"));
        action_Edit_User_Rule_for_GFWList = new QAction(MainWindow);
        action_Edit_User_Rule_for_GFWList->setObjectName(QStringLiteral("action_Edit_User_Rule_for_GFWList"));
        actionSecure_Local_PAC = new QAction(MainWindow);
        actionSecure_Local_PAC->setObjectName(QStringLiteral("actionSecure_Local_PAC"));
        actionSecure_Local_PAC->setCheckable(true);
        actionCopy_Local_PAC_URL = new QAction(MainWindow);
        actionCopy_Local_PAC_URL->setObjectName(QStringLiteral("actionCopy_Local_PAC_URL"));
        actionShare_Server_Config = new QAction(MainWindow);
        actionShare_Server_Config->setObjectName(QStringLiteral("actionShare_Server_Config"));
        actionShare_Server_Config->setVisible(true);
        actionScan_QRCode_from_Screen = new QAction(MainWindow);
        actionScan_QRCode_from_Screen->setObjectName(QStringLiteral("actionScan_QRCode_from_Screen"));
        actionScan_QRCode_from_Screen->setVisible(true);
        actionImport_URL_from_Clipboard = new QAction(MainWindow);
        actionImport_URL_from_Clipboard->setObjectName(QStringLiteral("actionImport_URL_from_Clipboard"));
        actionImport_URL_from_Clipboard->setVisible(true);
        actionAvailability_Statistics = new QAction(MainWindow);
        actionAvailability_Statistics->setObjectName(QStringLiteral("actionAvailability_Statistics"));
        actionAvailability_Statistics->setVisible(false);
        actionShow_Logs = new QAction(MainWindow);
        actionShow_Logs->setObjectName(QStringLiteral("actionShow_Logs"));
        actionVerbose_Logging = new QAction(MainWindow);
        actionVerbose_Logging->setObjectName(QStringLiteral("actionVerbose_Logging"));
        actionCheck_for_Updates = new QAction(MainWindow);
        actionCheck_for_Updates->setObjectName(QStringLiteral("actionCheck_for_Updates"));
        actionCheck_for_Updates_at_Startup = new QAction(MainWindow);
        actionCheck_for_Updates_at_Startup->setObjectName(QStringLiteral("actionCheck_for_Updates_at_Startup"));
        actionCheck_Pre_release_Version = new QAction(MainWindow);
        actionCheck_Pre_release_Version->setObjectName(QStringLiteral("actionCheck_Pre_release_Version"));
        actionEdit_Hotkeys = new QAction(MainWindow);
        actionEdit_Hotkeys->setObjectName(QStringLiteral("actionEdit_Hotkeys"));
        actionEdit_Hotkeys->setVisible(false);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionLoad_Balance = new QAction(MainWindow);
        actionLoad_Balance->setObjectName(QStringLiteral("actionLoad_Balance"));
        actionLoad_Balance->setVisible(false);
        actionHigh_Availability = new QAction(MainWindow);
        actionHigh_Availability->setObjectName(QStringLiteral("actionHigh_Availability"));
        actionHigh_Availability->setVisible(false);
        actionChoose_by_statistics = new QAction(MainWindow);
        actionChoose_by_statistics->setObjectName(QStringLiteral("actionChoose_by_statistics"));
        actionChoose_by_statistics->setVisible(false);
        actionEdit_Online_PAC_URL = new QAction(MainWindow);
        actionEdit_Online_PAC_URL->setObjectName(QStringLiteral("actionEdit_Online_PAC_URL"));
        actionImport_from_gui_config_json = new QAction(MainWindow);
        actionImport_from_gui_config_json->setObjectName(QStringLiteral("actionImport_from_gui_config_json"));
        actionExport_as_gui_config_json = new QAction(MainWindow);
        actionExport_as_gui_config_json->setObjectName(QStringLiteral("actionExport_as_gui_config_json"));
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        menuTray = new QMenu(MainWindow);
        menuTray->setObjectName(QStringLiteral("menuTray"));
        menuMode = new QMenu(menuTray);
        menuMode->setObjectName(QStringLiteral("menuMode"));
        menuServers = new QMenu(menuTray);
        menuServers->setObjectName(QStringLiteral("menuServers"));
        menuPAC = new QMenu(menuTray);
        menuPAC->setObjectName(QStringLiteral("menuPAC"));
        menuHelp = new QMenu(menuTray);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuHelp->setToolTipsVisible(false);
        menuUpdates = new QMenu(menuHelp);
        menuUpdates->setObjectName(QStringLiteral("menuUpdates"));
        MainWindow->setCentralWidget(menuTray);

        menuTray->addAction(actionEnable_System_Proxy);
        menuTray->addAction(menuMode->menuAction());
        menuTray->addAction(menuServers->menuAction());
        menuTray->addAction(menuPAC->menuAction());
        menuTray->addAction(actionForward_Proxy);
        menuTray->addSeparator();
        menuTray->addAction(actionStart_on_Boot);
        menuTray->addAction(actionAllow_Clients_from_LAN);
        menuTray->addSeparator();
        menuTray->addAction(actionEdit_Hotkeys);
        menuTray->addAction(menuHelp->menuAction());
        menuTray->addSeparator();
        menuTray->addAction(actionQuit);
        menuMode->addAction(actionPAC);
        menuMode->addAction(actionGlobal);
        menuServers->addAction(actionLoad_Balance);
        menuServers->addAction(actionHigh_Availability);
        menuServers->addAction(actionChoose_by_statistics);
        menuServers->addAction(actionAvailability_Statistics);
        menuServers->addSeparator();
        menuServers->addAction(actionEdit_Servers);
        menuServers->addAction(actionStatistics_Config);
        menuServers->addSeparator();
        menuServers->addAction(actionShare_Server_Config);
        menuServers->addAction(actionScan_QRCode_from_Screen);
        menuServers->addAction(actionImport_URL_from_Clipboard);
        menuPAC->addAction(actionLocal_PAC);
        menuPAC->addAction(actionOnline_PAC);
        menuPAC->addSeparator();
        menuPAC->addAction(actionEdit_Local_PAC_File);
        menuPAC->addAction(actionUpdate_Local_PAC_from_GFWList);
        menuPAC->addAction(action_Edit_User_Rule_for_GFWList);
        menuPAC->addAction(actionSecure_Local_PAC);
        menuPAC->addAction(actionCopy_Local_PAC_URL);
        menuPAC->addAction(actionEdit_Online_PAC_URL);
        menuHelp->addAction(actionShow_Logs);
        menuHelp->addAction(actionVerbose_Logging);
        menuHelp->addAction(menuUpdates->menuAction());
        menuHelp->addAction(actionAbout);
        menuUpdates->addAction(actionCheck_for_Updates);
        menuUpdates->addSeparator();
        menuUpdates->addAction(actionCheck_for_Updates_at_Startup);
        menuUpdates->addAction(actionCheck_Pre_release_Version);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionEnable_System_Proxy->setText(QApplication::translate("MainWindow", "Enable System Proxy", 0));
        actionPAC->setText(QApplication::translate("MainWindow", "PAC", 0));
        actionGlobal->setText(QApplication::translate("MainWindow", "Global", 0));
        actionEdit_Servers->setText(QApplication::translate("MainWindow", "Edit Servers...", 0));
        actionStatistics_Config->setText(QApplication::translate("MainWindow", "Statistics Config...", 0));
        actionStart_on_Boot->setText(QApplication::translate("MainWindow", "Start on Boot", 0));
        actionForward_Proxy->setText(QApplication::translate("MainWindow", "Forward Proxy...", 0));
        actionAllow_Clients_from_LAN->setText(QApplication::translate("MainWindow", "Allow Clients from LAN", 0));
        actionLocal_PAC->setText(QApplication::translate("MainWindow", "Local PAC", 0));
        actionOnline_PAC->setText(QApplication::translate("MainWindow", "Online PAC", 0));
        actionEdit_Local_PAC_File->setText(QApplication::translate("MainWindow", "Edit Local PAC File...", 0));
        actionUpdate_Local_PAC_from_GFWList->setText(QApplication::translate("MainWindow", "Update Local PAC from GFWList", 0));
        action_Edit_User_Rule_for_GFWList->setText(QApplication::translate("MainWindow", "\n"
"Edit User Rule for GFWList...", 0));
        actionSecure_Local_PAC->setText(QApplication::translate("MainWindow", "Secure Local PAC", 0));
        actionCopy_Local_PAC_URL->setText(QApplication::translate("MainWindow", "Copy Local PAC URL", 0));
        actionShare_Server_Config->setText(QApplication::translate("MainWindow", "Share Server Config...", 0));
        actionScan_QRCode_from_Screen->setText(QApplication::translate("MainWindow", "Scan QRCode from Screen...", 0));
        actionImport_URL_from_Clipboard->setText(QApplication::translate("MainWindow", "Import URL from Clipboard...", 0));
        actionAvailability_Statistics->setText(QApplication::translate("MainWindow", "Availability Statistics", 0));
        actionShow_Logs->setText(QApplication::translate("MainWindow", "Show Logs...", 0));
        actionVerbose_Logging->setText(QApplication::translate("MainWindow", "Verbose Logging", 0));
        actionCheck_for_Updates->setText(QApplication::translate("MainWindow", "Check for Updates...", 0));
        actionCheck_for_Updates_at_Startup->setText(QApplication::translate("MainWindow", "Check for Updates at Startup", 0));
        actionCheck_Pre_release_Version->setText(QApplication::translate("MainWindow", "Check Pre-release Version", 0));
        actionEdit_Hotkeys->setText(QApplication::translate("MainWindow", "Edit Hotkeys...", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About...", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        actionLoad_Balance->setText(QApplication::translate("MainWindow", "Load Balance", 0));
        actionHigh_Availability->setText(QApplication::translate("MainWindow", "High Availability", 0));
        actionChoose_by_statistics->setText(QApplication::translate("MainWindow", "Choose by statistics", 0));
        actionEdit_Online_PAC_URL->setText(QApplication::translate("MainWindow", "Edit Online PAC URL...", 0));
        actionImport_from_gui_config_json->setText(QApplication::translate("MainWindow", "Import from gui-config.json", 0));
        actionExport_as_gui_config_json->setText(QApplication::translate("MainWindow", "Export as gui-config.json", 0));
        actionConnect->setText(QApplication::translate("MainWindow", "Connect", 0));
        actionDisconnect->setText(QApplication::translate("MainWindow", "Disconnect", 0));
        menuTray->setTitle(QApplication::translate("MainWindow", "Tray", 0));
        menuMode->setTitle(QApplication::translate("MainWindow", "Mode", 0));
        menuServers->setTitle(QApplication::translate("MainWindow", "Servers", 0));
        menuPAC->setTitle(QApplication::translate("MainWindow", "PAC", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
        menuUpdates->setTitle(QApplication::translate("MainWindow", "Updates...", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
