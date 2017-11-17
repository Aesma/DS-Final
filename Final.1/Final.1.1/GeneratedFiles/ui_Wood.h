/********************************************************************************
** Form generated from reading UI file 'Wood.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WOOD_H
#define UI_WOOD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *InputGroupBox;
    QHBoxLayout *horizontalLayout;
    QLineEdit *InputLine;
    QPushButton *InputButton;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *CalButton;
    QPushButton *CancelButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->setWindowModality(Qt::ApplicationModal);
        Form->resize(470, 359);
        verticalLayout = new QVBoxLayout(Form);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        InputGroupBox = new QGroupBox(Form);
        InputGroupBox->setObjectName(QStringLiteral("InputGroupBox"));
        horizontalLayout = new QHBoxLayout(InputGroupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        InputLine = new QLineEdit(InputGroupBox);
        InputLine->setObjectName(QStringLiteral("InputLine"));

        horizontalLayout->addWidget(InputLine);

        InputButton = new QPushButton(InputGroupBox);
        InputButton->setObjectName(QStringLiteral("InputButton"));

        horizontalLayout->addWidget(InputButton);


        verticalLayout->addWidget(InputGroupBox);

        tableWidget = new QTableWidget(Form);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        CalButton = new QPushButton(Form);
        CalButton->setObjectName(QStringLiteral("CalButton"));

        horizontalLayout_2->addWidget(CalButton);

        CancelButton = new QPushButton(Form);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));

        horizontalLayout_2->addWidget(CancelButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Form);
        QObject::connect(CancelButton, SIGNAL(clicked()), Form, SLOT(close()));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Wood Polishing", 0));
        InputGroupBox->setTitle(QApplication::translate("Form", "InPut", 0));
        InputButton->setText(QApplication::translate("Form", "...", 0));
        CalButton->setText(QApplication::translate("Form", "Calculate", 0));
        CancelButton->setText(QApplication::translate("Form", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WOOD_H
