#ifndef UIQOSDIALOG_H
#define UIQOSDIALOG_H

#include <UiBaseDialog.h>

namespace Ui {
class QosDialog;
}

class UiQosDialog : public UiBaseDialog
{
    Q_OBJECT

public:
    explicit UiQosDialog(QWidget *parent = nullptr);
    ~UiQosDialog();

private:
    Ui::QosDialog *ui;
};

#endif // UIQOSDIALOG_H
