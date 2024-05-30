/********************************************************************************
** Form generated from reading UI file 'uibucketswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIBUCKETSWIDGET_H
#define UI_UIBUCKETSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BucketsWidget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QListView *listView;

    void setupUi(QWidget *BucketsWidget)
    {
        if (BucketsWidget->objectName().isEmpty())
            BucketsWidget->setObjectName(QString::fromUtf8("BucketsWidget"));
        BucketsWidget->resize(303, 516);
        gridLayout = new QGridLayout(BucketsWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(BucketsWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(BucketsWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        listView = new QListView(BucketsWidget);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout->addWidget(listView);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(BucketsWidget);

        QMetaObject::connectSlotsByName(BucketsWidget);
    } // setupUi

    void retranslateUi(QWidget *BucketsWidget)
    {
        BucketsWidget->setWindowTitle(QCoreApplication::translate("BucketsWidget", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("BucketsWidget", "\346\220\234\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BucketsWidget: public Ui_BucketsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIBUCKETSWIDGET_H
