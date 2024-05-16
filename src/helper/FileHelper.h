#ifndef FILEHELPER_H
#define FILEHELPER_H

#include <QFile>
#include <QJsonDocument>
#include <QString>

/// 文件操作的类
class FileHelper
{
public:
    static QString readFileAll(const QString &path)
    {
        QFile file(path);
        if (file.open(QIODevice::ReadOnly))
        {
            auto bytes = file.readAll();
            file.close();
            return QString::fromUtf8(bytes);
        }
        throw "read file error!!!";
    }
};

#endif // FILEHELPER_H
