#ifndef UIBUCKETDELEAGTE_H
#define UIBUCKETDELEAGTE_H

#include <QStyledItemDelegate>

class UiBucketDeleagte : public QStyledItemDelegate
{
    Q_OBJECT
public:
    UiBucketDeleagte(QObject *parent = nullptr);
    /// 三个重写方法来修改数据
    // editing  创建一个控件
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;
    // 设置对应控件数据
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    // 设置对应模型数据
    void setModelData(QWidget *editor,
                      QAbstractItemModel *model,
                      const QModelIndex &index) const override;
};

#endif // UIBUCKETDELEAGTE_H
