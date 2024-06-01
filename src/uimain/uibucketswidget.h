#ifndef UIBUCKETSWIDGET_H
#define UIBUCKETSWIDGET_H

#include <QWidget>

namespace Ui {
class BucketsWidget;
}

class UiBucketsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UiBucketsWidget(QWidget *parent = nullptr);
    ~UiBucketsWidget();

private slots:
    void on_listView_doubleClicked(const QModelIndex &index);

private:
    Ui::BucketsWidget *ui;
};

#endif // UIBUCKETSWIDGET_H
