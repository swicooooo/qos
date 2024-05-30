#ifndef UIMAINWIDGET_H
#define UIMAINWIDGET_H

#include <UiQosDialog.h>

namespace Ui {
class MainWidget;
}

class UiMainWidget : public UiQosDialog
{
    Q_OBJECT

public:
    explicit UiMainWidget(QWidget *parent = nullptr);
    ~UiMainWidget();

private slots:
    void onButtonClick(int id);

private:
    Ui::MainWidget *ui;
};

#endif // UIMAINWIDGET_H
