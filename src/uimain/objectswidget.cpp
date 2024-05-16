#include "objectswidget.h"
#include "ui_objectswidget.h"

#include <BucketDeleagte.h>
#include <BucketModel.h>

ObjectsWidget::ObjectsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ObjectsWidget)
{
    ui->setupUi(this);
    ui->tableView->setModel(BucketModel::instance()->model());          // 指定model数据来源
    ui->tableView->setItemDelegateForColumn(1, new BucketDeleagte());   // 指定某行的代理数据
}

ObjectsWidget::~ObjectsWidget()
{
    delete ui;
}
