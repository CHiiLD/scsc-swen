#ifndef NULLHYPOTHESIS_H
#define NULLHYPOTHESIS_H

#include "nullhypothesisparameter.h"

#define NULL_HYPOTHESIS_REJECT_FAIL 0
#define NULL_HYPOTHESIS_REJECT_SECCESS 1

/**
 * @brief 가설검정 클래스
 */
class NullHypothesis
{
private:
    /**
     * @brief student
     * @param number
     * @param t
     * @return
     */
    static double student(int number, double t);

    /**
     * @brief t_integration
     * @param alpha
     * @param num
     * @return
     */
    static double t_integration(double alpha, int num);

    /**
     * @brief standard_normal
     * @param z
     * @return
     */
    static double standard_normal(double z);

    /**
     * @brief z_integration
     * @param alpha
     * @return
     */
    static double z_integration(double alpha);

    /**
     * @brief critical_region1
     * @param n
     * @param alpha
     * @return
     */
    static double critical_region1(int n, double alpha);

    /**
     * @brief critical_region2
     * @param n
     * @param alpha
     * @return
     */
    static double critical_region2(int n, double alpha);

    /**
     * @brief critical_region3
     * @param n
     * @param alpha
     * @return
     */
    static double critical_region3(int n, double alpha);
public:
    /**
     * @brief 가설검정을 수행합니다.
     * @param testStatistic 검정통계량
     * @param standardDeviation 표준편차
     * @param dataSize 표본개수
     * @param testValue 검정값
     * @param alpha 유의수준, 0.0~1.0 사이의 값을 가집니다.
     * @param sign 부호
     * @return 기각(NULL_HYPOTHESIS_REJECT_SECCESS)과 기각실패(NULL_HYPOTHESIS_REJECT_FAIL)의 결과를 반환합니다. 잘못된 매개변수의 입력 시 -1(error)을 반환합니다.
     */
    static int hyphothesis(double testStatistic, double standardDeviation, int dataSize, double testValue, double alpha, NullHypothesisSign sign);

    /**
     * @brief 가설검정을 수행합니다.
     * @param parameter NullHypothesisParameter 인스턴스
     * @return 기각(NULL_HYPOTHESIS_REJECT_SECCESS)과 기각실패(NULL_HYPOTHESIS_REJECT_FAIL)의 결과를 반환합니다. 잘못된 매개변수의 입력 시 -1(error)을 반환합니다.
     */
    static int hyphothesis(NullHypothesisParameter parameter);
};

#endif // NULLHYPOTHESIS_H
