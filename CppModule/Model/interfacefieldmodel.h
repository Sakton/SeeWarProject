#ifndef INTERFACEFIELDMODEL_H
#define INTERFACEFIELDMODEL_H
#include <QAbstractListModel>

class InterfaceFieldModel : public QAbstractListModel
{
public:
    explicit InterfaceFieldModel(QObject *parent);
    virtual ~InterfaceFieldModel();
    virtual void setElementInToModel(int index) = 0; //пока не ясно какой тут метод
};

#endif // INTERFACEFIELDMODEL_H
