#include "statchart.h"
#include <math.h>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QScatterSeries>

using namespace QtCharts;

QChartView *StatChart::histogram(dataset &data, QString title, QString label)
{
    QStringList categories;
    QBarSet *barset = new QBarSet(label);

    int num = 0;
    for(auto iter = data.begin(); iter != data.end(); ++iter)
    {
        *barset << *iter;
        categories << QString::number(++num);
    }

    QBarSeries *series = new QBarSeries();
    series->append(barset);

    QChart *chart = new QChart();
    chart->addSeries(series);
    if(title.length() != 0)
        chart->setTitle(title);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    return chartView;
}

QChartView *StatChart::scatterPlot(dataset &dataX, dataset &dataY, QString title, QString label)
{
    double minX = *std::min_element(dataX.begin(), dataX.end());
    double maxX = *std::max_element(dataX.begin(), dataX.end());
    double minY = *std::min_element(dataY.begin(), dataY.end());
    double maxY = *std::max_element(dataY.begin(), dataY.end());
    double axisXmin = minX - 1.0;
    double axisXmax = maxX + 1.0;
    double axisYmin = minY - 1.0;
    double axisYmax = maxY + 1.0;
    if(minX != maxX)
    {
        axisXmin = minX - (abs(maxX - minX) * 0.1);
        axisXmax = maxX + (abs(maxX - minX) * 0.1);
    }
    if(minY != maxY)
    {
        axisYmin = minY - (abs(maxY - minY) * 0.1);
        axisYmax = maxY + (abs(maxY - minY) * 0.1);
    }

    QScatterSeries *series = new QScatterSeries();
    series->setName(label);
    series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series->setMarkerSize(12.0);

    dataset::iterator iterX, iterY;
    for(int i = 0; i < dataX.size(); ++i)
    {
        iterX = dataX.begin();
        iterY = dataY.begin();
        std::advance(iterX, i);
        std::advance(iterY, i);
        series->append(*iterX, *iterY);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(title);
    chart->createDefaultAxes();
    chart->setDropShadowEnabled(false);
    chart->legend()->setMarkerShape(QLegend::MarkerShapeCircle);
    chart->axisX()->setRange(axisXmin, axisXmax);
    chart->axisY()->setRange(axisYmin, axisYmax);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    return chartView;
}
