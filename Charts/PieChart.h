#ifndef PIECHART_H
#define PIECHART_H


#include "IChart.h"


class PieChart : public IChart
{
private:
    QtCharts::QAbstractSeries* getSeries(const QMap<QString, quint64>& sizesMap) const override;
public:
    ~PieChart() override = default;
};


#endif // PIECHART_H
