/********************************************************************************
** Form generated from reading UI file 'basedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASEDIALOG_H
#define UI_BASEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BaseDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QFrame *frameTitle;
    QHBoxLayout *horizontalLayout;
    QLabel *labelLogo;
    QLabel *labelTitle;
    QPushButton *pushButtonClose;
    QFrame *line;
    QWidget *widgetBody;

    void setupUi(QDialog *BaseDialog)
    {
        if (BaseDialog->objectName().isEmpty())
            BaseDialog->setObjectName(QString::fromUtf8("BaseDialog"));
        BaseDialog->resize(424, 491);
        gridLayout = new QGridLayout(BaseDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frameTitle = new QFrame(BaseDialog);
        frameTitle->setObjectName(QString::fromUtf8("frameTitle"));
        frameTitle->setFrameShape(QFrame::StyledPanel);
        frameTitle->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frameTitle);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(4, 4, 4, 4);
        labelLogo = new QLabel(frameTitle);
        labelLogo->setObjectName(QString::fromUtf8("labelLogo"));

        horizontalLayout->addWidget(labelLogo);

        labelTitle = new QLabel(frameTitle);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));

        horizontalLayout->addWidget(labelTitle);

        pushButtonClose = new QPushButton(frameTitle);
        pushButtonClose->setObjectName(QString::fromUtf8("pushButtonClose"));

        horizontalLayout->addWidget(pushButtonClose);

        horizontalLayout->setStretch(1, 1);

        verticalLayout->addWidget(frameTitle);

        line = new QFrame(BaseDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        widgetBody = new QWidget(BaseDialog);
        widgetBody->setObjectName(QString::fromUtf8("widgetBody"));

        verticalLayout->addWidget(widgetBody);

        verticalLayout->setStretch(2, 1);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(BaseDialog);

        QMetaObject::connectSlotsByName(BaseDialog);
    } // setupUi

    void retranslateUi(QDialog *BaseDialog)
    {
        BaseDialog->setWindowTitle(QCoreApplication::translate("BaseDialog", "Dialog", nullptr));
        labelLogo->setText(QCoreApplication::translate("BaseDialog", "logo", nullptr));
        labelTitle->setText(QCoreApplication::translate("BaseDialog", "<html><head/><body><p align=\"center\">Title</p></body></html>", nullptr));
        pushButtonClose->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BaseDialog: public Ui_BaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASEDIALOG_H
