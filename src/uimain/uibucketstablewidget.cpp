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

    ui->widgetPage->setMaxRowList({10, 20, 50});

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

    connect(ui->widgetPage, &UiPageWidget::pageNumChanged, this, &UiBucketsTableWidget::onPageNumChanged);
    connect(ui->tableView->model(), &QAbstractItemModel::rowsInserted, this, &UiBucketsTableWidget::onTableRowsChanged);
    connect(ui->tableView->model(), &QAbstractItemModel::rowsRemoved, this, &UiBucketsTableWidget::onTableRowsChanged);
    connect(ui->tableView->model(), &QAbstractItemModel::modelReset, this, &UiBucketsTableWidget::onTableRowsChanged);

    onTableRowsChanged();
}

UiBucketsTableWidget::~UiBucketsTableWidget()
{
    delete ui;
}

void UiBucketsTableWidget::onTableRowsChanged()
{
    int totalRows = ui->tableView->model()->rowCount();
    ui->widgetPage->setTotalRow(totalRows);
}

void UiBucketsTableWidget::onPageNumChanged(int startRow, int count)
{
    // 更新每行是否显示
    ui->tableView->scrollTo(ui->tableView->model()->index(startRow, 0));
    for (int row = 0; row < ui->tableView->model()->rowCount(); ++row)
    {
        bool isVisible = row >= startRow && row < startRow + count;
        ui->tableView->setRowHidden(row, !isVisible);
    }
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

