#ifndef PIECHARTVIEW_H
#define PIECHARTVIEW_H


#include <QWidget>
#include <QVBoxLayout>
#include <QtCharts/QChartView>
#include "../Charts/PieChart.h"


class PieChartView : public QWidget
{
    Q_OBJECT
private:
    QtCharts::QChartView* chartView;
    IChart* factory;
public:
    explicit PieChartView(QWidget* parent = nullptr);
    void setData(const QMap<QString, quint64>& sizesMap);
    ~PieChartView();
};


#endif // PIECHARTVIEW_H
