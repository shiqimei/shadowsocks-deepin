#include "EditHotkeysDialog.h"
#include "ui_EditHotkeysDialog.h"
#include <util/Util.h>

EditHotkeysDialog::EditHotkeysDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::EditHotkeysDialog) {
    ui->setupUi(this);
    setLayout(ui->gridLayout);
    auto &hotkey = Util::guiConfig.hotkey;
    ui->keySequenceEditSwitchSystemProxy->setKeySequence(QKeySequence(hotkey.switchSystemProxy));
    ui->keySequenceEditSwitchSystemProxyMode->setKeySequence(QKeySequence(hotkey.switchSystemProxyMode));
    ui->keySequenceEditShowLogs->setKeySequence(QKeySequence(hotkey.showLogs));
    ui->keySequenceEditSwitchShareOverLAN->setKeySequence(QKeySequence(hotkey.switchAllowLan));
    ui->keySequenceEditSwitchToPrevServer->setKeySequence(QKeySequence(hotkey.serverMoveUp));
    ui->keySequenceEditSwitchToNextServer->setKeySequence(QKeySequence(hotkey.serverMoveDown));
    list << ui->keySequenceEditSwitchSystemProxy << ui->keySequenceEditSwitchSystemProxyMode
         << ui->keySequenceEditShowLogs
         << ui->keySequenceEditSwitchShareOverLAN << ui->keySequenceEditSwitchToNextServer
         << ui->keySequenceEditSwitchToPrevServer;
    for (auto it:list) {
        connect(it, &QKeySequenceEdit::editingFinished, this, &EditHotkeysDialog::isValid);
    }
}

EditHotkeysDialog::~EditHotkeysDialog() {
    delete ui;
}


bool EditHotkeysDialog::on_pushButtonRegAll_clicked() {
    if (!isValid()) {
        QMessageBox::critical(nullptr, tr("Register Hotkey Fail"), tr("Hotkey Conflick"));
        return false;
    }
    auto &hotkey = Util::guiConfig.hotkey;
    hotkey.switchSystemProxy = ui->keySequenceEditSwitchSystemProxy->keySequence().toString();
    hotkey.switchSystemProxyMode = ui->keySequenceEditSwitchSystemProxyMode->keySequence().toString();
    hotkey.showLogs = ui->keySequenceEditShowLogs->keySequence().toString();
    hotkey.switchAllowLan = ui->keySequenceEditSwitchShareOverLAN->keySequence().toString();
    hotkey.serverMoveDown = ui->keySequenceEditSwitchToNextServer->keySequence().toString();
    hotkey.serverMoveUp = ui->keySequenceEditSwitchToPrevServer->keySequence().toString();
    Util::saveConfig();
    return true;
}

bool EditHotkeysDialog::isValid() const {

    QMap<QString, QKeySequenceEdit *> map;
    for (auto it:list) {
        it->setStyleSheet(QString("color:black"));
        const QString &string = it->keySequence().toString();
        if (string.isEmpty()) {
            continue;
        }
        if (map.contains(string)) {
            it->setStatusTip(tr("Hotkey Conflick"));
            it->setStyleSheet(QString("color:red"));
            map.value(string)->setStyleSheet(QString("color:red"));
//            QMessageBox::critical(nullptr, tr("Register Hotkey Fail"), tr("Hotkey Conflick : %1").arg(string));
            return false;
        }
        map.insert(string, it);
    }
    return true;
}

void EditHotkeysDialog::on_pushButtonCancel_clicked() {
    reject();
}

void EditHotkeysDialog::on_pushButtonConfirm_clicked() {
    auto ok=on_pushButtonRegAll_clicked();
    if(ok){
        accept();
    }
}
