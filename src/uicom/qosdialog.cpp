#include "qosdialog.h"
#include "Public.h"
#include "ui_qosdialog.h"
#include "ui_basedialog.h"

QosDialog::QosDialog(QWidget *parent)
    : BaseDialog(parent)
    , ui(new Ui::QosDialog)
{
    ui->setupUi(body());    // 当前widget基于basedialog的body进行创建
    setLogo(global::path::LOGO_PATH);
    setTitle(QString("Qos"));
    base_ui->labelLogo->setFixedSize(32,24);    // 使用父类ui指针需要包含头文件 ui_basedialog
}

QosDialog::~QosDialog()
{
    delete ui;
}
