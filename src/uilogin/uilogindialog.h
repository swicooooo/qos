#ifndef UILOGINDIALOG_H
#define UILOGINDIALOG_H

#include <UiQosDialog.h>

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
    void onPushButtonLoginClicked();
    void onLoginCallback(bool flag);

private:
    Ui::LoginDialog *ui;
    QPoint startPos_;
};

#endif // UILOGINDIALOG_H
