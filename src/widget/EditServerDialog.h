#ifndef EDITSERVERDIALOG_H
#define EDITSERVERDIALOG_H

#include "common/common.h"
#include <profile.h>

using QSS::Profile;
namespace Ui {
class EditServerDialog;
}
class EditServerDialog : public QDialog
{
    Q_OBJECT

    EditServerDialog(QWidget *parent);

public:
    explicit EditServerDialog(bool isNew= false, QWidget *parent= nullptr);

    ~EditServerDialog() override;

private slots:
    void on_addPushButton_clicked();
    void onListWidgetChange();
    void on_removePushButton_clicked();

    void on_copyPushButton_clicked();

    void on_upPushButton_clicked();

    void on_downPushButton_clicked();

    void on_pushButtonTestLatency_clicked();

    void onConnectionItem_latencyChanged();
private:
    Ui::EditServerDialog *ui;
    void setFormEnabled(bool flag);

    QDataWidgetMapper *mapper;
};

#endif // EDITSERVERDIALOG_H
