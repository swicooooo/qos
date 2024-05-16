#include "logindialog.h"
#include "commonformat.h"
#include "ui_logindialog.h"

#include <QJsonObject>
#include <QKeyEvent>
#include <gateway.h>

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);    // 去除边框和标题栏
    ui->lineEditSecretkey->installEventFilter(this);// 为lineEditSecretkey安装父类event过滤器
    ui->labelTitle->setProperty("style", "h1");     // 添加属性h1
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

void LoginDialog::mousePressEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        startPos_ = event->pos();   // 记录起始pos
    }
    QDialog::mousePressEvent(event);
}

void LoginDialog::mouseMoveEvent(QMouseEvent *event)
{
    // 计算鼠标点击左键时移动的pos+当前窗口的pos
    if(event->buttons() & Qt::LeftButton)
    {
        QPoint targetPos = event->pos() - startPos_ + this->pos();
        this->move(targetPos);
    }
    QDialog::mouseMoveEvent(event);
}

void LoginDialog::on_pushButtonLogin_clicked()
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
