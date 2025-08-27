#ifndef BARCHARTVIEW_H
#define BARCHARTVIEW_H


#include <QWidget>
#include <QVBoxLayout>
#include <QtCharts/QChartView>
#include "../Charts/BarChart.h"


class BarChartView : public QWidget
{
    Q_OBJECT
private:
    QtCharts::QChartView* chartView;
    IChart* factory;
public:
    explicit BarChartView(QWidget* parent = nullptr);
    void setData(const QMap<QString, quint64>& sizesMap);
    ~BarChartView();
};


#endif // BARCHARTVIEW_H
