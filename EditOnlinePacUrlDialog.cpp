#include "EditOnlinePacUrlDialog.h"
#include "ui_EditOnlinePacUrlDialog.h"

EditOnlinePacUrlDialog::EditOnlinePacUrlDialog(QString url, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditOnlinePacUrlDialog)
{
    ui->setupUi(this);
    setLayout(ui->gridLayout);
    ui->lineEdit->setText(url);
}

EditOnlinePacUrlDialog::~EditOnlinePacUrlDialog()
{
    delete ui;
}

QString EditOnlinePacUrlDialog::getOnlinePacUrl() {
    return ui->lineEdit->text();
}
