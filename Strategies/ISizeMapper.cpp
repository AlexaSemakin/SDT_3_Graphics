#include "ISizeMapper.h"


void ISizeMapper::selectionEvent(const QMap<QString, quint64> &sizesMap) const
{
    for (auto *obs : observers) obs->updateDisplay(sizesMap);
}
