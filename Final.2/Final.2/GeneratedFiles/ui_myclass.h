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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyClassClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *beqEdit;
    QLabel *label_3;
    QLineEdit *endEdit;
    QPushButton *searchButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *inButton;
    QPushButton *outButton;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QRadioButton *minLength;
    QRadioButton *minChange;
    QTableWidget *getWidget;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *addEdgeButton;
    QLineEdit *delEdgeEdit;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *delEdgeButton;
    QLineEdit *addEdgeEdit;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *addVerButton;
    QLineEdit *addVerEdit;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *delVerButton;
    QLineEdit *delVerEdit;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *seaEdgeButton;
    QLineEdit *seaEdgeEdit;
    QTableWidget *edgeWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *seaVerButton;
    QLineEdit *seaVerEdit;
    QTableWidget *verWidget;
    QGroupBox *groupBox_3;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyClassClass)
    {
        if (MyClassClass->objectName().isEmpty())
            MyClassClass->setObjectName(QStringLiteral("MyClassClass"));
        MyClassClass->resize(1116, 905);
        centralWidget = new QWidget(MyClassClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral(""));
        label->setFrameShape(QFrame::NoFrame);

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        beqEdit = new QLineEdit(centralWidget);
        beqEdit->setObjectName(QStringLiteral("beqEdit"));

        horizontalLayout->addWidget(beqEdit);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        endEdit = new QLineEdit(centralWidget);
        endEdit->setObjectName(QStringLiteral("endEdit"));

        horizontalLayout->addWidget(endEdit);

        searchButton = new QPushButton(centralWidget);
        searchButton->setObjectName(QStringLiteral("searchButton"));

        horizontalLayout->addWidget(searchButton);


        horizontalLayout_10->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(308, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        inButton = new QPushButton(centralWidget);
        inButton->setObjectName(QStringLiteral("inButton"));

        horizontalLayout_3->addWidget(inButton);

        outButton = new QPushButton(centralWidget);
        outButton->setObjectName(QStringLiteral("outButton"));

        horizontalLayout_3->addWidget(outButton);


        horizontalLayout_10->addLayout(horizontalLayout_3);


        gridLayout_4->addLayout(horizontalLayout_10, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(-1, -1, 0, -1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout_2->addWidget(label_4);

        minLength = new QRadioButton(centralWidget);
        minLength->setObjectName(QStringLiteral("minLength"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(minLength->sizePolicy().hasHeightForWidth());
        minLength->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(minLength);

        minChange = new QRadioButton(centralWidget);
        minChange->setObjectName(QStringLiteral("minChange"));
        sizePolicy.setHeightForWidth(minChange->sizePolicy().hasHeightForWidth());
        minChange->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(minChange);


        verticalLayout_5->addLayout(horizontalLayout_2);

        getWidget = new QTableWidget(centralWidget);
        getWidget->setObjectName(QStringLiteral("getWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(getWidget->sizePolicy().hasHeightForWidth());
        getWidget->setSizePolicy(sizePolicy1);
        getWidget->setMinimumSize(QSize(0, 250));
        getWidget->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_5->addWidget(getWidget);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        addEdgeButton = new QPushButton(groupBox);
        addEdgeButton->setObjectName(QStringLiteral("addEdgeButton"));
        sizePolicy.setHeightForWidth(addEdgeButton->sizePolicy().hasHeightForWidth());
        addEdgeButton->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(addEdgeButton);

        delEdgeEdit = new QLineEdit(groupBox);
        delEdgeEdit->setObjectName(QStringLiteral("delEdgeEdit"));
        sizePolicy.setHeightForWidth(delEdgeEdit->sizePolicy().hasHeightForWidth());
        delEdgeEdit->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(delEdgeEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        delEdgeButton = new QPushButton(groupBox);
        delEdgeButton->setObjectName(QStringLiteral("delEdgeButton"));
        sizePolicy.setHeightForWidth(delEdgeButton->sizePolicy().hasHeightForWidth());
        delEdgeButton->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(delEdgeButton);

        addEdgeEdit = new QLineEdit(groupBox);
        addEdgeEdit->setObjectName(QStringLiteral("addEdgeEdit"));
        sizePolicy.setHeightForWidth(addEdgeEdit->sizePolicy().hasHeightForWidth());
        addEdgeEdit->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(addEdgeEdit);


        verticalLayout->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        verticalLayout_5->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy2.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy2);
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        addVerButton = new QPushButton(groupBox_2);
        addVerButton->setObjectName(QStringLiteral("addVerButton"));
        sizePolicy.setHeightForWidth(addVerButton->sizePolicy().hasHeightForWidth());
        addVerButton->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(addVerButton);

        addVerEdit = new QLineEdit(groupBox_2);
        addVerEdit->setObjectName(QStringLiteral("addVerEdit"));
        sizePolicy.setHeightForWidth(addVerEdit->sizePolicy().hasHeightForWidth());
        addVerEdit->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(addVerEdit);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        delVerButton = new QPushButton(groupBox_2);
        delVerButton->setObjectName(QStringLiteral("delVerButton"));
        sizePolicy.setHeightForWidth(delVerButton->sizePolicy().hasHeightForWidth());
        delVerButton->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(delVerButton);

        delVerEdit = new QLineEdit(groupBox_2);
        delVerEdit->setObjectName(QStringLiteral("delVerEdit"));
        sizePolicy.setHeightForWidth(delVerEdit->sizePolicy().hasHeightForWidth());
        delVerEdit->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(delVerEdit);


        verticalLayout_2->addLayout(horizontalLayout_7);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);


        verticalLayout_5->addWidget(groupBox_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        seaEdgeButton = new QPushButton(centralWidget);
        seaEdgeButton->setObjectName(QStringLiteral("seaEdgeButton"));
        sizePolicy.setHeightForWidth(seaEdgeButton->sizePolicy().hasHeightForWidth());
        seaEdgeButton->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(seaEdgeButton);

        seaEdgeEdit = new QLineEdit(centralWidget);
        seaEdgeEdit->setObjectName(QStringLiteral("seaEdgeEdit"));
        sizePolicy.setHeightForWidth(seaEdgeEdit->sizePolicy().hasHeightForWidth());
        seaEdgeEdit->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(seaEdgeEdit);


        verticalLayout_3->addLayout(horizontalLayout_8);

        edgeWidget = new QTableWidget(centralWidget);
        edgeWidget->setObjectName(QStringLiteral("edgeWidget"));
        sizePolicy1.setHeightForWidth(edgeWidget->sizePolicy().hasHeightForWidth());
        edgeWidget->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(edgeWidget);


        verticalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        seaVerButton = new QPushButton(centralWidget);
        seaVerButton->setObjectName(QStringLiteral("seaVerButton"));
        sizePolicy.setHeightForWidth(seaVerButton->sizePolicy().hasHeightForWidth());
        seaVerButton->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(seaVerButton);

        seaVerEdit = new QLineEdit(centralWidget);
        seaVerEdit->setObjectName(QStringLiteral("seaVerEdit"));
        sizePolicy.setHeightForWidth(seaVerEdit->sizePolicy().hasHeightForWidth());
        seaVerEdit->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(seaVerEdit);


        verticalLayout_4->addLayout(horizontalLayout_9);

        verWidget = new QTableWidget(centralWidget);
        verWidget->setObjectName(QStringLiteral("verWidget"));
        sizePolicy1.setHeightForWidth(verWidget->sizePolicy().hasHeightForWidth());
        verWidget->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(verWidget);


        verticalLayout_5->addLayout(verticalLayout_4);


        gridLayout_3->addLayout(verticalLayout_5, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy3);
        groupBox_3->setMinimumSize(QSize(830, 0));

        gridLayout_3->addWidget(groupBox_3, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 1, 0, 1, 1);

        MyClassClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MyClassClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyClassClass->setStatusBar(statusBar);

        retranslateUi(MyClassClass);

        QMetaObject::connectSlotsByName(MyClassClass);
    } // setupUi

    void retranslateUi(QMainWindow *MyClassClass)
    {
        MyClassClass->setWindowTitle(QApplication::translate("MyClassClass", "\345\234\260\351\223\201\346\215\242\344\271\230", 0));
        label->setText(QApplication::translate("MyClassClass", "\347\272\277\350\267\257\345\233\276\346\237\245\350\257\242", 0));
        label_2->setText(QApplication::translate("MyClassClass", "\350\265\267\345\247\213\347\253\231", 0));
        label_3->setText(QApplication::translate("MyClassClass", "\347\273\210\347\202\271\347\253\231", 0));
        searchButton->setText(QApplication::translate("MyClassClass", "\346\220\234\347\264\242", 0));
        inButton->setText(QApplication::translate("MyClassClass", "\345\257\274\345\205\245\345\234\260\345\233\276\346\225\260\346\215\256", 0));
        outButton->setText(QApplication::translate("MyClassClass", "\345\257\274\345\207\272\345\234\260\345\233\276\346\225\260\346\215\256", 0));
        label_4->setText(QApplication::translate("MyClassClass", "\344\271\230\350\275\246\346\226\271\346\241\210", 0));
        minLength->setText(QApplication::translate("MyClassClass", "\350\267\257\345\276\204\346\234\200\347\237\255", 0));
        minChange->setText(QApplication::translate("MyClassClass", "\346\215\242\344\271\230\346\234\200\345\260\221", 0));
        groupBox->setTitle(QApplication::translate("MyClassClass", "\347\272\277\350\267\257\347\274\226\350\276\221", 0));
        addEdgeButton->setText(QApplication::translate("MyClassClass", "\346\267\273\345\212\240", 0));
        delEdgeButton->setText(QApplication::translate("MyClassClass", "\345\210\240\351\231\244", 0));
        groupBox_2->setTitle(QApplication::translate("MyClassClass", "\347\253\231\347\202\271\347\274\226\350\276\221", 0));
        addVerButton->setText(QApplication::translate("MyClassClass", "\346\267\273\345\212\240", 0));
        delVerButton->setText(QApplication::translate("MyClassClass", "\345\210\240\351\231\244", 0));
        seaEdgeButton->setText(QApplication::translate("MyClassClass", "\347\272\277\350\267\257\346\237\245\350\257\242", 0));
        seaVerButton->setText(QApplication::translate("MyClassClass", "\347\253\231\347\202\271\346\237\245\350\257\242", 0));
        groupBox_3->setTitle(QApplication::translate("MyClassClass", "\345\234\260\345\233\276", 0));
    } // retranslateUi

};

namespace Ui {
    class MyClassClass: public Ui_MyClassClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCLASS_H
