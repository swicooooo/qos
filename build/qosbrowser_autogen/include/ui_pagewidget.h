/********************************************************************************
** Form generated from reading UI file 'pagewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGEWIDGET_H
#define UI_PAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <comboline.h>

QT_BEGIN_NAMESPACE

class Ui_PageWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *labelTotal;
    ComboLine *lineEditMaxRows;
    QLabel *label_2;
    QPushButton *pushButtonPre;
    ComboLine *lineEditCurrentPage;
    QLabel *labelPageCount;
    QPushButton *pushButtonNext;

    void setupUi(QWidget *PageWidget)
    {
        if (PageWidget->objectName().isEmpty())
            PageWidget->setObjectName(QString::fromUtf8("PageWidget"));
        PageWidget->resize(729, 76);
        gridLayout = new QGridLayout(PageWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        labelTotal = new QLabel(PageWidget);
        labelTotal->setObjectName(QString::fromUtf8("labelTotal"));

        horizontalLayout->addWidget(labelTotal);

        lineEditMaxRows = new ComboLine(PageWidget);
        lineEditMaxRows->setObjectName(QString::fromUtf8("lineEditMaxRows"));
        lineEditMaxRows->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(lineEditMaxRows);

        label_2 = new QLabel(PageWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        pushButtonPre = new QPushButton(PageWidget);
        pushButtonPre->setObjectName(QString::fromUtf8("pushButtonPre"));
        pushButtonPre->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(pushButtonPre);

        lineEditCurrentPage = new ComboLine(PageWidget);
        lineEditCurrentPage->setObjectName(QString::fromUtf8("lineEditCurrentPage"));
        lineEditCurrentPage->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(lineEditCurrentPage);

        labelPageCount = new QLabel(PageWidget);
        labelPageCount->setObjectName(QString::fromUtf8("labelPageCount"));

        horizontalLayout->addWidget(labelPageCount);

        pushButtonNext = new QPushButton(PageWidget);
        pushButtonNext->setObjectName(QString::fromUtf8("pushButtonNext"));
        pushButtonNext->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(pushButtonNext);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(PageWidget);

        QMetaObject::connectSlotsByName(PageWidget);
    } // setupUi

    void retranslateUi(QWidget *PageWidget)
    {
        PageWidget->setWindowTitle(QCoreApplication::translate("PageWidget", "Form", nullptr));
        labelTotal->setText(QCoreApplication::translate("PageWidget", "\346\257\217\350\241\214\346\230\276\347\244\272", nullptr));
        label_2->setText(QCoreApplication::translate("PageWidget", "\350\241\214", nullptr));
        pushButtonPre->setText(QCoreApplication::translate("PageWidget", "<", nullptr));
        labelPageCount->setText(QCoreApplication::translate("PageWidget", "/", nullptr));
        pushButtonNext->setText(QCoreApplication::translate("PageWidget", ">", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PageWidget: public Ui_PageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEWIDGET_H
