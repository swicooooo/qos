#ifndef COMMONFORMAT_H
#define COMMONFORMAT_H

/// 工具栏button的类型
namespace btn
{
    enum EnButtonType
    {
        CREATE_BUCKET = 1,
        UPLOAD_FILE,
        DOWNLOAD_FILE,
        REFRESH_PAGE,
        TRANSLATE_LIST,
        SIGN_OUT,
    };
}
/// 网关分流的api类型
namespace api
{
    enum EnAPIType
    {
        LOGIN = 1,
    };
}

#endif // COMMONFORMAT_H
