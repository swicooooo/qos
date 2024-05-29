#ifndef BREADWIDGET_H
#define BREADWIDGET_H

#include "qstandarditemmodel.h"
#include <QWidget>

namespace Ui {
class BreadWidget;
}

/// 通过mvc控制显示面包屑导航
/// 从外界设置path时，切分更新model里面的row数据，并添加新的item项
/// 当用户点击listview里面的item时，获取当前路径发出信号并去除后面的面包屑
class BreadWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BreadWidget(QWidget *parent = nullptr);
    ~BreadWidget();

    // 设置面包屑路径，通过完整路径或者名称列表
    void setPath(const QString &path);
    void setPath(const QStringList &names);

    // get set方法
    QString currentPath()const;
    QString rootName()const;
    bool isEmpty()const;
    bool isRoot()const;
signals:
    void refresh(const QString &path);
    void pathChanged(const QString &newPath);
private:
    void onItemClicked(const QModelIndex &idx);             // 当item被点击后触发,删除后面的面包屑
    void addNameButton(const QString &name);                // 添加一块面包屑按钮
    QStandardItem* currentItem()const;                      // 获取当前item
    QString getPath(QStandardItem *item = nullptr)const;    // 根据item获取当前节点到根节点的路径
    Ui::BreadWidget *ui;
    QString rootName_;      // 根目录
    std::unique_ptr<QStandardItemModel> model_;
};

#endif // BREADWIDGET_H
