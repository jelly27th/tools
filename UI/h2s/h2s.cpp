#include "h2s.h"
#include "ui_h2s.h"
#include "../../HEX2SAE/hex2SAE.h"
#include "QFileDialog"
#include "../../widget.h"
#include "QStyleOption"
#include "QPainter"

h2s::h2s(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::h2s)
{
    ui->setupUi(this);
}

h2s::~h2s()
{
    delete ui;
}

void h2s::on_input_clicked()
{
    hexFile = QFileDialog::getOpenFileName(this, "open a file", " ",nullptr);
    ui->lineEdit_input->setText(hexFile);
}


void h2s::on_output_clicked()
{
    SAEFile = QFileDialog::getOpenFileName(this, "open a file", " ",nullptr);
    ui->lineEdit_output->setText(SAEFile);
}


void h2s::on_hex2SAE_clicked()
{
    FILE *ipf = fopen(hexFile.toLatin1().constData(), "r");
    FILE *opf = fopen(SAEFile.toLatin1().constData(), "w+");

    FilePathCheck(ipf, opf);

    Hex2SAE(ipf, opf);

    fclose(ipf);
    fclose(opf);
}


void h2s::on_SAE2hex_clicked()
{
    FILE *ipf = fopen(SAEFile.toLatin1().constData(), "r");
    FILE *opf = fopen(hexFile.toLatin1().constData(), "w+");

    FilePathCheck(ipf, opf);

    SAE2Hex(ipf, opf);

    fclose(ipf);
    fclose(opf);
}


void h2s::on_Return_clicked()
{
    Widget *main_windows = new Widget;
    main_windows->show();
    this->hide();
    this->deleteLater();

}

void h2s::paintEvent(QPaintEvent*) {
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

