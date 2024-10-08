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

private slots:
    void on_pushButtonBuckets_clicked();
    void onTableRowsChanged();
    void onPageNumChanged(int startRow, int count);

private:
    Ui::ObjectsWidget *ui;
};

#endif // UIOBJECTSTABLEWIDGET_H
