#include "uibucketswidget.h"
#include "ui_uibucketswidget.h"

#include <Gateway.h>
#include <managermodel.h>
#include <nlohmann/json.hpp>

UiBucketsWidget::UiBucketsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BucketsWidget)
{
    ui->setupUi(this);
    ui->listView->setModel(ManagerModel::instance()->modelBuckets());
}

UiBucketsWidget::~UiBucketsWidget()
{
    delete ui;
}

void UiBucketsWidget::on_listView_doubleClicked(const QModelIndex &index)
{
    nlohmann::json params;
    params["name"] = index.data().toString().toStdString();
    params["dir"] = "";
    Gateway::instance()->send(global::api::OBJECTS::OLIST, params);
}

