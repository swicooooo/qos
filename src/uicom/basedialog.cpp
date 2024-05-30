#include "basedialog.h"
#include "ui_basedialog.h"

#include <QMouseEvent>

BaseDialog::BaseDialog(QWidget *parent)
    : QDialog(parent)
    , base_ui(new Ui::BaseDialog)
{
    base_ui->setupUi(this);
    // 设置窗口默认样式,自定义窗口
    setWindowFlags(Qt::CustomizeWindowHint);
    setLogo(":/static/logo.png");
    addCloseButton(":/static/logo.png",":/static/logo.png");
    setAllButtonSize();
    base_ui->labelLogo->setFixedSize(28,28);
}

BaseDialog::~BaseDialog()
{
    delete base_ui;
}

void BaseDialog::setTitle(const QString &title)
{
    base_ui->labelTitle->setText(title);
}

void BaseDialog::setLogo(const QString &path)
{
    base_ui->labelLogo->setStyleSheet(QString("border-image: url(\"%1\");").arg(path));
}

void BaseDialog::addMinButton(const QString &path, const QString &hoverPath)
{
    // 添加一个button关联最小化槽函数
    QPushButton *btn = addButton(path, hoverPath);
    connect(btn, &QPushButton::clicked, this, &BaseDialog::showMinimized);
}

void BaseDialog::addMaxButton(const QString &maxPath, const QString &maxPathHover, const QString &normalPath, const QString &normalPathHover)
{
    // 关联信号，当点击最大化后显示max的图片路径，否则显示normal图片路径
    QPushButton *btn = addButton(maxPath, maxPathHover);
    auto funcImg = [=](){
        isMaximized() ? setButtonImage(btn, normalPath, normalPathHover)
                      :setButtonImage(btn, maxPath, maxPathHover);
    };

    auto funcShow = [=](){
        isMaximized() ? showNormal() : showMaximized();
        funcImg();
    };

    connect(btn, &QPushButton::clicked, this, funcShow);
    funcImg();
}

QPushButton* BaseDialog::addButton(const QString &path, const QString &hoverPath)
{
    QPushButton *btn = new QPushButton;
    btn->setFixedSize(recordSize_, recordSize_);
    setButtonImage(btn, path, hoverPath);
    // 添加到closebtn前
    addWidget(btn);
    return btn;
}

void BaseDialog::setButtonImage(QPushButton *btn, const QString &path, const QString &hoverPath)
{
    btn->setStyleSheet(QString(
        "QPushButton{border-image: url(\"%1\");}"
        "QPushButton:hover{border-image: url(\"%2\");}"
        ).arg(path,hoverPath)
    );
}

void BaseDialog::setAllButtonSize(int w)
{
    auto buttons = base_ui->frameTitle->findChildren<QPushButton*>();
    for (auto btn : buttons) {
        btn->setFixedSize(w, w);
    }
    recordSize_ = w;
}

void BaseDialog::addTitleLine(int w)
{
    QLabel *label = new QLabel;
    label->setFixedSize(w,15);
    label->setStyleSheet("QLabel{background-color: lightgray;}");
    addWidget(label);
}

void BaseDialog::mousePressEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        startPos_ = event->pos();   // 记录起始pos
    }
    QDialog::mousePressEvent(event);
}

void BaseDialog::mouseMoveEvent(QMouseEvent *event)
{
    // 计算鼠标点击左键时移动的pos+当前窗口的pos
    if(event->buttons() & Qt::LeftButton)
    {
        QPoint targetPos = event->pos() - startPos_ + this->pos();
        this->move(targetPos);
    }
    QDialog::mouseMoveEvent(event);
}

QWidget *BaseDialog::body()
{
    return base_ui->widgetBody;
}

void BaseDialog::addCloseButton(const QString &path, const QString &hoverPath)
{
    // 将close添加到窗口栏中, 并关联信号
    setButtonImage(base_ui->pushButtonClose, path, hoverPath);
    base_ui->horizontalLayout->addWidget(base_ui->pushButtonClose);
    connect(base_ui->pushButtonClose, &QPushButton::clicked, this, &BaseDialog::reject);
}

void BaseDialog::addWidget(QWidget *w)
{
    int idx = base_ui->horizontalLayout->indexOf(base_ui->pushButtonClose);
    base_ui->horizontalLayout->insertWidget(idx, w);
}
