#ifndef DAOCLOUDCOS_H
#define DAOCLOUDCOS_H

#include <DaoClouds.h>
#include <QList>

class DaoCloudCos: public DaoClouds
{
public:
    DaoCloudCos(const QString &path);
    QList<Bucket> buckets() override;
    QList<Bucket> login(const QString &secretId,const QString &secretKey, bool &flag)override;

    // TODO
    QList<Object> objects() override;
    void getObjects(const QString &bucketName, const QString &dir)override;
};

#endif // DAOCLOUDCOS_H
