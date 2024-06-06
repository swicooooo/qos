#ifndef DAOCLOUDMOCK_H
#define DAOCLOUDMOCK_H

#include <DaoClouds.h>

class DaoCloudMock: public DaoClouds
{
public:
    DaoCloudMock(const QString &path);
    QList<Bucket> buckets() override;
    QList<Object> objects() override;   // 直接模拟
    QList<Bucket> login(const QString &secretId,const QString &secretKey, bool &flag)override;

    bool isBucketExists(const QString &bucketName)override;
    QString getBucketLocation(const QString &bucketName)override;
    void putBucket(const QString &bucketName,const QString &location)override;
    void deleteBucket(const QString &bucketName)override;

    void getObjects(const QString &bucketName, const QString &dir)override;
};

#endif // DAOCLOUDMOCK_H
