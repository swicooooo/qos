#ifndef ENTITYCLASS_H
#define ENTITYCLASS_H

#include <QString>

struct BaseObject
{
    bool isValid()const { return !isInvalid(); }
    bool isInvalid()const { return name.isNull() || name.isEmpty(); }
    QString name;
};

/// 表示bucket信息的类
struct Bucket : public BaseObject
{
    QString location;
    QString createDate;
};

/// 表示object信息的类
struct Object : public BaseObject
{
    QString lastmodified;
    qulonglong size = 0;
    QString dir;
};

/// 表示登录用户信息的类
struct User
{
    QString secretId;
    QString secretKey;
};

#endif // ENTITYCLASS_H
