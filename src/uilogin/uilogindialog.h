#ifndef UILOGINDIALOG_H
#define UILOGINDIALOG_H

#include <UiQosDialog.h>
#include <entityclass.h>

namespace Ui {
class LoginDialog;
}

class UiLoginDialog : public UiQosDialog
{
    Q_OBJECT

public:
    explicit UiLoginDialog(QWidget *parent = nullptr);
    ~UiLoginDialog();
protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
    void onPushButtonLoginClicked();    // 向网关发送登录请求
    void onLoginCallback(bool flag, QList<Bucket> &buckets);    // 登录请求的回调函数

private:
    Ui::LoginDialog *ui;
    QPoint startPos_;
};

#endif // UILOGINDIALOG_H
