#ifndef BUCKETMODEL_H
#define BUCKETMODEL_H

#include "Singleton.h"

#include <QStandardItemModel>

class BucketModel: public Singleton<BucketModel>
{
public:
    void setMockBuckets();
    QStandardItemModel* model() { return model_; }

private:
    BucketModel();
    friend class Singleton<BucketModel>; // Singleton
    QStandardItemModel *model_;
};

#endif // BUCKETMODEL_H
