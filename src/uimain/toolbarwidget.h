#ifndef TOOLBARWIDGET_H
#define TOOLBARWIDGET_H

#include <QWidget>

namespace Ui {
class ToolBarWidget;
}

class ToolBarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ToolBarWidget(QWidget *parent = nullptr);
    ~ToolBarWidget();

signals:
    void buttonClick(int id);

private:
    Ui::ToolBarWidget *ui;
};

#endif // TOOLBARWIDGET_H
