#ifndef BASEDIALOG_H
#define BASEDIALOG_H

#include <QDialog>

namespace Ui {
class BaseDialog;
}

class BaseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BaseDialog(QWidget *parent = nullptr);
    ~BaseDialog();

    // 设置窗口基本信息
    void setTitle(const QString &title);        // 设置标题文本
    void setLogo(const QString &path);          // 设置logo图片路径

    // 设置窗口最大化和最小化按钮
    void addMinButton(const QString &path,const QString &hoverPath);
    void addMaxButton(const QString &maxPath, const QString &maxPathHover,
                      const QString &normalPath, const QString &normalPathHover);

    // 操作button相关参数
    QPushButton* addButton(const QString &path, const QString &hoverPath);
    void setButtonImage(QPushButton *btn, const QString &path, const QString &hoverPath);
    void setAllButtonSize(int w = 20);          // 设置所有button的大小
protected:
    Ui::BaseDialog *base_ui;                            // 让子类继承使用
    void mousePressEvent(QMouseEvent *event) override;  // 重写鼠标按下事件
    void mouseMoveEvent(QMouseEvent *event) override;   // 重写鼠标移动事件
    QWidget* body();
private:
    void addCloseButton(const QString &path, const QString &hoverPath); // 添加关闭按钮图片和悬浮图片
    QPoint startPos_;                           // 鼠标的起始位置
    int recordSize_;                            // 记录默认button大小，为新添加的button设置
};

#endif // BASEDIALOG_H
