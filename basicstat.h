#ifndef BASICSTAT_H
#define BASICSTAT_H

#include <list>

class BasicStat
{
public:
    /**
     * @brief 평균
     * @param data
     * @param mean
     * @return
     */
    static int mean(std::list<double> data, double& mean);

    /**
     * @brief 분산
     * @param data
     * @param variance
     * @return
     */
    static int variance(std::list<double> data, double& variance);

    /**
     * @brief 표준편차
     * @param data
     * @param deviation
     * @return
     */
    static int standardDeviation(std::list<double> data, double& deviation);

    /**
     * @brief 백분위수
     * @param data
     * @param pth
     * @param value
     * @return
     */
    static int pecentile(std::list<double> data, double pth, double& value);

    /**
     * @brief 상관계수
     * @param dataX
     * @param dataY
     * @param value
     * @return
     */
    static int correlationCoefficient(std::list<double> dataX, std::list<double> dataY, double& value);

private:
    /**
     * @brief 편차 제곱의 합
     * @param data
     * @param value
     * @return
     */
    static int sumOfDeviationSquare(std::list<double> data, double& value);
};

#endif // BASICSTAT_H
