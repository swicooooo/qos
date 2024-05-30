#include "uibucketswidget.h"
#include "ui_uibucketswidget.h"

#include <bucketmodel.h>

UiBucketsWidget::UiBucketsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BucketsWidget)
{
    ui->setupUi(this);
    ui->listView->setModel(BucketModel::instance()->model());
}

UiBucketsWidget::~UiBucketsWidget()
{
    delete ui;
}
