#include "toolbarwidget.h"
#include "ui_toolbarwidget.h"

#include <QSignalMapper>

ToolBarWidget::ToolBarWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ToolBarWidget)
{
    ui->setupUi(this);

    // 使用QSiginalMapper同时和多个相同类型绑定同一种信号
    QSignalMapper *mapper = new QSignalMapper();
    auto buttonList = this->findChildren<QPushButton*>();
    int id = 1;
    for(auto button: buttonList)
    {
        connect(button, SIGNAL(clicked()), mapper, SLOT(map()));            // map()会发出mapped信号
        mapper->setMapping(button, id++);
    }
    connect(mapper, SIGNAL(mapped(int)), this, SIGNAL(buttonClick(int)));   // 再次发出信号
}

ToolBarWidget::~ToolBarWidget()
{
    delete ui;
}

