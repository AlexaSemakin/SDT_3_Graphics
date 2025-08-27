#include "BarChart.h"
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
using namespace QtCharts;


QtCharts::QAbstractSeries* BarChart::getSeries(const QMap<QString, quint64> &sizesMap) const
{
    QBarSeries* series = new QBarSeries();
    foreach (const QString& key, sizesMap.keys()) {
        auto *set = new QBarSet(key);
        set->append(static_cast<qreal>(sizesMap.value(key)));
        series->append(set);
    }
    return series;
}
