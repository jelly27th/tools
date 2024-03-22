#include "widget.h"
#include "./ui_widget.h"
#include "QFileDialog"
#include "UI/h2s/h2s.h"
#include "UI/StringCopy/stringcopy.h"
#include "QStyleOption"
#include "QPainter"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_StringCopy_clicked()
{
    StringCopy* StringCopy_windows = new StringCopy;
    StringCopy_windows->show();
    this->hide();
}


void Widget::on_h2s_2_clicked()
{
    h2s* h2s_windows = new h2s;
    h2s_windows->show();
    this->hide();
}

void Widget::paintEvent(QPaintEvent*) {
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
