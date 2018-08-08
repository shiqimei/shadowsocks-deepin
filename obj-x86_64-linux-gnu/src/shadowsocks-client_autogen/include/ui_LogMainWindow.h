/********************************************************************************
** Form generated from reading UI file 'LogMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGMAINWINDOW_H
#define UI_LOGMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogMainWindow
{
public:
    QAction *action_Open_Location;
    QAction *actionE_xit;
    QAction *action_Clean_Logs;
    QAction *actionChange_Font;
    QAction *action_Wrap_Text;
    QAction *action_Top_Most;
    QAction *action_Show_Toolbar;
    QWidget *centralwidget;
    QPushButton *pushButtonCleanLogs;
    QPushButton *pushButtonChangeFont;
    QCheckBox *checkBoxWrapText;
    QCheckBox *checkBoxTopMost;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menu_View;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LogMainWindow)
    {
        if (LogMainWindow->objectName().isEmpty())
            LogMainWindow->setObjectName(QStringLiteral("LogMainWindow"));
        LogMainWindow->resize(800, 600);
        action_Open_Location = new QAction(LogMainWindow);
        action_Open_Location->setObjectName(QStringLiteral("action_Open_Location"));
        actionE_xit = new QAction(LogMainWindow);
        actionE_xit->setObjectName(QStringLiteral("actionE_xit"));
        action_Clean_Logs = new QAction(LogMainWindow);
        action_Clean_Logs->setObjectName(QStringLiteral("action_Clean_Logs"));
        actionChange_Font = new QAction(LogMainWindow);
        actionChange_Font->setObjectName(QStringLiteral("actionChange_Font"));
        action_Wrap_Text = new QAction(LogMainWindow);
        action_Wrap_Text->setObjectName(QStringLiteral("action_Wrap_Text"));
        action_Top_Most = new QAction(LogMainWindow);
        action_Top_Most->setObjectName(QStringLiteral("action_Top_Most"));
        action_Show_Toolbar = new QAction(LogMainWindow);
        action_Show_Toolbar->setObjectName(QStringLiteral("action_Show_Toolbar"));
        centralwidget = new QWidget(LogMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButtonCleanLogs = new QPushButton(centralwidget);
        pushButtonCleanLogs->setObjectName(QStringLiteral("pushButtonCleanLogs"));
        pushButtonCleanLogs->setGeometry(QRect(21, 11, 85, 30));
        pushButtonChangeFont = new QPushButton(centralwidget);
        pushButtonChangeFont->setObjectName(QStringLiteral("pushButtonChangeFont"));
        pushButtonChangeFont->setGeometry(QRect(112, 11, 91, 30));
        checkBoxWrapText = new QCheckBox(centralwidget);
        checkBoxWrapText->setObjectName(QStringLiteral("checkBoxWrapText"));
        checkBoxWrapText->setGeometry(QRect(209, 14, 85, 23));
        checkBoxTopMost = new QCheckBox(centralwidget);
        checkBoxTopMost->setObjectName(QStringLiteral("checkBoxTopMost"));
        checkBoxTopMost->setGeometry(QRect(300, 14, 81, 23));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(30, 70, 731, 201));
        LogMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LogMainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_View = new QMenu(menubar);
        menu_View->setObjectName(QStringLiteral("menu_View"));
        LogMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LogMainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        LogMainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_File->menuAction());
        menubar->addAction(menu_View->menuAction());
        menu_File->addAction(action_Open_Location);
        menu_File->addAction(actionE_xit);
        menu_View->addAction(action_Clean_Logs);
        menu_View->addAction(actionChange_Font);
        menu_View->addAction(action_Wrap_Text);
        menu_View->addAction(action_Top_Most);
        menu_View->addSeparator();
        menu_View->addAction(action_Show_Toolbar);

        retranslateUi(LogMainWindow);

        QMetaObject::connectSlotsByName(LogMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LogMainWindow)
    {
        LogMainWindow->setWindowTitle(QApplication::translate("LogMainWindow", "MainWindow", 0));
        action_Open_Location->setText(QApplication::translate("LogMainWindow", "&Open Location", 0));
        actionE_xit->setText(QApplication::translate("LogMainWindow", "E&xit", 0));
        action_Clean_Logs->setText(QApplication::translate("LogMainWindow", "&Clean Logs", 0));
        actionChange_Font->setText(QApplication::translate("LogMainWindow", "Change &Font", 0));
        action_Wrap_Text->setText(QApplication::translate("LogMainWindow", "&Wrap Text", 0));
        action_Top_Most->setText(QApplication::translate("LogMainWindow", "&Top Most", 0));
        action_Show_Toolbar->setText(QApplication::translate("LogMainWindow", "&Show Toolbar", 0));
        pushButtonCleanLogs->setText(QApplication::translate("LogMainWindow", "&Clean Logs", 0));
        pushButtonChangeFont->setText(QApplication::translate("LogMainWindow", "Change &Font", 0));
        checkBoxWrapText->setText(QApplication::translate("LogMainWindow", "&Wrap Text", 0));
        checkBoxTopMost->setText(QApplication::translate("LogMainWindow", "&Top Most", 0));
        menu_File->setTitle(QApplication::translate("LogMainWindow", "&File", 0));
        menu_View->setTitle(QApplication::translate("LogMainWindow", "&View", 0));
    } // retranslateUi

};

namespace Ui {
    class LogMainWindow: public Ui_LogMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGMAINWINDOW_H
