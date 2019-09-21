// xlsxcomments.h

#ifndef QXLSX_COMMENTS_H
#define QXLSX_COMMENTS_H

#include <QtGlobal>
#include <QSharedPointer>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

#include "xlsxglobal.h"
#include "xlsxabstractooxmlfile.h"

QT_BEGIN_NAMESPACE_XLSX

class AbstractOOXmlFile;
class AbstractSheet;
class CommentsPrivate;

class Comments : public AbstractOOXmlFile
{
    Q_DECLARE_PRIVATE(Comments)
protected:
    Comments(AbstractSheet *parent, CreateFlag flag);
public:
    ~Comments();
protected:
    friend class AbstractSheet;
    friend class Worksheet;

// bool loadFromXmlFile(QIODevice *device);
// void saveToXmlFile(QIODevice *device) const;

};

QT_END_NAMESPACE_XLSX

#endif
