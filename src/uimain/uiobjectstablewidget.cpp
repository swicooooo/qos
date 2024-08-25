#include "uiobjectstablewidget.h"
#include "ui_uiobjectstablewidget.h"

#include <Gateway.h>
#include <ManagerModel.h>

UiObjectsTableWidget::UiObjectsTableWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ObjectsWidget)
{
    ui->setupUi(this);
    ui->widgetPage->setMaxRowList({10, 20, 50});

    ui->tableView->setModel(ManagerModel::instance()->modelObjects());

    // 设置行宽度
    ui->tableView->setColumnWidth(0, 250);
    ui->tableView->setColumnWidth(1, 150);
    ui->tableView->horizontalHeader()->setStretchLastSection(true); // 设置最后一节占满后面的空间

    // 设置隐藏列的标题，点击鼠标自动排序
    ui->tableView->verticalHeader()->setHidden(true);
    ui->tableView->setSortingEnabled(true);     // 通过model指定排序规则

    ui->widgetBread->setPath("file1/a/b/c");    // Test

    connect(ui->widgetPage, &UiPageWidget::pageNumChanged, this, &UiObjectsTableWidget::onPageNumChanged);
    connect(ui->tableView->model(), &QAbstractItemModel::rowsInserted, this, &UiObjectsTableWidget::onTableRowsChanged);
    connect(ui->tableView->model(), &QAbstractItemModel::rowsRemoved, this, &UiObjectsTableWidget::onTableRowsChanged);
    connect(ui->tableView->model(), &QAbstractItemModel::modelReset, this, &UiObjectsTableWidget::onTableRowsChanged);

    onTableRowsChanged();
}

UiObjectsTableWidget::~UiObjectsTableWidget()
{
    delete ui;
}

void UiObjectsTableWidget::onTableRowsChanged()
{
    int totalRows = ui->tableView->model()->rowCount();
    ui->widgetPage->setTotalRow(totalRows);
}

void UiObjectsTableWidget::onPageNumChanged(int startRow, int count)
{
    // 更新每行是否显示
    ui->tableView->scrollTo(ui->tableView->model()->index(startRow, 0));
    for (int row = 0; row < ui->tableView->model()->rowCount(); ++row)
    {
        bool isVisible = row >= startRow && row < startRow + count;
        ui->tableView->setRowHidden(row, !isVisible);
    }
}

void UiObjectsTableWidget::on_pushButtonBuckets_clicked()
{
    Gateway::instance()->send(global::api::BUCKETS::BLIST,"");
}

