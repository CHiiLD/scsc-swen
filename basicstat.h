#ifndef BASICSTAT_H
#define BASICSTAT_H

#include "swen.h"

/**
 * @brief 기초 통계량 계산 클래스
 */
class FoundationStat
{
public:
    /**
     * @brief 평균을 계산합니다.
     * @param data 데이터 셋
     * @param mean 평균값
     * @return 0(ok) 또는 -1(error)을 반환합니다.
     */
    static int mean(dataset data, double& mean);

    /**
     * @brief 분산을 계산합니다.
     * @param data 데이터 셋
     * @param variance 분산값
     * @return 0(ok) 또는 -1(error)을 반환합니다.
     */
    static int variance(dataset data, double& variance);

    /**
     * @brief 표준편차를 계산합니다.
     * @param data 데이터 셋
     * @param deviation 표준편차값
     * @return 0(ok) 또는 -1(error)을 반환합니다.
     */
    static int standardDeviation(dataset data, double& deviation);

    /**
     * @brief 백분위수를 계산합니다.
     * @param data 데이터셋
     * @param pth 분할점, 0.0~1.0 사이의 범위의 값을 가집니다.
     * @param value 100pth 백분위수값
     * @return 0(ok) 또는 -1(error)을 반환합니다.
     */
    static int pecentile(dataset data, double pth, double& value);

    /**
     * @brief 상관계수를 계산합니다.
     * @param dataX 데이터셋
     * @param dataY 데이터셋
     * @param value 상관계수값
     * @return 0(ok) 또는 -1(error)을 반환합니다.
     */
    static int correlationCoefficient(dataset dataX, dataset dataY, double& value);

private:
    /**
     * @brief 편차 제곱의 합을 계산합니다.
     * @param data 데이터셋
     * @param value 편차 제곱의 합값
     * @return 0(ok) 또는 -1(error)을 반환합니다.
     */
    static int sumOfDeviationSquare(dataset data, double& value);
};

#endif // BASICSTAT_H
