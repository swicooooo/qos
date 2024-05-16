#include "bucketdeleagte.h"

#include <QComboBox>

BucketDeleagte::BucketDeleagte(QObject *parent)
    : QStyledItemDelegate(parent)
{}

QWidget *BucketDeleagte::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QComboBox *box = new QComboBox(parent); // 挂载对象树
    box->addItem("ap-beijing");
    box->addItem("ap-shanghai");
    box->addItem("ap-guangzhou");
    box->setFrame(false);
    return box;
}

void BucketDeleagte::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    auto box = static_cast<QComboBox*>(editor);
    box->setCurrentText(index.data().toString());
}

void BucketDeleagte::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    auto box = static_cast<QComboBox*>(editor);
    model->setData(index, box->currentText());
}
