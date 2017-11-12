#ifndef FOUNDTATIONSTATDATA_H
#define FOUNDTATIONSTATDATA_H

#include "aprint.h"

/**
 * @brief 기초 통계량 결과값 클래스
 */
class FoundtationStatData : public Print
{
public:
    FoundtationStatData();

    double getMean() const;
    void setMean(double value);

    double getStandardDeviation() const;
    void setStandardDeviation(double value);

    double getVariance() const;
    void setVariance(double value);

    double getQ1() const;
    void setQ1(double value);

    double getQ2() const;
    void setQ2(double value);

    double getQ3() const;
    void setQ3(double value);

    virtual void print() override;

private:
    /**
     * @brief 평균
     */
    double mean;

    /**
     * @brief 표준편차
     */
    double standardDeviation;

    /**
     * @brief 분산
     */
    double variance;

    /**
     * @brief 제1분위수
     */
    double q1;

    /**
     * @brief 제2분위수, 중앙값
     */
    double q2;

    /**
     * @brief 제3분위수
     */
    double q3;
};

#endif // FOUNDTATIONSTATDATA_H
