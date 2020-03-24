#ifndef MYJSONOBJECTS_H
#define MYJSONOBJECTS_H
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

class BaseMyJson {
    virtual ~BaseMyJson() = 0;
    virtual QByteArray toQByteArray() = 0;
};


#endif // MYJSONOBJECTS_H
