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
    QList<Bucket> mockBuckets();                    // 模拟桶集合
    QList<Object> mockObjects();                    // 模拟桶内的对象集合
    QList<User> mockUsers();                        // 模拟登录用户集合
    QMap<QString, QList<QString>> mockLocations();  // 模拟登录用户集合

private:
    OSMockData();
    nlohmann::json json_;;
};

#endif // OSMOCKDATA_H
