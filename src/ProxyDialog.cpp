#include "ProxyDialog.h"
#include "ui_ProxyDialog.h"

ProxyDialog::ProxyDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::ProxyDialog) {
    ui->setupUi(this);

}

ProxyDialog::~ProxyDialog() {
    delete ui;
}
