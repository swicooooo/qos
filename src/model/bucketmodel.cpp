#include "bucketmodel.h"

#include <Bucket.h>
#include <DaoCloudMock.h>
#include <DaoClouds.h>
#include <QosPlugin.h>

void BucketModel::setMockBuckets()
{
    // 获取buckets数据
    QList<Bucket> buckets = QosPlugin::instance()->cloud()->buckets();
    model_->setRowCount(buckets.size());
    model_->setColumnCount(3);  // 必须要先设定行列数才能添加数据
    // 填充数据到bucketModel中，绑定view实现实时更新
    for (int i = 0; i < buckets.size(); ++i) {
        model_->setData(model_->index(i, 0), buckets[i].name);
        model_->setData(model_->index(i, 1), buckets[i].location);
        model_->setData(model_->index(i, 2), buckets[i].createDate);
    }
    model_->sort(2, Qt::DescendingOrder);    // 根据创建时间降序排序
}

BucketModel::BucketModel()
{
    model_ = new QStandardItemModel();  // 向对象树模型注册对象分配内存
}
