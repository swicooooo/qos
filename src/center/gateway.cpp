#include "gateway.h"
#include <entityclass.h>
#include <DaoCloudMock.h>
#include <QosPlugin.h>
#include <thread>
#include <qlist.h>

void Gateway::send(int api, const nlohmann::json &params)
{
    // 开启新线程分发前端发来的api请求
    std::thread([=](){
        switch (api)
        {
        case global::api::LOGIN::NORMAL:
            this->apiLogin(params);
            break;
        case global::api::BUCKETS::BLIST:
            this->apiGetBuckets(params);
            break;
        case global::api::OBJECTS::OLIST:
            this->apiGetObjects(params);
            break;
        default:
            break;
        }
    }).detach();
}

void Gateway::apiLogin(const nlohmann::json &params)
{
    QString secretId = QString::fromStdString(params["secretId"]);
    QString secretKey = QString::fromStdString(params["secretKey"]);
    bool flag = false;
    QList<Bucket> buckets = QosPlugin::instance()->cloud()->login(secretId, secretKey, flag);
    loginCallback_(flag, buckets);    // 执行回调处理登录结果
}

void Gateway::apiGetBuckets(const nlohmann::json &params)
{
    QList<Object> objects;
    stackChangeCallback_(0, objects);
}

void Gateway::apiGetObjects(const nlohmann::json &params)
{
    QString bucketName = QString::fromStdString(params["name"]);
    QString dir = QString::fromStdString(params["dir"]);
    QList<Object> objects = QosPlugin::instance()->cloud()->getObjects(bucketName, dir);
    stackChangeCallback_(1, objects);
}

