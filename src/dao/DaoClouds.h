#ifndef DAOCLOUDS_H
#define DAOCLOUDS_H

#include <entityclass.h>

class DaoClouds
{
public:
    /// 获取buckets和objects数据的函数
    virtual QList<Bucket> buckets() = 0;
    virtual QList<Object> objects() = 0;

    /// 登录
    virtual QList<Bucket> login(const QString &secretId,const QString &secretKey, bool &flag) = 0;

    /// bucket操作相关函数
    virtual bool isBucketExists(const QString &bucketName) = 0;
    virtual QString getBucketLocation(const QString &bucketName) = 0;
    virtual void putBucket(const QString &bucketName,const QString &location) = 0;
    virtual void deleteBucket(const QString &bucketName) = 0;

    /// 桶内的每条都是一个对象，如果是文件夹则其中还有对象
    virtual void getObjects(const QString &bucketName, const QString &dir) = 0;
};

#endif // DAOCLOUDS_H
