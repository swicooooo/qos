#include "uibucketstablewidget.h"
#include "ui_uibucketstablewidget.h"

#include <UiBucketDeleagte.h>
#include <managermodel.h>
#include <ToolBarWidget.h>
#include <qstandarditemmodel.h>
#include <Gateway.h>
#include <nlohmann/json.hpp>

UiBucketsTableWidget::UiBucketsTableWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BucketsTableWidget)
{
    ui->setupUi(this);

    // 指定model数据来源，指定某行的代理数据
    ui->tableView->setModel(ManagerModel::instance()->modelBuckets());
    ui->tableView->setItemDelegateForColumn(1, new UiBucketDeleagte());

    // 设置行宽度
    ui->tableView->setColumnWidth(0, 250);
    ui->tableView->setColumnWidth(1, 150);
    ui->tableView->horizontalHeader()->setStretchLastSection(true); // 设置最后一节占满后面的空间

    // 设置隐藏列的标题，点击鼠标自动排序
    ui->tableView->verticalHeader()->setHidden(true);
    ui->tableView->setSortingEnabled(true);     // 通过model指定排序规则

}

UiBucketsTableWidget::~UiBucketsTableWidget()
{
    delete ui;
}


void UiBucketsTableWidget::on_tableView_doubleClicked(const QModelIndex &index)
{
    if(index.column() == 0)
    {
        nlohmann::json params;
        params["name"] = index.data().toString().toStdString();
        params["dir"] = "";
        Gateway::instance()->send(global::api::OBJECTS::OLIST, params);
    }
}

