#include "PACUrlDialog.h"
#include "ui_PACUrlDialog.h"

PACUrlDialog::PACUrlDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::PACUrlDialog) {
    ui->setupUi(this);
}

PACUrlDialog::~PACUrlDialog() {
    delete ui;
}
