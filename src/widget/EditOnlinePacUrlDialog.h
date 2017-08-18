#ifndef EDITONLINEPACURLDIALOG_H
#define EDITONLINEPACURLDIALOG_H

#include <QDialog>

namespace Ui {
class EditOnlinePacUrlDialog;
}

class EditOnlinePacUrlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditOnlinePacUrlDialog(QString url = QString(), QWidget *parent = nullptr);
    ~EditOnlinePacUrlDialog();
    QString getOnlinePacUrl();
private:
    Ui::EditOnlinePacUrlDialog *ui;
};

#endif // EDITONLINEPACURLDIALOG_H
