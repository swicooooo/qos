/********************************************************************************
** Form generated from reading UI file 'uimainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIMAINWIDGET_H
#define UI_UIMAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <uibucketstablewidget.h>
#include <uiobjectstablewidget.h>
#include "uibucketswidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QGridLayout *gridLayout;
    QSplitter *splitter;
    UiBucketsWidget *widgetBucket;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    UiBucketsTableWidget *pageBucket;
    UiObjectsTableWidget *pageObject;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(860, 573);
        gridLayout = new QGridLayout(MainWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setContentsMargins(11, 0, 11, 0);
        splitter = new QSplitter(MainWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        widgetBucket = new UiBucketsWidget(splitter);
        widgetBucket->setObjectName(QString::fromUtf8("widgetBucket"));
        splitter->addWidget(widgetBucket);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(layoutWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        pageBucket = new UiBucketsTableWidget();
        pageBucket->setObjectName(QString::fromUtf8("pageBucket"));
        stackedWidget->addWidget(pageBucket);
        pageObject = new UiObjectsTableWidget();
        pageObject->setObjectName(QString::fromUtf8("pageObject"));
        stackedWidget->addWidget(pageObject);

        verticalLayout->addWidget(stackedWidget);

        splitter->addWidget(layoutWidget);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);


        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIMAINWIDGET_H
