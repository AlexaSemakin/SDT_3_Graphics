#include "BarChartView.h"
using namespace QtCharts;


BarChartView::BarChartView(QWidget* parent) : QWidget(parent)
{
    factory = new BarChart();
    chartView = new QChartView(new QChart());
    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(chartView);
}


void BarChartView::setData(const QMap<QString, quint64>& sizesMap)
{
    auto *chart = factory->CreateChart(sizesMap);
    chartView->setChart(chart);
}


BarChartView::~BarChartView()
{
    delete factory;
}
