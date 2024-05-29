#include "logindialog.h"
#include "commonformat.h"
#include "ui_logindialog.h"

#include <QJsonObject>
#include <QKeyEvent>
#include <gateway.h>

LoginDialog::LoginDialog(QWidget *parent)
    : QosDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(body());
    ui->lineEditSecretkey->installEventFilter(this);     // 为lineEditSecretkey安装父类event过滤器

    // 当该组件加入到qosdialog的body中时，需要手动连接登录信号槽
    connect(ui->pushButtonLogin, &QPushButton::clicked, this, &LoginDialog::onPushButtonLoginClicked);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

bool LoginDialog::eventFilter(QObject *watched, QEvent *event)
{
    // 过滤ctrl+c或ctrl+v,禁止lineEditSecretkey复制粘贴
    if(watched == ui->lineEditSecretkey
        && event->type() == QEvent::KeyPress)
    {
        QKeyEvent *eve = static_cast<QKeyEvent*>(event);
        if(eve->modifiers() == Qt::ControlModifier
            && eve->key() == Qt::Key_C || eve->key() == Qt::Key_V)
        {
            return true;    // 表示信号已处理，不需要父控件处理
        }
    }

    // 调用父类的event过滤
    return QDialog::eventFilter(watched, event);
}

void LoginDialog::onPushButtonLoginClicked()
{
    QJsonObject params;
    params["secretId"] = ui->lineEditSecretid->text().trimmed();
    params["secretKey"] = ui->lineEditSecretkey->text().trimmed();
    Gateway::instance()->send(api::LOGIN, params);
    Gateway::instance()->setLoginCallback(std::bind(&LoginDialog::onLoginCallback,this,std::placeholders::_1));
}

void LoginDialog::onLoginCallback(bool flag)
{
    if(flag)
    {
        accept();
    }
    else
    {
        // TODO错误QMessageBox处理
        // reject();
    }
}
