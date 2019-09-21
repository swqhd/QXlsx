// xlsxcomments_p.h

#ifndef QXLSX_COMMENTS_P_H
#define QXLSX_COMMENTS_P_H

#include <QtGlobal>
#include <QObject>
#include <QString>
#include <QSharedPointer>
#include <QVector>
#include <QMap>
#include <QList>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

#include "xlsxabstractooxmlfile_p.h"
#include "xlsxcomments.h"

QT_BEGIN_NAMESPACE_XLSX

class CommentsPrivate : public AbstractOOXmlFilePrivate
{
    Q_DECLARE_PUBLIC(Comments)
public:
    CommentsPrivate(Comments *q, Comments::CreateFlag flag);
    ~CommentsPrivate();
public:
    AbstractSheet* sheet;
};

QT_END_NAMESPACE_XLSX

#endif
