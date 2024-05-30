/********************************************************************************
** Form generated from reading UI file 'uiobjectstablewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIOBJECTSTABLEWIDGET_H
#define UI_UIOBJECTSTABLEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>
#include <UiBreadWidget.h>
#include "uibreadwidget.h"
#include "uipagewidget.h"

QT_BEGIN_NAMESPACE

class Ui_ObjectsWidget
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QWidget *widgetTools;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonBuckets;
    QPushButton *pushButtonRefresh;
    QPushButton *pushButtonUpload;
    QPushButton *pushButtonDownload;
    QSpacerItem *horizontalSpacer;
    UiBreadWidget *widgetBread;
    QTableView *tableView;
    UiPageWidget *widgetPage;

    void setupUi(QWidget *ObjectsWidget)
    {
        if (ObjectsWidget->objectName().isEmpty())
            ObjectsWidget->setObjectName(QString::fromUtf8("ObjectsWidget"));
        ObjectsWidget->resize(750, 515);
        gridLayout_2 = new QGridLayout(ObjectsWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widgetTools = new QWidget(ObjectsWidget);
        widgetTools->setObjectName(QString::fromUtf8("widgetTools"));
        horizontalLayout = new QHBoxLayout(widgetTools);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonBuckets = new QPushButton(widgetTools);
        pushButtonBuckets->setObjectName(QString::fromUtf8("pushButtonBuckets"));
        pushButtonBuckets->setMinimumSize(QSize(90, 0));
        pushButtonBuckets->setMaximumSize(QSize(90, 16777215));

        horizontalLayout->addWidget(pushButtonBuckets);

        pushButtonRefresh = new QPushButton(widgetTools);
        pushButtonRefresh->setObjectName(QString::fromUtf8("pushButtonRefresh"));
        pushButtonRefresh->setMinimumSize(QSize(90, 0));
        pushButtonRefresh->setMaximumSize(QSize(90, 16777215));

        horizontalLayout->addWidget(pushButtonRefresh);

        pushButtonUpload = new QPushButton(widgetTools);
        pushButtonUpload->setObjectName(QString::fromUtf8("pushButtonUpload"));
        pushButtonUpload->setMinimumSize(QSize(90, 0));
        pushButtonUpload->setMaximumSize(QSize(90, 16777215));

        horizontalLayout->addWidget(pushButtonUpload);

        pushButtonDownload = new QPushButton(widgetTools);
        pushButtonDownload->setObjectName(QString::fromUtf8("pushButtonDownload"));
        pushButtonDownload->setMinimumSize(QSize(100, 0));
        pushButtonDownload->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(pushButtonDownload);

        horizontalSpacer = new QSpacerItem(348, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addWidget(widgetTools, 0, 0, 1, 1);

        widgetBread = new UiBreadWidget(ObjectsWidget);
        widgetBread->setObjectName(QString::fromUtf8("widgetBread"));

        gridLayout->addWidget(widgetBread, 1, 0, 1, 1);

        tableView = new QTableView(ObjectsWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 2, 0, 1, 1);

        widgetPage = new UiPageWidget(ObjectsWidget);
        widgetPage->setObjectName(QString::fromUtf8("widgetPage"));

        gridLayout->addWidget(widgetPage, 3, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(ObjectsWidget);

        QMetaObject::connectSlotsByName(ObjectsWidget);
    } // setupUi

    void retranslateUi(QWidget *ObjectsWidget)
    {
        ObjectsWidget->setWindowTitle(QCoreApplication::translate("ObjectsWidget", "Form", nullptr));
        pushButtonBuckets->setText(QCoreApplication::translate("ObjectsWidget", "buckets", nullptr));
        pushButtonRefresh->setText(QCoreApplication::translate("ObjectsWidget", "refresh", nullptr));
        pushButtonUpload->setText(QCoreApplication::translate("ObjectsWidget", "upload", nullptr));
        pushButtonDownload->setText(QCoreApplication::translate("ObjectsWidget", "download", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ObjectsWidget: public Ui_ObjectsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIOBJECTSTABLEWIDGET_H
