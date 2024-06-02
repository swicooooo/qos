#include "daocloudcos.h"
#include "qdebug.h"

DaoCloudCos::DaoCloudCos(const QString &path)
{

}

QList<Bucket> DaoCloudCos::buckets()
{
    QList<Bucket> res;
    bool result;
    // 调用cos的api获取service
    if(!result)
    {
        qDebug() << "cos occurred error!";
    }
    std::vector<Bucket> buckets;
    for (const auto &bucket : buckets) {
        Bucket b;
        b.name = bucket.name;
        b.location = bucket.location;
        b.createDate = bucket.createDate;
        res.append(b);
    }
    return res;
}

QList<Bucket> DaoCloudCos::login(const QString &secretId, const QString &secretKey, bool &flag)
{
    // 配置config后返回buckets()

    return buckets();
}

QList<Object> DaoCloudCos::objects()
{

}

void DaoCloudCos::getObjects(const QString &bucketName, const QString &dir)
{

}
