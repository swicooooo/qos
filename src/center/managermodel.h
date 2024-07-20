#ifndef MANAGERMODEL_H
#define MANAGERMODEL_H

#include "Singleton.h"

#include <entityclass.h>
#include <QStandardItemModel>

class ManagerModel: public Singleton<ManagerModel>
{
public:
    void setBuckets(const QList<Bucket> &buckets);  // 通过mock返回的buckets设置
    void setObjects(const QList<Object> &objects);  // 通过mock返回的buckets设置
    QStandardItemModel* modelBuckets() { return modelBuckets_; }
    QStandardItemModel *modelObjects() { return modelObjects_; };

    void initBucketsTable();    // 设置标题内容
    void initObjectsTable();    // 设置标题内容
private:
    ManagerModel();
    friend class Singleton<ManagerModel>; // Singleton
    QStandardItemModel *modelBuckets_;   // 存储桶表格模型
    QStandardItemModel *modelObjects_;   // 对象表格模型
};

#endif // MANAGERMODEL_H
