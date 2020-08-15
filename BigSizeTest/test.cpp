// test.cpp

#include <QtGlobal>
#include <QCoreApplication>
#include <QtCore>
#include <QVector>
#include <QVariant>
#include <QDebug> 
#include <QDir>
#include <QColor>
#include <QImage>
#include <QRgb>

#include <iostream>
using namespace std;

#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"

// Qt Creator 4.12.4  Based on Qt 5.14.2 (MSVC 2017, 32 bit) Built on Jul 7 2020 07:24:47
// MingW 7.3.0 64bit
// gcc 8.1.0
// Microsoft Windows 10
int test( QVector<QVariant> params )
{
    using namespace QXlsx;

    Document xlsx;

    for (int count =0 ; count < 30000; count++)
    {
        xlsx.write( (count+1), 1, QVariant(QString("1234567890")) );
        xlsx.write( (count+1), 2, QVariant(QString("3号设备 事件报警 3号设备 事件报警 3号设备 事件报警")) );
        xlsx.write( (count+1), 3, QVariant(QString("1234567890abcdefghijklmnopqrstu")) );
    }

    if (xlsx.saveAs("testBIg.xlsx"))
    {
        qDebug() << "success to save";
    }

    return 0;
}
