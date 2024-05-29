#ifndef COMBOLINE_H
#define COMBOLINE_H

#include <QLineEdit>
#include <QObject>

// QCompleter这个类可以和QLineEdit组合实现自动补全功能
class ComboLine : public QLineEdit
{
    Q_OBJECT
public:
    ComboLine(QWidget *parent = nullptr);
    ComboLine(const QStringList &words, QWidget *parent = nullptr);

    // 设置和获取提示列表
    void setWords(const QStringList &words);    // 登录窗口的提示列表
    void setWords(const QList<int> words);      // 跳转页码选择的提示列表
    void setWords(int start=1, int len=10);     // 所有页码选择的提示列表
    QStringList getWords();

signals:
    void itemSelected(const QString &text);         // 当item被选中的信号
protected:
    void mousePressEvent(QMouseEvent *e)override;
};

#endif // COMBOLINE_H
