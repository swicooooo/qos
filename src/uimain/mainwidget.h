#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QosDialog.h>

namespace Ui {
class MainWidget;
}

class MainWidget : public QosDialog
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private slots:
    void onButtonClick(int id);

private:
    Ui::MainWidget *ui;
};

#endif // MAINWIDGET_H
