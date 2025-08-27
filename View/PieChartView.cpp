#include "PieChartView.h"
using namespace QtCharts;


PieChartView::PieChartView(QWidget* parent) : QWidget(parent)
{
    factory = new PieChart();
    chartView = new QChartView(new QChart());
    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(chartView);
}


void PieChartView::setData(const QMap<QString, quint64>& sizesMap)
{
    auto *chart = factory->CreateChart(sizesMap);
    chartView->setChart(chart);
}


PieChartView::~PieChartView()
{
    delete factory;
}
