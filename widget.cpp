#include "widget.h"
#include "./ui_widget.h"
#include "QFileDialog"

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

void Widget::on_h2s_clicked()
{
    h2s_windows->show();
    this->hide();
}


void Widget::on_StringCopy_clicked()
{
    StringCopy_windows->show();
    this->hide();
}

