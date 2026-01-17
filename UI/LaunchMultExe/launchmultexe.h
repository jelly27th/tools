#ifndef LAUNCHMULTEXE_H
#define LAUNCHMULTEXE_H

#include <QWidget>

namespace Ui {
class LaunchMultExe;
}

class LaunchMultExe : public QWidget
{
    Q_OBJECT
public:
    explicit LaunchMultExe(QWidget *parent = nullptr);
    ~LaunchMultExe();

    void paintEvent(QPaintEvent*);
private slots:
    void on_Return_clicked();

    void on_Load_clicked();

    void on_textBrowser_anchorClicked(const QUrl &arg1);

private:
    Ui::LaunchMultExe *ui;
};

#endif // LAUNCHMULTEXE_H
