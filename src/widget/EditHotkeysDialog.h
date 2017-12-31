#ifndef EDITHOTKEYSDIALOG_H
#define EDITHOTKEYSDIALOG_H

#include "stdafx.h"
namespace Ui {
class EditHotkeysDialog;
}

class EditHotkeysDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditHotkeysDialog(QWidget *parent = 0);
    ~EditHotkeysDialog();

private slots:
    bool on_pushButtonRegAll_clicked();

    void on_pushButtonCancel_clicked();

    void on_pushButtonConfirm_clicked();

private:
    Ui::EditHotkeysDialog *ui;
    QList<QKeySequenceEdit*> list;

    bool isValid() const;
};

#endif // EDITHOTKEYSDIALOG_H
