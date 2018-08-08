/********************************************************************************
** Form generated from reading UI file 'PACUrlDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PACURLDIALOG_H
#define UI_PACURLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_PACUrlDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;

    void setupUi(QDialog *PACUrlDialog)
    {
        if (PACUrlDialog->objectName().isEmpty())
            PACUrlDialog->setObjectName(QStringLiteral("PACUrlDialog"));
        PACUrlDialog->resize(400, 128);
        gridLayout = new QGridLayout(PACUrlDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(PACUrlDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(PACUrlDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 0, 1, 1, 1);

        lineEdit = new QLineEdit(PACUrlDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 2);


        retranslateUi(PACUrlDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PACUrlDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PACUrlDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PACUrlDialog);
    } // setupUi

    void retranslateUi(QDialog *PACUrlDialog)
    {
        PACUrlDialog->setWindowTitle(QApplication::translate("PACUrlDialog", "Dialog", 0));
        label->setText(QApplication::translate("PACUrlDialog", "Please input PAC Url", 0));
    } // retranslateUi

};

namespace Ui {
    class PACUrlDialog: public Ui_PACUrlDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PACURLDIALOG_H
