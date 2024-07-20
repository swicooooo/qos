#include "osmockdata.h"
#include <FileHelper.h>

/**
 * @brief OSMockData::mockData
 * location--buckets    map<string,list<bucket>>
 * bucket--objects      map<string,list<object>>
 */
void OSMockData::mockData()
{
    // 解析user部分
    std::vector<nlohmann::json> users = json_["users"];
    for (const auto &u : users)
    {
        User user;
        user.secretId = QString::fromStdString(u["secretId"]);
        user.secretKey = QString::fromStdString(u["secretKey"]);
        mockUsers_.append(user);
        qDebug() << user.secretId << user.secretKey;
    }

    // 解析location--buckets部分
    for (const auto &l : json_["locations"].items())
    {
        QList<Bucket> buckets;
        for (const auto &b : l.value())
        {
            // 解析bucket对象
            Bucket bucket;
            bucket.name = QString::fromStdString(b["bucketname"]);
            bucket.location = QString::fromStdString(b["location"]);
            bucket.createDate = QString::fromStdString(b["create_date"]);
            qDebug() << bucket.name << bucket.location << bucket.createDate;
            buckets.push_back(bucket);

            // 解析bucket--objects部分
            QList<Object> objects;
            for(const auto &o :  b["objects"])
            {
                Object object;
                object.name = QString::fromStdString(o["objectname"]);
                object.lastmodified = QString::fromStdString(o["lastmodified"]);
                object.size = o["size"].get<int>();
                object.dir = QString::fromStdString(o["dir"]);
                qDebug() << object.name << object.lastmodified << object.size << object.dir;
                objects.push_back(object);
            }
            // 组装
            mockBucket_.insert(bucket.name, objects);
        }
        mockLocations_.insert(QString::fromStdString(l.key()), buckets);
    }
}

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

QMap<QString, QList<Object>> OSMockData::mockObjects()
{
    QMap<QString, QList<Object>> res;
    for (const auto &object : json_["objects"].items())
    {
        QList<Object> values;
        for (const auto &object : object.value())
        {
            Object o;
            o.name = QString::fromStdString(object["name"]);
            o.lastmodified = QString::fromStdString(object["lastmodified"]);
            o.size = object["size"].get<int>();
            o.dir = QString::fromStdString(object["dir"]);
            values.push_back(o);
        }
        res.insert(object.key().data(), values);
        // print
        qDebug() << object.key().data();
        for (const auto &v : values)
        {
            qDebug() << v.name << v.lastmodified << v.size << v.dir;
        }
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
