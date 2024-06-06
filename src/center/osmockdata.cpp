#include "osmockdata.h"
#include <FileHelper.h>

QList<Bucket> OSMockData::mockBuckets()
{
    QList<Bucket> res;
    std::vector<nlohmann::json> arr = json_["buckets"];
    for (const auto &a : arr)
    {
        Bucket bucket;
        bucket.name = QString::fromStdString(a["name"]);
        bucket.location = QString::fromStdString(a["location"]);
        bucket.createDate = QString::fromStdString(a["create_date"]);
        res.append(bucket);
        qDebug() << bucket.name << bucket.location << bucket.createDate;
    }
    return res;
}

QList<Object> OSMockData::mockObjects()
{
    QList<Object> res;
    std::vector<nlohmann::json> arr = json_["objects"];
    for (const auto &a : arr)
    {
        Object object;
        object.name = QString::fromStdString(a["name"]);
        object.lastmodified = QString::fromStdString(a["lastmodified"]);
        object.size = a["size"].get<int>();
        res.append(object);
        qDebug() << object.name << object.lastmodified << object.size;
    }
    return res;
}

QList<User> OSMockData::mockUsers()
{
    QList<User> res;
    std::vector<nlohmann::json> arr = json_["users"];
    for (const auto &a : arr)
    {
        User user;
        user.secretId = QString::fromStdString(a["secretId"]);
        user.secretKey = QString::fromStdString(a["secretKey"]);
        res.append(user);
        qDebug() << user.secretId << user.secretKey;
    }
    return res;
}

QMap<QString, QList<QString>> OSMockData::mockLocations()
{
    QMap<QString, QList<QString>> res;
    for (const auto &location : json_["locations"].items())
    {
        QList<QString> values;
        for (const auto &bucket : location.value())
        {
            values.push_back(QString::fromStdString(bucket.dump()));
        }
        res.insert(location.key().data(), values);
        qDebug() << location.key().data() << values;
    }
    return res;
}

OSMockData::OSMockData()
{
    json_ = nlohmann::json::parse(FileHelper::readFileAll(":/static/mockTest.json").toStdString());
}
