#include "daocloudmock.h"

#include <FileHelper.h>
#include <QJsonArray>
#include <QVariant>
#include <qjsonobject.h>

DaoCloudMock::DaoCloudMock(const QString &path)
{
    doc_ = QJsonDocument::fromJson(FileHelper::readFileAll(path).toUtf8());
}

QList<Bucket> DaoCloudMock::buckets()
{
    QList<Bucket> res;
    QJsonArray arr = doc_.array();
    for (int i = 0; i < arr.count(); ++i) {
        QJsonValue v = arr[i];
        Bucket bucket;
        bucket.name = v["name"].toString();
        bucket.location = v["location"].toString();
        bucket.createDate = v["create_date"].toString();
        res.append(bucket);
    }
    return res;
}

QList<Bucket> DaoCloudMock::login(const QString &secretId, const QString &secretKey, bool &flag)
{
    // TODO 登录操作，向数据请求数据
    flag = true;
    return this->buckets();
}
