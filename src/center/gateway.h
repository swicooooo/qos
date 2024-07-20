#ifndef GATEWAY_H
#define GATEWAY_H

#include "Singleton.h"
#include <entityclass.h>
#include <functional>
#include <nlohmann/json.hpp>
#include "Public.h"

class Gateway: public Singleton<Gateway>
{
public:
    void send(int api, const nlohmann::json &params);    // 向后端发送api请求
    void setLoginCallback(std::function<void(bool,QList<Bucket>&)>cb) {loginCallback_ = cb;};
    void setStackChangeCallback(std::function<void(int)> cb) {stackChangeCallback_ = cb;};

private:
    friend class Singleton<Gateway>;
    Gateway() = default;
    void dispatch(int api, const nlohmann::json &params);// 分流api请求
    void apiLogin(const nlohmann::json &params);         // 登录请求
    void apiGetBuckets(const nlohmann::json &params);    // 桶操作请求列表
    void apiGetObjects(const nlohmann::json &params);    // 对象操作请求列表
    std::function<void(bool,QList<Bucket>&)> loginCallback_;  // 登录后的回调函数,用于解决ui层不知道登录结果
    std::function<void(bool)> stackChangeCallback_;          // 切换stackwidget页面的回调
};

#endif // GATEWAY_H
