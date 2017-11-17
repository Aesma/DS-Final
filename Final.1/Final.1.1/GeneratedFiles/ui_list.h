/********************************************************************************
** Form generated from reading UI file 'list.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIST_H
#define UI_LIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_listDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *listButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *listDialog)
    {
        if (listDialog->objectName().isEmpty())
            listDialog->setObjectName(QStringLiteral("listDialog"));
        listDialog->resize(348, 232);
        listDialog->setModal(true);
        gridLayout = new QGridLayout(listDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidget = new QTableWidget(listDialog);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        listButton = new QPushButton(listDialog);
        listButton->setObjectName(QStringLiteral("listButton"));

        horizontalLayout->addWidget(listButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(listDialog);

        QMetaObject::connectSlotsByName(listDialog);
    } // setupUi

    void retranslateUi(QDialog *listDialog)
    {
        listDialog->setWindowTitle(QApplication::translate("listDialog", "\351\223\276\350\241\250\345\244\215\345\210\266", 0));
        listButton->setText(QApplication::translate("listDialog", "\345\244\215\345\210\266\351\223\276\350\241\250", 0));
    } // retranslateUi

};

namespace Ui {
    class listDialog: public Ui_listDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIST_H
