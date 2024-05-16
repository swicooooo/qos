#ifndef DAOCLOUDMOCK_H
#define DAOCLOUDMOCK_H

#include <DaoClouds.h>
#include <QJsonDocument>

class DaoCloudMock: public DaoClouds
{
public:
    DaoCloudMock();
    QList<Bucket> buckets() override;
    QList<Bucket> login(const QString &secretId,const QString &secretKey, bool &flag)override;
private:
    QJsonDocument doc_;
};

#endif // DAOCLOUDMOCK_H
