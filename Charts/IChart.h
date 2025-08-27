#ifndef ICHART_H
#define ICHART_H


#include <QtCharts/QChart>
#include <QtCharts/QAbstractSeries>
#include <QtCharts/QLegend>
#include <QMap>
#include <QString>
#include <QtGlobal>


class IChart
{
private:
    virtual QtCharts::QAbstractSeries* getSeries(const QMap<QString, quint64>& sizesMap) const = 0;
    void setLegend(QtCharts::QLegend* legend) const;
public:
    virtual ~IChart() = default;
    QtCharts::QChart* CreateChart(const QMap<QString, quint64>& sizesMap) const;
};


#endif // ICHART_H
