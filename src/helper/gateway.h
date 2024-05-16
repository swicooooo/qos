#ifndef GATEWAY_H
#define GATEWAY_H

#include "Singleton.h"

#include <QJsonValue>
#include <functional>

class Gateway: public Singleton<Gateway>
{
public:
    void send(int api, const QJsonValue &value);    // 向后端发送api请求
    void setLoginCallback(std::function<void(bool)>);
private:
    friend class Singleton<Gateway>;
    Gateway() = default;
    void dispatch(int api, const QJsonValue &value);// 分流api请求
    void apiLogin(const QJsonValue &value);         // 登录请求
    std::function<void(bool)> loginCallback_;       // 登录后的回调函数,用于解决ui层不知道登录结果
};

#endif // GATEWAY_H
