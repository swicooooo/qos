#include "uilogindialog.h"
#include "src/uimain/uimainwidget.h"

#include <UiBreadWidget.h>
#include <managermodel.h>
#include <FileHelper.h>
#include <UiPageWidget.h>
#include <QApplication>
#include <OSMockData.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // QApplication加载qss内容
    QString qssStr = FileHelper::readFileAll(":/static/default.qss");
    a.setStyleSheet(qssStr);

    OSMockData::instance()->mockData();

    UiLoginDialog w;
    int flag = w.exec();
    UiMainWidget m;
    if(flag == QDialog::Accepted)
    {
        m.show();
        return a.exec();
    }
    return 0;
}
