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
    // 点击桶名称进入对象列表, 有mainwidget更新stackwidget信息
    void on_tableView_doubleClicked(const QModelIndex &index);
    void onTableRowsChanged();
    void onPageNumChanged(int startRow, int count);

private:
    Ui::BucketsTableWidget *ui;
};

#endif // UIBUCKETSTABLEWIDGET_H
