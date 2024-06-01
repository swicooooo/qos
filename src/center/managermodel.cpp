#include "managermodel.h"

#include <entityclass.h>
#include <DaoCloudMock.h>
#include <DaoClouds.h>
#include <QosPlugin.h>

void ManagerModel::setMockBuckets()
{
    // 获取buckets数据
    QList<Bucket> buckets = QosPlugin::instance()->cloud()->buckets();
    modelBuckets_->setRowCount(buckets.size());
    modelBuckets_->setColumnCount(3);  // 必须要先设定行列数才能添加数据
    // 填充数据到bucketModel中，绑定view实现实时更新
    for (int i = 0; i < buckets.size(); ++i) {
        modelBuckets_->setData(modelBuckets_->index(i, 0), buckets[i].name);
        modelBuckets_->setData(modelBuckets_->index(i, 1), buckets[i].location);
        modelBuckets_->setData(modelBuckets_->index(i, 2), buckets[i].createDate);
    }
    modelBuckets_->sort(2, Qt::DescendingOrder);    // 根据创建时间降序排序
}

void ManagerModel::setMockObjects()
{
    // 获取objects数据
    QList<Object> objects = QosPlugin::instance()->cloud()->objects();
    modelObjects_->setRowCount(objects.size());
    modelObjects_->setColumnCount(3);  // 必须要先设定行列数才能添加数据
    // 填充数据到objectModel中，绑定view实现实时更新
    for (int i = 0; i < objects.size(); ++i) {
        modelObjects_->setData(modelObjects_->index(i, 0), objects[i].name);
        modelObjects_->setData(modelObjects_->index(i, 1), objects[i].size);
        modelObjects_->setData(modelObjects_->index(i, 2), objects[i].lastmodified);
    }
}

void ManagerModel::initBucketsTable()
{
    // 设置标题内容
    QStringList labels;
    labels << QString("bucket_name") << QString("location") << QString("create_time");
    modelBuckets_->setHorizontalHeaderLabels(labels);
}

void ManagerModel::initObjectsTable()
{
    // 设置标题内容
    QStringList labels;
    labels << QString("object_name") << QString("size") << QString("update_time");
    modelObjects_->setHorizontalHeaderLabels(labels);
}

ManagerModel::ManagerModel()
{
    modelBuckets_ = new QStandardItemModel();  // 向对象树模型注册对象分配内存
    modelObjects_ = new QStandardItemModel();  // 向对象树模型注册对象分配内存
    initBucketsTable();
    initObjectsTable();
}
