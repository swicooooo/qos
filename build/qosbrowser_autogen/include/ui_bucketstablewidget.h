/********************************************************************************
** Form generated from reading UI file 'bucketstablewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUCKETSTABLEWIDGET_H
#define UI_BUCKETSTABLEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>
#include "pagewidget.h"

QT_BEGIN_NAMESPACE

class Ui_BucketsTableWidget
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QWidget *widgetTools;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonCreateBucket;
    QPushButton *pushButtonRefresh;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;
    PageWidget *widgetPage;

    void setupUi(QWidget *BucketsTableWidget)
    {
        if (BucketsTableWidget->objectName().isEmpty())
            BucketsTableWidget->setObjectName(QString::fromUtf8("BucketsTableWidget"));
        BucketsTableWidget->resize(620, 474);
        gridLayout_2 = new QGridLayout(BucketsTableWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widgetTools = new QWidget(BucketsTableWidget);
        widgetTools->setObjectName(QString::fromUtf8("widgetTools"));
        horizontalLayout = new QHBoxLayout(widgetTools);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonCreateBucket = new QPushButton(widgetTools);
        pushButtonCreateBucket->setObjectName(QString::fromUtf8("pushButtonCreateBucket"));
        pushButtonCreateBucket->setMinimumSize(QSize(100, 0));
        pushButtonCreateBucket->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(pushButtonCreateBucket);

        pushButtonRefresh = new QPushButton(widgetTools);
        pushButtonRefresh->setObjectName(QString::fromUtf8("pushButtonRefresh"));
        pushButtonRefresh->setMinimumSize(QSize(80, 0));
        pushButtonRefresh->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(pushButtonRefresh);

        horizontalSpacer = new QSpacerItem(359, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addWidget(widgetTools, 0, 0, 1, 1);

        tableView = new QTableView(BucketsTableWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 1, 0, 1, 1);

        widgetPage = new PageWidget(BucketsTableWidget);
        widgetPage->setObjectName(QString::fromUtf8("widgetPage"));

        gridLayout->addWidget(widgetPage, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(BucketsTableWidget);

        QMetaObject::connectSlotsByName(BucketsTableWidget);
    } // setupUi

    void retranslateUi(QWidget *BucketsTableWidget)
    {
        BucketsTableWidget->setWindowTitle(QCoreApplication::translate("BucketsTableWidget", "Form", nullptr));
        pushButtonCreateBucket->setText(QCoreApplication::translate("BucketsTableWidget", "create_B", nullptr));
        pushButtonRefresh->setText(QCoreApplication::translate("BucketsTableWidget", "refresh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BucketsTableWidget: public Ui_BucketsTableWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUCKETSTABLEWIDGET_H
