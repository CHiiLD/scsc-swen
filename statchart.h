#ifndef STATCHART_H
#define STATCHART_H

#include <QtCharts/QChartView>
#include "swen.h"

/**
 * @brief 통계 차트 클래스
 */
class StatChart
{
public:
    /**
     * @brief 일변량 데이터의 히스토그램을 qchart로 작성합니다.
     * @param data 데이터셋
     * @param title 타이틀
     * @param label 라벨
     * @return QChartView* 인스턴스
     */
    static QtCharts::QChartView* histogram(dataset& data, QString title = "", QString label = "");

    /**
     * @brief 이변량 데이터의 다중산점돌르 qchart로 작성합니다.
     * @param dataX X 데이터셋
     * @param dataY Y 데이터셋
     * @param title 타이틀
     * @param label 라벨
     * @return QChartView* 인스턴스
     */
    static QtCharts::QChartView* scatterPlot(dataset& dataX, dataset& dataY, QString title = "", QString label = "");
};

#endif // STATCHART_H
