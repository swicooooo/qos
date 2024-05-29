#include "logindialog.h"
#include "src/uimain/mainwidget.h"

#include <BreadWidget.h>
#include <BucketModel.h>
#include <FileHelper.h>
#include <PageWidget.h>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // QApplication加载qss内容
    // QString qssStr = FileHelper::readFileAll(":/static/default.qss");
    // a.setStyleSheet(qssStr);

    // LoginDialog w;
    // int flag = w.exec();
    // BucketModel::instance()->setMockBuckets();
    // MainWidget m;
    // if(flag == QDialog::Accepted)
    // {
    //     m.show();
    //     return a.exec();
    // }
    PageWidget w;
    w.setMaxRowList(QList<int>() << 10 << 50 << 100);
    w.setTotalRow(330);
    w.show();
    return a.exec();
    // return 0;
}
