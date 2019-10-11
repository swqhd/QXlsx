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

int test( QVector<QVariant> params );
int test1( QVector<QVariant> params );
int test2( QVector<QVariant> params );

int test( QVector<QVariant> params )
{
    return test1( params );
}

int test1( QVector<QVariant> params )
{
    qDebug() << "[debug] current path : " << QDir::currentPath();

    using namespace QXlsx;

    Document doc;

    doc.write( "A1", QVariant(QDateTime::currentDateTimeUtc()) );
    doc.write( "A2", QVariant(double(10.5)) );
    doc.write( "A3", QVariant(QDate(2019, 10, 9)) );
    doc.write( "A4", QVariant(QTime(10, 9, 5)) );
    doc.write( "A5", QVariant((int) 40000) );

    qDebug() << "doc.read()";
    qDebug() << doc.read( 1, 1 ).type() << doc.read( 1, 1 );
    qDebug() << doc.read( 2, 1 ).type() << doc.read( 2, 1 );
    qDebug() << doc.read( 3, 1 ).type() << doc.read( 3, 1 );
    qDebug() << doc.read( 4, 1 ).type() << doc.read( 4, 1 );
    qDebug() << doc.read( 5, 1 ).type() << doc.read( 5, 1 );
    qDebug() << "\n";

    qDebug() << "doc.cellAt()->value()";
    qDebug() << doc.cellAt( 1, 1 )->value().type() << doc.cellAt( 1, 1 )->value();
    qDebug() << doc.cellAt( 2, 1 )->value().type() << doc.cellAt( 2, 1 )->value();
    qDebug() << doc.cellAt( 3, 1 )->value().type() << doc.cellAt( 3, 1 )->value();
    qDebug() << doc.cellAt( 4, 1 )->value().type() << doc.cellAt( 4, 1 )->value();
    qDebug() << doc.cellAt( 5, 1 )->value().type() << doc.cellAt( 5, 1 )->value();

    doc.saveAs("datetime.xlsx");

    return 0;
}


