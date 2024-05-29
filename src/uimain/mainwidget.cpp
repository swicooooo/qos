#include "mainwidget.h"
#include "Public.h"
#include "commonformat.h"
#include "ui_mainwidget.h"
#include <QPushButton>
#include <QDebug>

MainWidget::MainWidget(QWidget *parent)
    : QosDialog(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(body());
    ui->splitter->setStretchFactor(0, 2);
    ui->splitter->setStretchFactor(1, 5);

    // 为main窗口添加最大化和最小化按钮
    addMinButton(global::path::MIN_PATH, global::path::MIN_HOVER_PATH);
    addMaxButton(global::path::MAX_PATH, global::path::MAX_HOVER_PATH,
                 global::path::NORMLA_PATH, global::path::NORMLA_HOVER_PATH);
    setTitle(QString("Qos Browser"));
    resize(1080, 640);  // 重设大小

    // 巧妙：对widgetToolBar发过来的信号统一处理
    connect(ui->widgetToolBar, &ToolBarWidget::buttonClick, this, &MainWidget::onButtonClick);

    // Test
    ui->widgetBread->setPath("file-1/a/b/c");
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::onButtonClick(int id)
{
    // TODO  switch选择对button的具体处理
    switch (id) {
    case btn::CREATE_BUCKET:
        qDebug() << "CREATE_BUCKET...";
        break;
    default:
        break;
    }
}
