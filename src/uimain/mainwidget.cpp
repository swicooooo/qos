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

    // 在窗口添加传输和退出按钮
    addButton(global::path::TRAN_PATH,global::path::TRAN_HOVER_PATH);
    auto quitBtn = addButton(global::path::QUIT_PATH,global::path::QUIT_HOVER_PATH);
    // connect()    // TODO 连接信号退出登录关闭mainwidget显示loginwidget

    addTitleLine();    // 添加分隔栏

    // 为main窗口添加最大化和最小化按钮
    addMinButton(global::path::MIN_PATH, global::path::MIN_HOVER_PATH);
    addMaxButton(global::path::MAX_PATH, global::path::MAX_HOVER_PATH,
                 global::path::NORMLA_PATH, global::path::NORMLA_HOVER_PATH);
    setTitle(QString("Qos Browser"));
    resize(1080, 640);  // 重设大小

    // 巧妙：对widgetToolBar发过来的信号统一处理
    // connect(ui->widgetToolBar, &ToolBarWidget::buttonClick, this, &MainWidget::onButtonClick);
    // ui->stackedWidget->setCurrentIndex(1);   Test
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
