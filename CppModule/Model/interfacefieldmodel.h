#ifndef INTERFACEFIELDMODEL_H
#define INTERFACEFIELDMODEL_H


class InterfaceFieldModel
{
public:
    virtual ~InterfaceFieldModel();
    virtual void setElementInToModel(int index) = 0; //пока не ясно какой тут метод
};

#endif // INTERFACEFIELDMODEL_H
