#include "uilogindialog.h"
#include "src/uimain/uimainwidget.h"

#include <UiBreadWidget.h>
#include <BucketModel.h>
#include <FileHelper.h>
#include <UiPageWidget.h>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // QApplication加载qss内容
    QString qssStr = FileHelper::readFileAll(":/static/default.qss");
    a.setStyleSheet(qssStr);

    UiLoginDialog w;
    int flag = w.exec();
    BucketModel::instance()->setMockBuckets();
    UiMainWidget m;
    if(flag == QDialog::Accepted)
    {
        m.show();
        return a.exec();
    }
    return 0;
}
