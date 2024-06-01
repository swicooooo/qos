#ifndef PUBLIC_H
#define PUBLIC_H

#include <QString>

namespace global
{
namespace path
{
    static const QString LOGO_PATH = ":/static/logo.png";
    static const QString MAX_PATH = ":/static/logo.png";
    static const QString MAX_HOVER_PATH = ":/static/logo.png";
    static const QString NORMLA_PATH = ":/static/logo.png";
    static const QString NORMLA_HOVER_PATH = ":/static/logo.png";
    static const QString MIN_PATH = ":/static/logo.png";
    static const QString MIN_HOVER_PATH = ":/static/logo.png";

    static const QString TRAN_PATH = ":/static/tran.svg";
    static const QString TRAN_HOVER_PATH = ":/static/tran.svg";
    static const QString QUIT_PATH = ":/static/quit.svg";
    static const QString QUIT_HOVER_PATH = ":/static/quit.svg";
};
namespace api {
    /// 工具栏button的类型
    enum EnButtonType
    {
        CREATE_BUCKET = 1,
        UPLOAD_FILE,
        DOWNLOAD_FILE,
        REFRESH_PAGE,
        TRANSLATE_LIST,
        SIGN_OUT,
    };
    /// 网关分流的api类型
    enum LOGIN
    {
        NORMAL = 1,
    };
    enum BUCKETS
    {
        BLIST = 2,
        BPUT,
        BDEL
    };
    enum OBJECTS
    {
        OLIST = 5,
        OPUT,
        ODEL
    };
};
}

#endif // PUBLIC_H
