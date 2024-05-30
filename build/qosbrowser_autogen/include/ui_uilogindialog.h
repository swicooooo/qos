/********************************************************************************
** Form generated from reading UI file 'uilogindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UILOGINDIALOG_H
#define UI_UILOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QCheckBox *checkBoxRemember;
    QFormLayout *formLayout;
    QLabel *labelsecretid;
    QLineEdit *lineEditSecretid;
    QLabel *labelsecretkey;
    QLineEdit *lineEditSecretkey;
    QLabel *labelRemark;
    QLineEdit *lineEditRemark;
    QPushButton *pushButtonLogin;
    QSpacerItem *verticalSpacer_9;

    void setupUi(QWidget *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(425, 523);
        gridLayout_2 = new QGridLayout(LoginDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
        checkBoxRemember = new QCheckBox(LoginDialog);
        checkBoxRemember->setObjectName(QString::fromUtf8("checkBoxRemember"));

        gridLayout->addWidget(checkBoxRemember, 2, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        labelsecretid = new QLabel(LoginDialog);
        labelsecretid->setObjectName(QString::fromUtf8("labelsecretid"));
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        labelsecretid->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, labelsecretid);

        lineEditSecretid = new QLineEdit(LoginDialog);
        lineEditSecretid->setObjectName(QString::fromUtf8("lineEditSecretid"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditSecretid);

        labelsecretkey = new QLabel(LoginDialog);
        labelsecretkey->setObjectName(QString::fromUtf8("labelsecretkey"));
        labelsecretkey->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, labelsecretkey);

        lineEditSecretkey = new QLineEdit(LoginDialog);
        lineEditSecretkey->setObjectName(QString::fromUtf8("lineEditSecretkey"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditSecretkey);

        labelRemark = new QLabel(LoginDialog);
        labelRemark->setObjectName(QString::fromUtf8("labelRemark"));
        labelRemark->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, labelRemark);

        lineEditRemark = new QLineEdit(LoginDialog);
        lineEditRemark->setObjectName(QString::fromUtf8("lineEditRemark"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditRemark);


        gridLayout->addLayout(formLayout, 1, 0, 1, 2);

        pushButtonLogin = new QPushButton(LoginDialog);
        pushButtonLogin->setObjectName(QString::fromUtf8("pushButtonLogin"));
        pushButtonLogin->setFont(font);

        gridLayout->addWidget(pushButtonLogin, 3, 0, 1, 2);

        verticalSpacer_9 = new QSpacerItem(17, 178, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_9, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QWidget *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Dialog", nullptr));
        checkBoxRemember->setText(QCoreApplication::translate("LoginDialog", "remember", nullptr));
        labelsecretid->setText(QCoreApplication::translate("LoginDialog", "secretid:", nullptr));
        labelsecretkey->setText(QCoreApplication::translate("LoginDialog", "secretkey:", nullptr));
        labelRemark->setText(QCoreApplication::translate("LoginDialog", "remark:", nullptr));
        pushButtonLogin->setText(QCoreApplication::translate("LoginDialog", "login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UILOGINDIALOG_H
