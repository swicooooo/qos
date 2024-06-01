#ifndef DAOCLOUDMOCK_H
#define DAOCLOUDMOCK_H

#include "nlohmann/json.hpp"
#include <DaoClouds.h>

class DaoCloudMock: public DaoClouds
{
public:
    DaoCloudMock(const QString &path);
    QList<Bucket> buckets() override;
    QList<Object> objects() override;
    QList<Bucket> login(const QString &secretId,const QString &secretKey, bool &flag)override;

    void getObjects(const QString &bucketName, const QString &dir)override;
private:
    nlohmann::json json_;;
};

#endif // DAOCLOUDMOCK_H
