#ifndef DAOCLOUDS_H
#define DAOCLOUDS_H

#include <Bucket.h>

class DaoClouds
{
public:
    virtual QList<Bucket> buckets() = 0;
    virtual QList<Bucket> login(const QString &secretId,const QString &secretKey, bool &flag) = 0;
};

#endif // DAOCLOUDS_H
