/********************************************************************************
** Form generated from reading UI file 'HotkeySettingsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOTKEYSETTINGSDIALOG_H
#define UI_HOTKEYSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QKeySequenceEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_HotkeySettingsDialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QDialogButtonBox *buttonBox;
    QFormLayout *formLayout;
    QLabel *label;
    QKeySequenceEdit *keySequenceEdit;
    QLabel *label_2;
    QLabel *label_3;
    QKeySequenceEdit *keySequenceEdit_2;
    QKeySequenceEdit *keySequenceEdit_5;
    QLabel *label_4;
    QKeySequenceEdit *keySequenceEdit_3;
    QKeySequenceEdit *keySequenceEdit_4;
    QKeySequenceEdit *keySequenceEdit_6;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *HotkeySettingsDialog)
    {
        if (HotkeySettingsDialog->objectName().isEmpty())
            HotkeySettingsDialog->setObjectName(QStringLiteral("HotkeySettingsDialog"));
        HotkeySettingsDialog->resize(427, 269);
        gridLayout = new QGridLayout(HotkeySettingsDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(HotkeySettingsDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(HotkeySettingsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(HotkeySettingsDialog);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        keySequenceEdit = new QKeySequenceEdit(HotkeySettingsDialog);
        keySequenceEdit->setObjectName(QStringLiteral("keySequenceEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, keySequenceEdit);

        label_2 = new QLabel(HotkeySettingsDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(HotkeySettingsDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        keySequenceEdit_2 = new QKeySequenceEdit(HotkeySettingsDialog);
        keySequenceEdit_2->setObjectName(QStringLiteral("keySequenceEdit_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, keySequenceEdit_2);

        keySequenceEdit_5 = new QKeySequenceEdit(HotkeySettingsDialog);
        keySequenceEdit_5->setObjectName(QStringLiteral("keySequenceEdit_5"));

        formLayout->setWidget(2, QFormLayout::FieldRole, keySequenceEdit_5);

        label_4 = new QLabel(HotkeySettingsDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        keySequenceEdit_3 = new QKeySequenceEdit(HotkeySettingsDialog);
        keySequenceEdit_3->setObjectName(QStringLiteral("keySequenceEdit_3"));

        formLayout->setWidget(3, QFormLayout::FieldRole, keySequenceEdit_3);

        keySequenceEdit_4 = new QKeySequenceEdit(HotkeySettingsDialog);
        keySequenceEdit_4->setObjectName(QStringLiteral("keySequenceEdit_4"));

        formLayout->setWidget(4, QFormLayout::FieldRole, keySequenceEdit_4);

        keySequenceEdit_6 = new QKeySequenceEdit(HotkeySettingsDialog);
        keySequenceEdit_6->setObjectName(QStringLiteral("keySequenceEdit_6"));

        formLayout->setWidget(5, QFormLayout::FieldRole, keySequenceEdit_6);

        label_5 = new QLabel(HotkeySettingsDialog);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(HotkeySettingsDialog);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);


        gridLayout->addLayout(formLayout, 0, 0, 1, 2);


        retranslateUi(HotkeySettingsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), HotkeySettingsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), HotkeySettingsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(HotkeySettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *HotkeySettingsDialog)
    {
        HotkeySettingsDialog->setWindowTitle(QApplication::translate("HotkeySettingsDialog", "Dialog", 0));
        pushButton->setText(QApplication::translate("HotkeySettingsDialog", "Reg All", 0));
        label->setText(QApplication::translate("HotkeySettingsDialog", "Switch system proxy", 0));
        label_2->setText(QApplication::translate("HotkeySettingsDialog", "Switch system proxy mode", 0));
        label_3->setText(QApplication::translate("HotkeySettingsDialog", "Switch share over LAN", 0));
        label_4->setText(QApplication::translate("HotkeySettingsDialog", "Show Logs", 0));
        label_5->setText(QApplication::translate("HotkeySettingsDialog", "Switch to prev server", 0));
        label_6->setText(QApplication::translate("HotkeySettingsDialog", "Switch to next server", 0));
    } // retranslateUi

};

namespace Ui {
    class HotkeySettingsDialog: public Ui_HotkeySettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOTKEYSETTINGSDIALOG_H
