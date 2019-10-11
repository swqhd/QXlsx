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
    // return test2( params );
}

int test1( QVector<QVariant> params )
{
    qDebug() << "[debug] current path : " << QDir::currentPath();

    using namespace QXlsx;

    Document doc;
    doc.addSheet("TestWorksheet");

    QVariant expected = QDateTime::currentDateTimeUtc();
    assert(doc.write("A1", expected));

    assert(doc.write("A2", QVariant(double(10.5)) ));

    QVariant actual;
    auto cell = doc.cellAt("A1"); // get cell pointer.
    if ( cell != nullptr )
        actual = cell->readValue();

    auto cell2 = doc.cellAt("A2");
    if ( cell2 != nullptr )
    {
        QVariant val2 = cell2->readValue();

        qDebug() << val2.type() << val2 ;
    }

    doc.saveAs("EA.xlsx");

    return 0;
}

int test2( QVector<QVariant> params )
{
    qDebug() << "[debug] current path : " << QDir::currentPath();

    using namespace QXlsx;

    QString fileName = QUuid::createUuid().toString() + ".xlsx";
    QFile::remove(fileName);

    auto docW = new QXlsx::Document(fileName);
    docW->addSheet("TestWorksheet");

    QVariant expected = QDateTime::currentDateTimeUtc();
    assert(docW->write("A1", expected));

    docW->save();
    delete docW;

    auto docR = new QXlsx::Document(fileName);
    docR->load();

    QVariant actual;
    auto cell = docR->cellAt("A1"); // get cell pointer.
    if ( cell != nullptr)
        actual = cell->readValue();

    qDebug() << "expected.type() : " << expected.type();
    qDebug() << "actual.type() : " << actual.type();

    auto expectedTime = expected.toDateTime();
    auto actualTime = actual.toDateTime();
    qDebug() << (actualTime == expectedTime ? "Values are the same" : "Values are Not the same");
    qDebug() << "Expected:" << expectedTime.toString(Qt::DateFormat::ISODate);
    qDebug() << "Actual:" << actualTime.toString(Qt::DateFormat::ISODate);

    delete docR;
    QFile::remove(fileName);


    return 0;
}
