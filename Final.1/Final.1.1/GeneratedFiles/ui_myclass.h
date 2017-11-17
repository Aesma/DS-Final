/********************************************************************************
** Form generated from reading UI file 'myclass.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCLASS_H
#define UI_MYCLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyClassClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *listButton;
    QPushButton *diskButton;
    QPushButton *teamButton;
    QPushButton *woodButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyClassClass)
    {
        if (MyClassClass->objectName().isEmpty())
            MyClassClass->setObjectName(QStringLiteral("MyClassClass"));
        MyClassClass->resize(333, 187);
        centralWidget = new QWidget(MyClassClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        listButton = new QPushButton(centralWidget);
        listButton->setObjectName(QStringLiteral("listButton"));
        listButton->setMinimumSize(QSize(100, 50));

        gridLayout->addWidget(listButton, 0, 0, 1, 1);

        diskButton = new QPushButton(centralWidget);
        diskButton->setObjectName(QStringLiteral("diskButton"));
        diskButton->setMinimumSize(QSize(100, 50));

        gridLayout->addWidget(diskButton, 0, 1, 1, 1);

        teamButton = new QPushButton(centralWidget);
        teamButton->setObjectName(QStringLiteral("teamButton"));
        teamButton->setMinimumSize(QSize(100, 50));

        gridLayout->addWidget(teamButton, 1, 0, 1, 1);

        woodButton = new QPushButton(centralWidget);
        woodButton->setObjectName(QStringLiteral("woodButton"));
        woodButton->setMinimumSize(QSize(100, 50));

        gridLayout->addWidget(woodButton, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MyClassClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MyClassClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyClassClass->setStatusBar(statusBar);

        retranslateUi(MyClassClass);

        QMetaObject::connectSlotsByName(MyClassClass);
    } // setupUi

    void retranslateUi(QMainWindow *MyClassClass)
    {
        MyClassClass->setWindowTitle(QApplication::translate("MyClassClass", "MyClass", 0));
        listButton->setText(QApplication::translate("MyClassClass", "\351\223\276\350\241\250\345\244\215\345\210\266", 0));
        diskButton->setText(QApplication::translate("MyClassClass", "\347\242\216\347\211\207\346\225\264\347\220\206", 0));
        teamButton->setText(QApplication::translate("MyClassClass", "\351\230\237\344\274\215\346\216\222\345\272\217", 0));
        woodButton->setText(QApplication::translate("MyClassClass", "\346\234\250\346\235\220\346\212\233\345\205\211", 0));
    } // retranslateUi

};

namespace Ui {
    class MyClassClass: public Ui_MyClassClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCLASS_H
