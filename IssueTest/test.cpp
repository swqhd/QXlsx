// test.cpp

#include <QtGlobal>
#include <QCoreApplication>
#include <QtCore>
#include <QVector>
#include <QVariant>
#include <QDebug> 
#include <QDir>

#include <iostream>
using namespace std;

#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"

int test( QVector<QVariant> params )
{
    using namespace QXlsx;

    QString filepath = ":/test.xlsx";

    Document xlsxR(filepath);
    if (!xlsxR.load())
    {
        qDebug() << "failed to load file";
        return (-1);
    }

    int row = 1; int col = 1;
    Cell* cell = xlsxR.cellAt(row, col);
    if ( cell != NULL )
    {
        QVariant var = cell->readValue();
        qDebug() << var;
    }

    return 0;
}

