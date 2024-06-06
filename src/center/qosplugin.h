#ifndef QOSPLUGIN_H
#define QOSPLUGIN_H

#include <Singleton.h>

class DaoClouds;
class QosPlugin: public Singleton<QosPlugin>
{
public:
    DaoClouds *cloud() const;

private:
    friend class Singleton<QosPlugin>;
    QosPlugin();
    void installPlugin();       // 向应用安装插件
    DaoClouds *cloud_;          // 云对象基类
};

#endif // QOSPLUGIN_H
