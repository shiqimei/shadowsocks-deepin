#ifndef HOTKEYSETTINGSDIALOG_H
#define HOTKEYSETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
    class HotkeySettingsDialog;
}

class HotkeySettingsDialog : public QDialog {
Q_OBJECT

public:
    explicit HotkeySettingsDialog(QWidget *parent = 0);

    ~HotkeySettingsDialog();

private:
    Ui::HotkeySettingsDialog *ui;
};

#endif // HOTKEYSETTINGSDIALOG_H
