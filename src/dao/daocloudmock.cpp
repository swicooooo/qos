#include "daocloudmock.h"

#include <FileHelper.h>

DaoCloudMock::DaoCloudMock(const QString &path)
{
    json_ = nlohmann::json::parse(FileHelper::readFileAll(path).toStdString());
}

QList<Bucket> DaoCloudMock::buckets()
{
    QList<Bucket> res;
    std::vector<nlohmann::json> arr = json_["buckets"];
    for (const auto &a : arr) {
        Bucket bucket;
        bucket.name = QString::fromStdString(a["name"]);
        bucket.location = QString::fromStdString(a["location"]);
        bucket.createDate = QString::fromStdString(a["create_date"]);
        res.append(bucket);
        qDebug() << bucket.name << bucket.location << bucket.createDate;
    }
    return res;
}

QList<Object> DaoCloudMock::objects()
{
    QList<Object> res;
    std::vector<nlohmann::json> arr = json_["objects"];
    for (const auto &a : arr) {
        Object object;
        object.name = QString::fromStdString(a["name"]);
        object.lastmodified = QString::fromStdString(a["lastmodified"]);
        object.size = a["size"].get<int>();
        res.append(object);
        qDebug() << object.name << object.lastmodified << object.size;
    }
    return res;
}

QList<Bucket> DaoCloudMock::login(const QString &secretId, const QString &secretKey, bool &flag)
{
    // TODO 登录操作，向数据请求数据
    flag = true;
    return this->buckets();
}

void DaoCloudMock::getObjects(const QString &bucketName, const QString &dir)
{

}
