/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "breadwidget.h"
#include "bucketswidget.h"
#include "objectswidget.h"
#include "pagewidget.h"
#include "toolbarwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QGridLayout *gridLayout;
    QSplitter *splitter;
    BucketsWidget *widgetBucket;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    ToolBarWidget *widgetToolBar;
    BreadWidget *widgetBread;
    ObjectsWidget *widgetObject;
    PageWidget *widgetPage;

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
        widgetBucket = new BucketsWidget(splitter);
        widgetBucket->setObjectName(QString::fromUtf8("widgetBucket"));
        splitter->addWidget(widgetBucket);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widgetToolBar = new ToolBarWidget(layoutWidget);
        widgetToolBar->setObjectName(QString::fromUtf8("widgetToolBar"));

        verticalLayout->addWidget(widgetToolBar);

        widgetBread = new BreadWidget(layoutWidget);
        widgetBread->setObjectName(QString::fromUtf8("widgetBread"));

        verticalLayout->addWidget(widgetBread);

        widgetObject = new ObjectsWidget(layoutWidget);
        widgetObject->setObjectName(QString::fromUtf8("widgetObject"));

        verticalLayout->addWidget(widgetObject);

        widgetPage = new PageWidget(layoutWidget);
        widgetPage->setObjectName(QString::fromUtf8("widgetPage"));

        verticalLayout->addWidget(widgetPage);

        verticalLayout->setStretch(2, 1);
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

#endif // UI_MAINWIDGET_H
