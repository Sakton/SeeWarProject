#ifndef ABSTRACTQUERY_H
#define ABSTRACTQUERY_H
#include <QString>


class MyAbstractQuery
{
public:
    virtual ~MyAbstractQuery();
    virtual QString toQstring() = 0;

};

#endif // ABSTRACTQUERY_H
