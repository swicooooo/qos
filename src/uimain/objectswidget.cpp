#include "objectswidget.h"
#include "ui_objectswidget.h"

#include <BucketDeleagte.h>
#include <BucketModel.h>

ObjectsWidget::ObjectsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ObjectsWidget)
{
    ui->setupUi(this);

    // 指定model数据来源，指定某行的代理数据
    ui->tableView->setModel(BucketModel::instance()->model());
    ui->tableView->setItemDelegateForColumn(1, new BucketDeleagte());

    // // 设置标题内容
    QStandardItemModel*  model = BucketModel::instance()->model();
    QStringList labels;
    labels << QString("bucket_name") << QString("location") << QString("create_time");
    // model->setColumnCount(labels.size());
    model->setHorizontalHeaderLabels(labels);

    // // 设置行宽度
    ui->tableView->setColumnWidth(0, 250);
    ui->tableView->setColumnWidth(1, 150);
    ui->tableView->horizontalHeader()->setStretchLastSection(true); // 设置最后一节占满后面的空间

    // 设置隐藏列的标题，点击鼠标自动排序
    ui->tableView->verticalHeader()->setHidden(true);
    ui->tableView->setSortingEnabled(true);     // 通过model指定排序规则
}

ObjectsWidget::~ObjectsWidget()
{
    delete ui;
}
