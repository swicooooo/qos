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
    void installPlugin();
    QosPlugin();
    DaoClouds *cloud_;
};

#endif // QOSPLUGIN_H
