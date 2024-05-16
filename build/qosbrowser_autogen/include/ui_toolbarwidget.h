/********************************************************************************
** Form generated from reading UI file 'toolbarwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLBARWIDGET_H
#define UI_TOOLBARWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToolBarWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_7;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QWidget *ToolBarWidget)
    {
        if (ToolBarWidget->objectName().isEmpty())
            ToolBarWidget->setObjectName(QString::fromUtf8("ToolBarWidget"));
        ToolBarWidget->resize(597, 52);
        gridLayout = new QGridLayout(ToolBarWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_7 = new QPushButton(ToolBarWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(pushButton_7);

        pushButton_4 = new QPushButton(ToolBarWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_2 = new QPushButton(ToolBarWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(ToolBarWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(pushButton_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_5 = new QPushButton(ToolBarWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(ToolBarWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(pushButton_6);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(ToolBarWidget);

        QMetaObject::connectSlotsByName(ToolBarWidget);
    } // setupUi

    void retranslateUi(QWidget *ToolBarWidget)
    {
        ToolBarWidget->setWindowTitle(QCoreApplication::translate("ToolBarWidget", "Form", nullptr));
        pushButton_7->setText(QCoreApplication::translate("ToolBarWidget", "\345\210\233\345\273\272\346\241\266", nullptr));
        pushButton_4->setText(QCoreApplication::translate("ToolBarWidget", "\344\270\212\344\274\240", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ToolBarWidget", "\344\270\213\350\275\275", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ToolBarWidget", "\345\210\267\346\226\260", nullptr));
        pushButton_5->setText(QCoreApplication::translate("ToolBarWidget", "\344\274\240\350\276\223\345\210\227\350\241\250", nullptr));
        pushButton_6->setText(QCoreApplication::translate("ToolBarWidget", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ToolBarWidget: public Ui_ToolBarWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLBARWIDGET_H
