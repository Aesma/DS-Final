/********************************************************************************
** Form generated from reading UI file 'disk.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISK_H
#define UI_DISK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_diskDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *inButton;
    QLineEdit *lineEdit;
    QPushButton *doButton;

    void setupUi(QDialog *diskDialog)
    {
        if (diskDialog->objectName().isEmpty())
            diskDialog->setObjectName(QStringLiteral("diskDialog"));
        diskDialog->resize(399, 97);
        diskDialog->setModal(true);
        gridLayout = new QGridLayout(diskDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        inButton = new QPushButton(diskDialog);
        inButton->setObjectName(QStringLiteral("inButton"));

        horizontalLayout->addWidget(inButton);

        lineEdit = new QLineEdit(diskDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        doButton = new QPushButton(diskDialog);
        doButton->setObjectName(QStringLiteral("doButton"));

        verticalLayout->addWidget(doButton);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(diskDialog);

        QMetaObject::connectSlotsByName(diskDialog);
    } // setupUi

    void retranslateUi(QDialog *diskDialog)
    {
        diskDialog->setWindowTitle(QApplication::translate("diskDialog", "Dialog", 0));
        inButton->setText(QApplication::translate("diskDialog", "\346\211\223\345\274\200\346\226\207\344\273\266", 0));
        doButton->setText(QApplication::translate("diskDialog", "\346\225\264\347\220\206\347\243\201\347\233\230\347\242\216\347\211\207", 0));
    } // retranslateUi

};

namespace Ui {
    class diskDialog: public Ui_diskDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISK_H
