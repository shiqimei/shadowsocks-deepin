#ifndef CONFIGDIALOG_H
#define CONFIGDIALOG_H

#include "stdafx.h"

namespace Ui {
    class ConfigDialog;
}

class ConfigDialog : public QDialog {
Q_OBJECT

public:
    explicit ConfigDialog(QWidget *parent = 0);

    ~ConfigDialog();

private slots:

    void on_listWidget_currentRowChanged(int currentRow);

private:
    Ui::ConfigDialog *ui;
    QJsonArray array;
    bool isModified;
    QJsonObject lastConfig;
    int lastPos;

    void save();

    void checkModify();

    void updateListWidget();

    void connectChanged();

    void disconnectChanged();

private slots:

    void modified();

    void on_pushButtonAdd_clicked();

    void on_pushButtonDelete_clicked();

    void on_pushButtonDuplicate_clicked();

    void on_pushButtonMoveUp_clicked();

    void on_pushButtonMoveDown_clicked();

    void on_pushButtonOK_clicked();
};

#endif // CONFIGDIALOG_H
