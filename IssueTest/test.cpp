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

int test102( QVector<QVariant> params );

int test( QVector<QVariant> params )
{
    qDebug() << "[debug] current path : " << QDir::currentPath();
    return test102( params );
}

int test102( QVector<QVariant> params )
{
    using namespace QXlsx;

    Document xlsx;



    return 0;
}

