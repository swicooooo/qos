#include "qosplugin.h"

#include <DaoCloudMock.h>

void QosPlugin::installPlugin()
{
    cloud_ = new DaoCloudMock(":/static/bucketsTest.json");
}

QosPlugin::QosPlugin()
{
    this->installPlugin();
}

DaoClouds *QosPlugin::cloud() const
{
    return cloud_;
}
