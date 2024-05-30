#include "uicomboline.h"
#include "qabstractitemview.h"

#include <QCompleter>

UiComboLine::UiComboLine(QWidget *parent)
    : QLineEdit(parent)
{
    UiComboLine(QStringList(),nullptr);
}

UiComboLine::UiComboLine(const QStringList &words, QWidget *parent)
    : QLineEdit(parent)
{
    setWords(words);
}

void UiComboLine::setWords(const QStringList &words)
{
    // 创建一个QCompleter,关闭竖直水平的滑动条
    QCompleter *com = new QCompleter(words, this);
    com->popup()->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    com->popup()->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // 当QCompleter发出activated信号时，会再次发出itemSelected信号传递给父控件,
    // 父控件再捕捉信号实现相关的槽函数即可
    connect(com, QOverload<const QString&>::of(&QCompleter::activated),
        [=](const QString &text){
            emit itemSelected(text);
        }
    );
    // 为LineEdit设置自动补全，并设置内容匹配过滤
    this->setCompleter(com);
    com->setFilterMode(Qt::MatchContains);
}

void UiComboLine::setWords(const QList<int> words)
{
    QStringList strs;
    for (int i = 0; i < words.size(); ++i)
    {
        strs << QString::number(words[i]);
    }
    setWords(strs);
}

void UiComboLine::setWords(int start, int len)
{
    QStringList strs;
    for (int i = start; i <= len; ++i)
    {
        strs << QString::number(i);
    }
    setWords(strs);
}

QStringList UiComboLine::getWords()
{
    QStringList strs;
    if(completer())
    {
        // completer内有模型，通过模型的索引获取数据
        auto model = completer()->model();
        for (int i = 0; i < model->rowCount(); ++i)
        {
            strs << model->index(i,0).data().toString();
        }
    }
    return strs;
}

void UiComboLine::mousePressEvent(QMouseEvent *e)
{
    if(completer())
    {
        completer()->complete();    // 弹出popup
    }
    QLineEdit::mousePressEvent(e);
}

