#include "qosplugin.h"

#include <DaoCloudCos.h>

void QosPlugin::installPlugin()
{
    // cloud_ = new DaoCloudMock(":/static/mockTest.json");
    cloud_ = new DaoCloudCos("");
}

QosPlugin::QosPlugin()
{
    this->installPlugin();
}

DaoClouds *QosPlugin::cloud() const
{
    return cloud_;
}
