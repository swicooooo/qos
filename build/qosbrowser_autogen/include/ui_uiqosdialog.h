/********************************************************************************
** Form generated from reading UI file 'uiqosdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIQOSDIALOG_H
#define UI_UIQOSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QosDialog
{
public:

    void setupUi(QWidget *QosDialog)
    {
        if (QosDialog->objectName().isEmpty())
            QosDialog->setObjectName(QString::fromUtf8("QosDialog"));
        QosDialog->resize(541, 405);

        retranslateUi(QosDialog);

        QMetaObject::connectSlotsByName(QosDialog);
    } // setupUi

    void retranslateUi(QWidget *QosDialog)
    {
        QosDialog->setWindowTitle(QCoreApplication::translate("QosDialog", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QosDialog: public Ui_QosDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIQOSDIALOG_H
