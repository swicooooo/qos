#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QPushButton>
#include <QDebug>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0, 2);
    ui->splitter->setStretchFactor(1, 5);

    // 巧妙：对widgetToolBar发过来的信号统一处理
    connect(ui->widgetToolBar, &ToolBarWidget::buttonClick, this, &MainWidget::onButtonClick);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::onButtonClick(int id)
{
    //TODO  switch选择对button的具体处理
    // switch (id) {
    // case CREATE_BUCKET:
    //     qDebug() << "CREATE_BUCKET...";
    //     break;
    // default:
    //     break;
    // }
}
