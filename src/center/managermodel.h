#ifndef MANAGERMODEL_H
#define MANAGERMODEL_H

#include "Singleton.h"

#include <entityclass.h>
#include <QStandardItemModel>

class ManagerModel: public Singleton<ManagerModel>
{
public:
    void setMockBuckets();  // 模拟buckets数据
    void setMockObjects();  // 模拟objects数据
    void setBuckets(const QList<Bucket> &buckets);  // 通过云服务返回的buckets设置
    void setObjects(const QList<Object> &buckets);  // 通过云服务返回的objects设置
    QStandardItemModel* modelBuckets() { return modelBuckets_; }
    QStandardItemModel *modelObjects() { return modelObjects_; };

    void initBucketsTable();
    void initObjectsTable();
private:
    ManagerModel();
    friend class Singleton<ManagerModel>; // Singleton
    QStandardItemModel *modelBuckets_;   // 存储桶表格模型
    QStandardItemModel *modelObjects_;   // 对象表格模型
};

#endif // MANAGERMODEL_H
