#ifndef BASICSTAT_H
#define BASICSTAT_H

#include <list>

class BasicStat
{
public:
    /**
     * @brief mean 평균
     * @param data
     * @param mean
     * @return
     */
    static int mean(std::list<double> data, double& mean);

    /**
     * @brief variance 분산
     * @param data
     * @param variance
     * @return
     */
    static int variance(std::list<double> data, double& variance);

    /**
     * @brief stdDeviation 표준편차
     * @param data
     * @param deviation
     * @return
     */
    static int stdDeviation(std::list<double> data, double& deviation);

    /**
     * @brief pecentile 백분위수
     * @param data
     * @param pth
     * @param value
     * @return
     */
    static int pecentile(std::list<double> data, double pth, double& value);

    /**
     * @brief correlationCoefficient 상관계수
     * @param dataX
     * @param dataY
     * @param value
     * @return
     */
    static int correlationCoefficient(std::list<double> dataX, std::list<double> dataY, double& value);

private:
    /**
     * @brief sumOfDeviationSquare 편차 제곱의 합
     * @param data
     * @param value
     * @return
     */
    static int sumOfDeviationSquare(std::list<double> data, double& value);
};

#endif // BASICSTAT_H
