#include "daocloudmock.h"

#include <FileHelper.h>
#include <QJsonArray>
#include <QVariant>
#include <qjsonobject.h>

DaoCloudMock::DaoCloudMock()
{
    doc_ = QJsonDocument::fromJson(FileHelper::readFileAll(":/static/bucketsTest.json").toUtf8());
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
    // 无法读取对象
    flag = true;
    return this->buckets();
}
