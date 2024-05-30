#ifndef UIPAGEWIDGET_H
#define UIPAGEWIDGET_H

#include <QWidget>

namespace Ui {
class PageWidget;
}

class UiPageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UiPageWidget(QWidget *parent = nullptr);
    ~UiPageWidget();

    // get set is
    int totalRow()const;
    int maxRowPerPage()const;
    int currentPage()const;
    int pageCount()const;
    int isFirstPage()const;
    int isLastPage()const;

    void setTotalRow(int newTotalRow);
    void setMaxRowPerPage(int rows);
    void setMaxRowList(const QList<int> rowList);   // 设置下拉行数选择列表
signals:
    void pageNumChanged(int start, int maxLen);     // 当更新页码时发出信号
public slots:
    void next();
    void pre();
    void jumpTo(int page);
private slots:
    // 这两个槽函数，需要与自定义lineedit发出的QCompleter的信号绑定
    void onCurrentPageSelected(const QString &text);
    void onMaxRowItemSelected(const QString &text);
private:
    void setPageCount();                    //  设置页号选择列表
    void reset();                           // 重置为首页
    void switchPage(int newCurrentPage);    // 切换页码

    Ui::PageWidget *ui;
    int totalRow_;          // 总共条数
    int currentPage_;       // 当前页码,不能与下者混为一谈
    int maxRowPerPage_;     // 每页最大条数
};

#endif // UIPAGEWIDGET_H
