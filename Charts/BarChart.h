#ifndef BARCHART_H
#define BARCHART_H


#include "IChart.h"


class BarChart : public IChart
{
private:
    QtCharts::QAbstractSeries* getSeries(const QMap<QString, quint64>& sizesMap) const override;
public:
    ~BarChart() override = default;
};


#endif // BARCHART_H
