#include "osmockdata.h"
#include <FileHelper.h>

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

OSMockData::OSMockData()
{
    json_ = nlohmann::json::parse(FileHelper::readFileAll(":/static/mockTest.json").toStdString());
}
