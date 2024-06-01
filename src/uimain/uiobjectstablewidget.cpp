#include "uiobjectstablewidget.h"
#include "ui_uiobjectstablewidget.h"

#include <Gateway.h>
#include <ManagerModel.h>

UiObjectsTableWidget::UiObjectsTableWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ObjectsWidget)
{
    ui->setupUi(this);
    // 绑定数据
    ui->tableView->setModel(ManagerModel::instance()->modelObjects());

    // 设置行宽度
    ui->tableView->setColumnWidth(0, 250);
    ui->tableView->setColumnWidth(1, 150);
    ui->tableView->horizontalHeader()->setStretchLastSection(true); // 设置最后一节占满后面的空间

    // 设置隐藏列的标题，点击鼠标自动排序
    ui->tableView->verticalHeader()->setHidden(true);
    ui->tableView->setSortingEnabled(true);     // 通过model指定排序规则

    ui->widgetBread->setPath("file1/a/b/c");    // Test
}

UiObjectsTableWidget::~UiObjectsTableWidget()
{
    delete ui;
}

void UiObjectsTableWidget::on_pushButtonBuckets_clicked()
{
    Gateway::instance()->send(global::api::BUCKETS::BLIST,"");
}

