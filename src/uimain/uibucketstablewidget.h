#ifndef UIBUCKETSTABLEWIDGET_H
#define UIBUCKETSTABLEWIDGET_H

#include <QWidget>

namespace Ui {
class BucketsTableWidget;
}

class UiBucketsTableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UiBucketsTableWidget(QWidget *parent = nullptr);
    ~UiBucketsTableWidget();
private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::BucketsTableWidget *ui;
};

#endif // UIBUCKETSTABLEWIDGET_H
