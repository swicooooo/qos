#include "logindialog.h"
#include "src/uimain/mainwidget.h"

#include <BucketModel.h>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // LoginDialog w;
    // int flag = w.exec();
    BucketModel::instance()->setMockBuckets();
    MainWidget m;
    // if(flag == QDialog::Accepted)
    // {
        m.show();
        return a.exec();
    // }
    // return 0;
}
