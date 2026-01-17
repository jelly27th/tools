#include "launchmultexe.h"
#include "ui_launchmultexe.h"
#include "../../widget.h"
#include "QStyleOption"
#include "QPainter"
#include "QFileDialog"
#include "QFile"
#include "QDesktopServices"

LaunchMultExe::LaunchMultExe(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LaunchMultExe)
{
    ui->setupUi(this);
}

LaunchMultExe::~LaunchMultExe()
{
    delete ui;
}

void LaunchMultExe::on_Return_clicked()
{
    Widget *main_windows = new Widget;
    main_windows->show();
    this->hide();
    this->deleteLater();
}

void LaunchMultExe::paintEvent(QPaintEvent*) {
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

QString exeFile;
void LaunchMultExe::on_Load_clicked()
{
    exeFile = QFileDialog::getOpenFileName(this, "open a file", " ",nullptr);
    ui->lineEdit_Load->setText(exeFile);

    QFile file(exeFile);
    QStringList exeLists;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            exeLists << line;
            // ui->listView;
        }
    }

    for (int i = 0; i < exeLists.length(); i++) {
        QString htmlLink = QString("<a href=\"file:///%1\">%2</a>")
                               .arg(exeLists[i])
                               .arg(exeLists[i]);
        ui->textBrowser->append(htmlLink);
    }
    ui->textBrowser->setOpenLinks(false);

    file.close();
}


void LaunchMultExe::on_textBrowser_anchorClicked(const QUrl &arg1)
{
    if (arg1.scheme() == "file") {
        QDesktopServices::openUrl(arg1);
    }
}

