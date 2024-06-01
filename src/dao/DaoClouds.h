#ifndef DAOCLOUDS_H
#define DAOCLOUDS_H

#include <entityclass.h>

class DaoClouds
{
public:
    virtual QList<Bucket> buckets() = 0;
    virtual QList<Object> objects() = 0;
    virtual QList<Bucket> login(const QString &secretId,const QString &secretKey, bool &flag) = 0;

    virtual void getObjects(const QString &bucketName, const QString &dir) = 0;
};

#endif // DAOCLOUDS_H
