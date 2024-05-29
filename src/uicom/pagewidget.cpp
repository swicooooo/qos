#include "pagewidget.h"
#include "qdebug.h"
#include "ui_pagewidget.h"

#include <QtMath>

PageWidget::PageWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PageWidget)
    , totalRow_(0)
    , currentPage_(1)
    , maxRowPerPage_(10)
{
    ui->setupUi(this);

    // 关联信号
    connect(ui->pushButtonPre, &QPushButton::clicked, this, &PageWidget::pre);
    connect(ui->pushButtonNext, &QPushButton::clicked, this, &PageWidget::next);
}

PageWidget::~PageWidget()
{
    delete ui;
}

int PageWidget::totalRow() const
{
    return totalRow_;
}

int PageWidget::maxRowPerPage() const
{
    return maxRowPerPage_;
}

int PageWidget::currentPage() const
{
    return currentPage_;
}

int PageWidget::pageCount() const
{
    return totalRow()==0?1:qCeil(totalRow()/(float)maxRowPerPage());  // 向上取整
}

int PageWidget::isFirstPage() const
{
    return currentPage_ == 1;
}

int PageWidget::isLastPage() const
{
    return currentPage_ == pageCount();
}

void PageWidget::setTotalRow(int newTotalRow)
{
    // 更新总共的条数,更新页码
    totalRow_ = newTotalRow;
    ui->labelTotal->setText(QString("共:%1条, 每页").arg(newTotalRow));
    reset();
}

void PageWidget::setMaxRowPerPage(int rows)
{
    // 搜索lineEditMaxRows提供的最大显示行数,如果符合则重置页码状态
    QStringList words = ui->lineEditCurrentPage->getWords();
    for (const auto &num : words)
    {
        if(num.toInt() == rows)
        {
            maxRowPerPage_ = rows;
            reset();
            break;
        }
    }
}

void PageWidget::setMaxRowList(const QList<int> rowList)
{
    ui->lineEditMaxRows->setWords(rowList);
    if(rowList.size() > 0)
    {
        // 默认数据为第一个
        ui->lineEditMaxRows->setText(QString::number(rowList[0]));
        setMaxRowPerPage(rowList[0]);
    }
}

void PageWidget::next()
{
    jumpTo(currentPage()+1);
}

void PageWidget::pre()
{
    jumpTo(currentPage()-1);
}

void PageWidget::jumpTo(int page)
{
    if(page != currentPage())
    {
        switchPage(page);
    }
}

void PageWidget::onCurrentPageSelected(const QString &text)
{
    if(currentPage() != text.toInt())
    {
        jumpTo(text.toInt());
    }
}

void PageWidget::onMaxRowItemSelected(const QString &text)
{
    setMaxRowPerPage(text.toInt());
}

void PageWidget::setPageCount()
{
    int count = pageCount();
    ui->labelPageCount->setText("/"+QString::number(count));
    ui->lineEditCurrentPage->setWords(1, count);    // 设置顺序序号
    ui->lineEditCurrentPage->setText("1");
}

void PageWidget::reset()
{
    setPageCount();
    switchPage(1);
}

void PageWidget::switchPage(int newCurrentPage)
{
    // 更新currentPage_索引
    currentPage_ = newCurrentPage;
    ui->lineEditCurrentPage->setText(QString::number(newCurrentPage));
    ui->pushButtonPre->setDisabled(isFirstPage());
    ui->pushButtonNext->setDisabled(isLastPage());

    // 确定newCurrentPage需要显示的条数
    int startRow = (newCurrentPage-1)*maxRowPerPage();
    int left = totalRow()-startRow;
    int len = left < maxRowPerPage() ? left : maxRowPerPage();

    qDebug() << QString("switch page %1,%2").arg(startRow).arg(len);
    emit pageNumChanged(startRow, len);
}
