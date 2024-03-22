#include "widget.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "QHBoxLayout"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "tools_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    Widget w;
    QHBoxLayout *layout = new QHBoxLayout(&w);
    w.setLayout(layout);
    w.show();
    return a.exec();
}
