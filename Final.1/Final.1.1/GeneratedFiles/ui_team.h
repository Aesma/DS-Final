/********************************************************************************
** Form generated from reading UI file 'team.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEAM_H
#define UI_TEAM_H

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

class Ui_teamDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *inButton;
    QLineEdit *lineEdit;
    QPushButton *doButton;

    void setupUi(QDialog *teamDialog)
    {
        if (teamDialog->objectName().isEmpty())
            teamDialog->setObjectName(QStringLiteral("teamDialog"));
        teamDialog->resize(400, 112);
        teamDialog->setModal(true);
        gridLayout = new QGridLayout(teamDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        inButton = new QPushButton(teamDialog);
        inButton->setObjectName(QStringLiteral("inButton"));

        horizontalLayout->addWidget(inButton);

        lineEdit = new QLineEdit(teamDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        doButton = new QPushButton(teamDialog);
        doButton->setObjectName(QStringLiteral("doButton"));

        verticalLayout->addWidget(doButton);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(teamDialog);

        QMetaObject::connectSlotsByName(teamDialog);
    } // setupUi

    void retranslateUi(QDialog *teamDialog)
    {
        teamDialog->setWindowTitle(QApplication::translate("teamDialog", "Dialog", 0));
        inButton->setText(QApplication::translate("teamDialog", "\346\211\223\345\274\200\346\226\207\344\273\266", 0));
        doButton->setText(QApplication::translate("teamDialog", "\346\216\222\345\220\215", 0));
    } // retranslateUi

};

namespace Ui {
    class teamDialog: public Ui_teamDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEAM_H
