#include "uiobjectstablewidget.h"
#include "ui_uiobjectstablewidget.h"

UiObjectsTableWidget::UiObjectsTableWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ObjectsWidget)
{
    ui->setupUi(this);
}

UiObjectsTableWidget::~UiObjectsTableWidget()
{
    delete ui;
}
