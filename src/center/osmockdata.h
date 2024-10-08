#ifndef OSMOCKDATA_H
#define OSMOCKDATA_H

#include <QList>
#include <QMap>
#include <Singleton.h>
#include <entityclass.h>
#include "nlohmann/json.hpp"

class OSMockData : public Singleton<OSMockData>
{
public:
    friend class Singleton<OSMockData>;
    void mockData();        // 解包mock的各部分数据
    QMap<QString, QList<Bucket>> mockLocations() { return mockLocations_; };
    QMap<QString, QList<Object>> mockBucket() { return mockBucket_; }
    QList<User> mockUsers() { return mockUsers_; }

private:
    OSMockData();
    QMap<QString, QList<Bucket>> mockLocations_;  // 模拟位置信息集合
    QMap<QString, QList<Object>> mockBucket_;     // 模拟桶内的对象集合
    QList<User> mockUsers_;                       // 模拟登录用户集合
    nlohmann::json json_;;
};

#endif // OSMOCKDATA_H
