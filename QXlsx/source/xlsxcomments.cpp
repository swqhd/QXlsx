// xlsxcomments.cpp

#include <QtGlobal>
#include <QString>
#include <QIODevice>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDebug>

#include "xlsxworksheet.h"
#include "xlsxabstractooxmlfile.h"
#include "xlsxabstractsheet.h"
#include "xlsxcomments.h"
#include "xlsxcomments_p.h"

QT_BEGIN_NAMESPACE_XLSX

CommentsPrivate::CommentsPrivate(Comments *q, Comments::CreateFlag flag)
    : AbstractOOXmlFilePrivate(q, flag)
{
}

CommentsPrivate::~CommentsPrivate()
{
}

Comments::Comments(AbstractSheet *parent, CreateFlag flag)
    : AbstractOOXmlFile(new CommentsPrivate(this, flag))
{
    d_func()->sheet = parent;
}

Comments::~Comments()
{
}

QT_END_NAMESPACE_XLSX
