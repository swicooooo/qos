#include "bucketswidget.h"
#include "ui_bucketswidget.h"

#include <bucketmodel.h>

BucketsWidget::BucketsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BucketsWidget)
{
    ui->setupUi(this);
    ui->listView->setModel(BucketModel::instance()->model());
}

BucketsWidget::~BucketsWidget()
{
    delete ui;
}
