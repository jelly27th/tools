#ifndef H2S_H
#define H2S_H

#include <QWidget>

namespace Ui {
class h2s;
}

class h2s : public QWidget
{
    Q_OBJECT

public:
    explicit h2s(QWidget *parent = nullptr);
    ~h2s();

private slots:
    void on_input_clicked();

    void on_output_clicked();

    void on_hex2SAE_clicked();

    void on_SAE2hex_clicked();

    void on_Return_clicked();

    void paintEvent(QPaintEvent*);

private:
    Ui::h2s *ui;
};

#endif // H2S_H
