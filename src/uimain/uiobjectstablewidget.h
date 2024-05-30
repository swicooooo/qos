#ifndef UIOBJECTSTABLEWIDGET_H
#define UIOBJECTSTABLEWIDGET_H

#include <QWidget>

namespace Ui {
class ObjectsWidget;
}

class UiObjectsTableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UiObjectsTableWidget(QWidget *parent = nullptr);
    ~UiObjectsTableWidget();

private:
    Ui::ObjectsWidget *ui;
};

#endif // UIOBJECTSTABLEWIDGET_H
