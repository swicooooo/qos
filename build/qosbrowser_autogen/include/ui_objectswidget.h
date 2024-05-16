/********************************************************************************
** Form generated from reading UI file 'objectswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBJECTSWIDGET_H
#define UI_OBJECTSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ObjectsWidget
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;

    void setupUi(QWidget *ObjectsWidget)
    {
        if (ObjectsWidget->objectName().isEmpty())
            ObjectsWidget->setObjectName(QString::fromUtf8("ObjectsWidget"));
        ObjectsWidget->resize(454, 414);
        gridLayout = new QGridLayout(ObjectsWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 7, 0, 0);
        tableView = new QTableView(ObjectsWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);


        retranslateUi(ObjectsWidget);

        QMetaObject::connectSlotsByName(ObjectsWidget);
    } // setupUi

    void retranslateUi(QWidget *ObjectsWidget)
    {
        ObjectsWidget->setWindowTitle(QCoreApplication::translate("ObjectsWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ObjectsWidget: public Ui_ObjectsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBJECTSWIDGET_H
