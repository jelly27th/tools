#include "stringcopy.h"
#include "ui_stringcopy.h"
#include "QFile"
#include "../../widget.h"
#include "QStyleOption"
#include "QPainter"

StringCopy::StringCopy(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StringCopy)
{
    ui->setupUi(this);
}

StringCopy::~StringCopy()
{
    delete ui;
}

void StringCopy::on_Input_OK_clicked()
{
    QString oriStr = ui->textEdit_StrOri->toPlainText();
    QString subStr = ui->subStr->toPlainText();

    QFile ipf(copyFile);
    QFile opf(outFile);
    if (ipf.open(QIODevice::ReadOnly | QIODevice::Text) &&
        opf.open(QIODevice::ReadWrite | QIODevice::Text)) {

        QTextStream stream(&opf);
        stream.seek(opf.size());
        while (!ipf.atEnd())
        {
            QByteArray line = ipf.readLine();
            QString str(line);

            QString tmp = oriStr;
            tmp.replace(subStr,str);
            int pos = tmp.indexOf(str);
            for (QChar *it=tmp.begin(); it!=tmp.end(); ) {
                tmp.remove(pos+str.size()-1, 1);
                pos = tmp.indexOf(str, pos+str.size());
                if (-1 == pos) {
                    it = tmp.end();
                }
            }
            stream << tmp << "\n";
        }
        ipf.close();
        opf.close();

    }
}


void StringCopy::on_Input_clicked()
{
    copyFile = QFileDialog::getOpenFileName(this, "open a file", " ",nullptr);
    ui->lineEdit_input->setText(copyFile);
}


void StringCopy::on_Input_out_clicked()
{
    outFile = QFileDialog::getOpenFileName(this, "open a file", " ",nullptr);
    ui->lineEdit_input_2->setText(outFile);
}


void StringCopy::on_Return_clicked()
{
    Widget *main_windows = new Widget;
    main_windows->show();
    this->hide();
    this->deleteLater();
}

void StringCopy::paintEvent(QPaintEvent*) {
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
