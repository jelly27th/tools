#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_input_clicked();

    void on_output_clicked();

    void on_hex2SAE_clicked();

    void on_SAE2hex_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
