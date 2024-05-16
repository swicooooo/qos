#include "gateway.h"
#include "commonformat.h"
#include <Bucket.h>
#include <DaoCloudMock.h>
#include <thread>

void Gateway::send(int api, const QJsonValue &value)
{
    // 开启新线程分发前端发来的api请求
    std::thread([=](){
        this->dispatch(api, value);
    }).detach();
}

void Gateway::setLoginCallback(std::function<void (bool)> cb)
{
    loginCallback_ = cb;
}

void Gateway::dispatch(int api, const QJsonValue &value)
{
    switch (api)
    {
    case api::LOGIN:
        this->apiLogin(value);
        break;
    default:
        break;
    }
}

void Gateway::apiLogin(const QJsonValue &value)
{
    QString secretId = value["secretId"].toString();
    QString secretKey = value["secretKey"].toString();
    bool flag = false;
    auto cloud = new DaoCloudMock();
    QList<Bucket> buckets = cloud->login(secretId, secretKey, flag);
    loginCallback_(flag);    // 执行回调处理登录结果
}

