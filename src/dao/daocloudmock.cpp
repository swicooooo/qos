#include "daocloudmock.h"
#include "osmockdata.h"

DaoCloudMock::DaoCloudMock(const QString &path)
{}

QList<Bucket> DaoCloudMock::buckets()
{
    return OSMockData::instance()->mockBuckets();
}

QList<Object> DaoCloudMock::objects()
{
    return OSMockData::instance()->mockObjects();
}

QList<Bucket> DaoCloudMock::login(const QString &secretId, const QString &secretKey, bool &flag)
{
    // TODO 登录操作，向数据请求数据
    // auto users = OSMockData::instance()->mockUsers();
    // for(const auto &u : users)
    // {
    //     if(u.secretId == secretId && u.secretKey == secretKey)
    //     {
    //         // TODO 返回true，返回buckets，在ui端设置Buckets数据
    //     }
    // }
    flag = true;
    return this->buckets();
}

bool DaoCloudMock::isBucketExists(const QString &bucketName)
{
    for(const auto &b : this->buckets())
    {
        if(b.name == bucketName) return true;
    }
    return false;
}

QString DaoCloudMock::getBucketLocation(const QString &bucketName)
{
    auto locations = OSMockData::instance()->mockLocations();
    for (auto it = locations.constBegin(); it != locations.constEnd(); ++it)
    {
        if(it.value().contains(bucketName))
        {
            return it.key();
        }
    }
    return QString();
}

void DaoCloudMock::putBucket(const QString &bucketName, const QString &location)
{
    if(isBucketExists(bucketName))
    {
        return;
    }
    // TODO上传文件

}

void DaoCloudMock::deleteBucket(const QString &bucketName)
{
    if(!isBucketExists(bucketName))
    {
        return;
    }
    // TODO 删除文件
    QString location = getBucketLocation(bucketName);
}

void DaoCloudMock::getObjects(const QString &bucketName, const QString &dir)
{

}
