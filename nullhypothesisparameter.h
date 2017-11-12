#ifndef NULLHYPOTHESISPARAMETER_H
#define NULLHYPOTHESISPARAMETER_H
#include <QString>
#include "aprint.h"

#define NULL_HYPOTHESIS_SIGN_LESS_THEN ">"
#define NULL_HYPOTHESIS_SIGN_GREATER_THEN "<"
#define NULL_HYPOTHESIS_SIGN_NEIN "≠"

enum class NullHypothesisSign
{
    NONE,
    LESS_THEN,
    GREATER_THEN,
    NOT_EQUAL
};

/**
 * @brief 가설검정 데이터 클래스
 */
class NullHypothesisParameter : public Print
{
public:
    NullHypothesisParameter();
    NullHypothesisParameter(double testStatistic, double standardDeviation, int dataSize, double testValue, double alpha, NullHypothesisSign sign);

    double getTestStatistic() const;
    void setTestStatistic(double value);

    double getStandardDeviation() const;
    void setStandardDeviation(double value);

    int getDataSize() const;
    void setDataSize(int value);

    double getAlpha() const;
    void setAlpha(double value);

    NullHypothesisSign getSign() const;
    void setSign(const NullHypothesisSign &value);

    double getTestValue() const;
    void setTestValue(double value);

    /**
     * @brief 클래스 정보를 출력합니다.
     */
    virtual void print() override;

private:
    /**
     * @brief 검정통계량
     */
    double testStatistic;

    /**
     * @brief 표본표쥰오차
     */
    double standardDeviation;

    /**
     * @brief 표본 개수
     */
    int dataSize;

    /**
     * @brief 검정값
     */
    double testValue;

    /**
     * @brief 유의수준
     */
    double alpha;

    /**
     * @brief 귀무가설의 기호
     */
    NullHypothesisSign sign;
};

#endif // NULLHYPOTHESISPARAMETER_H
