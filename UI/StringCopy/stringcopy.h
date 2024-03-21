#ifndef STRINGCOPY_H
#define STRINGCOPY_H

#include <QWidget>
#include "QString"
#include "QFileDialog"

namespace Ui {
class StringCopy;
}

class StringCopy : public QWidget
{
    Q_OBJECT

public:
    explicit StringCopy(QWidget *parent = nullptr);
    ~StringCopy();

private slots:

    void on_Input_OK_clicked();

    void on_Input_clicked();

    void on_Input_out_clicked();

private:
    Ui::StringCopy *ui;
    QString copyFile;
    QString outFile;
};

#endif // STRINGCOPY_H
