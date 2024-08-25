#include "uipagewidget.h"
#include "qdebug.h"
#include "ui_uipagewidget.h"

#include <QtMath>

UiPageWidget::UiPageWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PageWidget)
    , totalRow_(0)
    , currentPage_(1)
    , maxRowPerPage_(10)
{
    ui->setupUi(this);
    ui->lineEditMaxRows->setMinimumWidth(40);
    // 关联信号
    connect(ui->pushButtonPre, &QPushButton::clicked, this, &UiPageWidget::pre);
    connect(ui->pushButtonNext, &QPushButton::clicked, this, &UiPageWidget::next);
    // 从ComboLine被点击后发出信号itemSelected，后绑定槽
    connect(ui->lineEditCurrentPage,&UiComboLine::itemSelected,this,&UiPageWidget::onCurrentPageSelected);
    connect(ui->lineEditMaxRows,&UiComboLine::itemSelected,this,&UiPageWidget::onMaxRowItemSelected);
}

UiPageWidget::~UiPageWidget()
{
    delete ui;
}

int UiPageWidget::totalRow() const
{
    return totalRow_;
}

int UiPageWidget::maxRowPerPage() const
{
    return maxRowPerPage_;
}

int UiPageWidget::currentPage() const
{
    return currentPage_;
}

int UiPageWidget::pageCount() const
{
    // 页数=总条数/每页最大条数，向上取整
    return totalRow()==0?1:qCeil(totalRow()/(float)maxRowPerPage());
}

int UiPageWidget::isFirstPage() const
{
    return currentPage_ == 1;
}

int UiPageWidget::isLastPage() const
{
    return currentPage_ == pageCount();
}

void UiPageWidget::setTotalRow(int newTotalRow)
{
    // 更新总条数,更新页码
    totalRow_ = newTotalRow;
    ui->labelTotal->setText(QString("共:%1条, 每页").arg(newTotalRow));
    reset();
}

void UiPageWidget::setMaxRowPerPage(int rows)
{
    // 搜索lineEditMaxRows提供的最大显示行数,如果符合则重置页码状态
    QStringList words = ui->lineEditMaxRows->getWords();
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

void UiPageWidget::setMaxRowList(const QList<int> rowList)
{
    ui->lineEditMaxRows->setWords(rowList);
    if(rowList.size() > 0)
    {
        // 默认数据为第一个
        ui->lineEditMaxRows->setText(QString::number(rowList[0]));
        setMaxRowPerPage(rowList[0]);
    }
}

void UiPageWidget::next()
{
    jumpTo(currentPage()+1);
}

void UiPageWidget::pre()
{
    jumpTo(currentPage()-1);
}

void UiPageWidget::jumpTo(int page)
{
    if(page != currentPage())
    {
        switchPage(page);
    }
}

void UiPageWidget::onCurrentPageSelected(const QString &text)
{
    if(currentPage() != text.toInt())
    {
        jumpTo(text.toInt());
    }
}

void UiPageWidget::onMaxRowItemSelected(const QString &text)
{
    setMaxRowPerPage(text.toInt());
}

void UiPageWidget::reset()
{
    // 更新总页码数
    ui->labelPageCount->setText("/"+QString::number(pageCount()));
    ui->lineEditCurrentPage->setWords(1, pageCount());    // 设置顺序序号
    ui->lineEditCurrentPage->setText("1");
    switchPage(1);
}

void UiPageWidget::switchPage(int newCurrentPage)
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
