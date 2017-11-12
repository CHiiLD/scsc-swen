#ifndef FOUNDTATIONSTATDATA_H
#define FOUNDTATIONSTATDATA_H

#include "aprint.h"

/**
 * @brief 기초 통계량 결과값 클래스
 */
class FoundationStatData : public Print
{
public:
    FoundationStatData();

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

/**
 * @brief FoundtationStatData 빌더 클래스
 */
class FoundationStatDataBuilder
{
public:
    FoundationStatDataBuilder* setMean(double value);
    FoundationStatDataBuilder* setStandardDeviation(double value);
    FoundationStatDataBuilder* setVariance(double value);
    FoundationStatDataBuilder* setQ1(double value);
    FoundationStatDataBuilder* setQ2(double value);
    FoundationStatDataBuilder* setQ3(double value);
    FoundationStatData* build();
private:
    double mean;
    double standardDeviation;
    double variance;
    double q1;
    double q2;
    double q3;
};

#endif // FOUNDTATIONSTATDATA_H
