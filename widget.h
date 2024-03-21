#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "UI/h2s/h2s.h"
#include "UI/StringCopy/stringcopy.h"

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

    void on_h2s_clicked();

    void on_StringCopy_clicked();

private:
    Ui::Widget *ui;
    h2s* h2s_windows = new h2s;
    StringCopy* StringCopy_windows = new StringCopy;
};
#endif // WIDGET_H
