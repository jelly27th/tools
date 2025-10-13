#include "widget.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "QHBoxLayout"

#include <QtGlobal>
#include <QCoreApplication>
#include <QtCore>
#include <QVariant>
#include <QDebug>

#include <iostream>
// [0] include QXlsx headers
#include "thirdparty/QXlsx/QXlsx/header/xlsxdocument.h"
#include "thirdparty/QXlsx/QXlsx/header/xlsxchartsheet.h"
#include "thirdparty/QXlsx/QXlsx/header/xlsxcellrange.h"
#include "thirdparty/QXlsx/QXlsx/header/xlsxchart.h"
#include "thirdparty/QXlsx/QXlsx/header/xlsxrichstring.h"
#include "thirdparty/QXlsx/QXlsx/header/xlsxworkbook.h"
using namespace QXlsx;
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int row = 1; int col = 1;

    // [1]  Writing excel file(*.xlsx)
    QXlsx::Document xlsxW;
    QVariant writeValue = QString("Hello Qt!");
    xlsxW.write(row, col, writeValue); // write "Hello Qt!" to cell(A,1).
    xlsxW.saveAs("Test.xlsx"); // save the document as 'Test.xlsx'

    // [2] Reading excel file(*.xlsx)
    Document xlsxR("Test.xlsx");
    if (xlsxR.load()) // load excel file
    {
        //Cell* cell = xlsxR.cellAt(row, col); // get cell pointer.
        std::shared_ptr<QXlsx::Cell> sharedCell = xlsxR.cellAt(row, col);/* ... obtain shared_ptr ... */
        QXlsx::Cell* cell = sharedCell.get(); // Get the raw pointer
        if ( cell != NULL )
        {
            QVariant var = cell->readValue(); // read cell value (number(double), QDateTime, QString ...)
            qDebug() << var; // display value. it is 'Hello Qt!'.
        }
    }

    return 0;
}
