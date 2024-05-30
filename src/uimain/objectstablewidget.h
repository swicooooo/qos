#ifndef OBJECTSTABLEWIDGET_H
#define OBJECTSTABLEWIDGET_H

#include <QWidget>

namespace Ui {
class ObjectsWidget;
}

class ObjectsTableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ObjectsTableWidget(QWidget *parent = nullptr);
    ~ObjectsTableWidget();

private:
    Ui::ObjectsWidget *ui;
};

#endif // OBJECTSTABLEWIDGET_H
