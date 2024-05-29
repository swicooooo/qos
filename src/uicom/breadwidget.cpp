#include "breadwidget.h"
#include "qdebug.h"
#include "ui_breadwidget.h"

BreadWidget::BreadWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BreadWidget)
    , model_(new QStandardItemModel())
{
    ui->setupUi(this);
    // 设置listview属性
    ui->listView->setFlow(QListView::LeftToRight);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listView->setStyleSheet("QListView{border: none;}");
    ui->listView->setModel(model_.get());
    setPath("");
    // 当listview的item被点击后切换目录
    connect(ui->listView, &QListView::clicked, this, &BreadWidget::onItemClicked);
    setFixedHeight(30);
}

BreadWidget::~BreadWidget()
{
    delete ui;
}

void BreadWidget::setPath(const QString &path)
{
    setPath(path.split("/",Qt::SkipEmptyParts));    // 拆分为名称列表处理
}

void BreadWidget::setPath(const QStringList &names)
{
    // 如果名称列表存在则处理
    if(!names.empty())
    {
        model_->clear();
        rootName_ = names[0];
        for(const QString &name : names)
        {
            addNameButton(name.trimmed());
        }
    }
}

QString BreadWidget::currentPath() const
{
    return getPath();
}

QString BreadWidget::rootName() const
{
    return rootName_;
}

bool BreadWidget::isEmpty() const
{
    return model_->rowCount() == 0;
}

bool BreadWidget::isRoot() const
{
    return getPath() == rootName_;
}

void BreadWidget::addNameButton(const QString &name)
{
    if(!name.isEmpty())
    {
        QStandardItem *item = new QStandardItem;
        item->setText(name);
        if(!isEmpty())
        {
            item->setIcon(QIcon(":/static/breadIcon.svg"));   // 设置右箭头icon
        }
        model_->appendRow(item);
    }
}

void BreadWidget::onItemClicked(const QModelIndex &idx)
{
    // 获取被点击的item
    QStandardItem *newItem = model_->itemFromIndex(idx);
    QStandardItem *oldItem = currentItem();

    // 如果点击当前路径的item，发出刷新页面信号
    if(newItem == oldItem)
    {
        emit refresh(getPath(oldItem));
        qDebug() << "refresh" << getPath(oldItem);
    }
    else
    {
        // 否则发出路径改变的信号，并且删除后面的面包屑
        int row = newItem->row();
        model_->removeRows(row+1, model_->rowCount()-(row+1));
        emit pathChanged(getPath(newItem));
        qDebug() << "pathChanged" << getPath(newItem);
    }
}

QStandardItem *BreadWidget::currentItem() const
{
    return model_->item(model_->rowCount()-1);
}

QString BreadWidget::getPath(QStandardItem *item) const
{
    // item不存在，直接赋值为当前item
    if(!item)
    {
        item = currentItem();
    }
    // 通过当前item索引获取前面的所有面包屑
    QStringList paths;
    for (int i = 0; i <= item->row(); ++i) {
        auto b = model_->item(i);
        if(b)
        {
            paths << b->text();
        }
    }
    return paths.join("/");
}
