/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QCheckBox *checkBoxRemember;
    QHBoxLayout *horizontalLayout;
    QLabel *labelLogo;
    QSpacerItem *horizontalSpacer;
    QLabel *labelTitle;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonClose;
    QFrame *line;
    QFormLayout *formLayout;
    QLabel *labelsecretid;
    QLineEdit *lineEditSecretid;
    QLabel *labelsecretkey;
    QLineEdit *lineEditSecretkey;
    QLabel *labelRemark;
    QLineEdit *lineEditRemark;
    QSpacerItem *verticalSpacer_9;
    QPushButton *pushButtonLogin;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(353, 443);
        gridLayout_2 = new QGridLayout(LoginDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        checkBoxRemember = new QCheckBox(LoginDialog);
        checkBoxRemember->setObjectName(QString::fromUtf8("checkBoxRemember"));

        gridLayout->addWidget(checkBoxRemember, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelLogo = new QLabel(LoginDialog);
        labelLogo->setObjectName(QString::fromUtf8("labelLogo"));
        labelLogo->setMinimumSize(QSize(32, 32));

        horizontalLayout->addWidget(labelLogo);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        labelTitle = new QLabel(LoginDialog);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        QFont font;
        font.setPointSize(15);
        labelTitle->setFont(font);

        horizontalLayout->addWidget(labelTitle);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButtonClose = new QPushButton(LoginDialog);
        pushButtonClose->setObjectName(QString::fromUtf8("pushButtonClose"));

        horizontalLayout->addWidget(pushButtonClose);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        line = new QFrame(LoginDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        labelsecretid = new QLabel(LoginDialog);
        labelsecretid->setObjectName(QString::fromUtf8("labelsecretid"));
        QFont font1;
        font1.setPointSize(12);
        labelsecretid->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, labelsecretid);

        lineEditSecretid = new QLineEdit(LoginDialog);
        lineEditSecretid->setObjectName(QString::fromUtf8("lineEditSecretid"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditSecretid);

        labelsecretkey = new QLabel(LoginDialog);
        labelsecretkey->setObjectName(QString::fromUtf8("labelsecretkey"));
        labelsecretkey->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, labelsecretkey);

        lineEditSecretkey = new QLineEdit(LoginDialog);
        lineEditSecretkey->setObjectName(QString::fromUtf8("lineEditSecretkey"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditSecretkey);

        labelRemark = new QLabel(LoginDialog);
        labelRemark->setObjectName(QString::fromUtf8("labelRemark"));
        labelRemark->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, labelRemark);

        lineEditRemark = new QLineEdit(LoginDialog);
        lineEditRemark->setObjectName(QString::fromUtf8("lineEditRemark"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditRemark);


        gridLayout->addLayout(formLayout, 3, 0, 1, 2);

        verticalSpacer_9 = new QSpacerItem(17, 178, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_9, 2, 1, 1, 1);

        pushButtonLogin = new QPushButton(LoginDialog);
        pushButtonLogin->setObjectName(QString::fromUtf8("pushButtonLogin"));
        pushButtonLogin->setFont(font1);

        gridLayout->addWidget(pushButtonLogin, 5, 0, 1, 2);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(LoginDialog);
        QObject::connect(pushButtonClose, SIGNAL(clicked()), LoginDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Dialog", nullptr));
        checkBoxRemember->setText(QCoreApplication::translate("LoginDialog", "remember", nullptr));
        labelLogo->setText(QString());
        labelTitle->setText(QCoreApplication::translate("LoginDialog", "Login", nullptr));
        pushButtonClose->setText(QString());
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

#endif // UI_LOGINDIALOG_H
