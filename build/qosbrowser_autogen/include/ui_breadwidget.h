/********************************************************************************
** Form generated from reading UI file 'breadwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BREADWIDGET_H
#define UI_BREADWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QListView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BreadWidget
{
public:
    QGridLayout *gridLayout;
    QListView *listView;

    void setupUi(QWidget *BreadWidget)
    {
        if (BreadWidget->objectName().isEmpty())
            BreadWidget->setObjectName(QString::fromUtf8("BreadWidget"));
        BreadWidget->resize(761, 85);
        gridLayout = new QGridLayout(BreadWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(4, 4, 4, 4);
        listView = new QListView(BreadWidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setLayoutDirection(Qt::LeftToRight);
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView->setFlow(QListView::LeftToRight);

        gridLayout->addWidget(listView, 0, 0, 1, 1);


        retranslateUi(BreadWidget);

        QMetaObject::connectSlotsByName(BreadWidget);
    } // setupUi

    void retranslateUi(QWidget *BreadWidget)
    {
        BreadWidget->setWindowTitle(QCoreApplication::translate("BreadWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BreadWidget: public Ui_BreadWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BREADWIDGET_H
