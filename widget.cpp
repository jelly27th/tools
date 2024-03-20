#include "widget.h"
#include "./ui_widget.h"
#include "QFileDialog"
#include "HEX2SAE/hex2SAE.h"

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

void Widget::on_input_clicked()
{
    hexFile = QFileDialog::getOpenFileName(this, "open a file", " ",nullptr);
    ui->lineEdit_input->setText(hexFile);
}


void Widget::on_output_clicked()
{
    SAEFile = QFileDialog::getOpenFileName(this, "open a file", " ",nullptr);
    ui->lineEdit_output->setText(SAEFile);
}


void Widget::on_hex2SAE_clicked()
{
    FILE *ipf = fopen(hexFile.toLatin1().constData(), "r");
    FILE *opf = fopen(SAEFile.toLatin1().constData(), "w+");

    FilePathCheck(ipf, opf);

    Hex2SAE(ipf, opf);

    fclose(ipf);
    fclose(opf);
}


void Widget::on_SAE2hex_clicked()
{
    FILE *ipf = fopen(SAEFile.toLatin1().constData(), "r");
    FILE *opf = fopen(hexFile.toLatin1().constData(), "w+");

    FilePathCheck(ipf, opf);

    SAE2Hex(ipf, opf);

    fclose(ipf);
    fclose(opf);
}

