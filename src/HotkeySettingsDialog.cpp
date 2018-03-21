#include "HotkeySettingsDialog.h"
#include "ui_HotkeySettingsDialog.h"

HotkeySettingsDialog::HotkeySettingsDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::HotkeySettingsDialog) {
    ui->setupUi(this);
}

HotkeySettingsDialog::~HotkeySettingsDialog() {
    delete ui;
}
