#ifndef IOBSERVER_H
#define IOBSERVER_H


#include <QMap>
#include <QString>
#include <QtGlobal>


class IObserver
{
public:
    virtual ~IObserver() = default;
    virtual void updateDisplay(const QMap<QString, quint64>& sizesMap) = 0;
};


#endif // IOBSERVER_H
