#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QosDialog.h>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QosDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();
protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private slots:
    void onPushButtonLoginClicked();
    void onLoginCallback(bool flag);

private:
    Ui::LoginDialog *ui;
    QPoint startPos_;
};

#endif // LOGINDIALOG_H
