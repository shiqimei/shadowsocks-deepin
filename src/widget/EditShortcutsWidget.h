//
// Created by pikachu on 17-8-6.
//

#ifndef SHADOWSOCKS_CLIENT_EDITSHORTCUTSWIDGET_H
#define SHADOWSOCKS_CLIENT_EDITSHORTCUTSWIDGET_H

#include <QObject>
#include <QWidget>
#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QDialog>
class EditShortcutsWidget : public QDialog {
public:
    explicit EditShortcutsWidget(QWidget *parent= nullptr);

private:

    QPushButton* pushButtonRegisterAllShortcuts;
    QPushButton* pushButtonCancel;
    QPushButton* pushButtonConfirm;
};


#endif //SHADOWSOCKS_CLIENT_EDITSHORTCUTSWIDGET_H
