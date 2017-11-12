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
private:
   /**
    * @brief t분포 함수를 계산합니다
    * @param number 표본개수
    * @param t 확률변수
    * @return t분포값
    */
   static double student(int number, double t);

   /**
    * @brief t분포의 백분위수를 계산합니다.
    * @param alpha 유의수준
    * @param num 표본개수
    * @return t분포의 백분위수
    */
   static double t_integration(double alpha, int num);

   /**
    * @brief 정규분포 함수를 계산합니다
    * @param z 확률변수
    * @return 정규본포값
    */
   static double standard_normal(double z);

   /**
    * @brief 정규분포의 백분위수를 계산합니다.
    * @param alpha 유의수준
    * @return 정규분포의 백분위수
    */
   static double z_integration(double alpha);

   /**
    * @brief 귀무가설이 '>'일 때의 기각역을 계산합니다.
    * @param n 표본개수
    * @param alpha 유의수준
    * @return 기각역
    */
   static double critical_region1(int n, double alpha);

   /**
    * @brief 귀무가설이 '<'일 때의 기각역을 계산합니다.
    * @param n 표본개수
    * @param alpha 유의수준
    * @return 기각역
    */
   static double critical_region2(int n, double alpha);

   /**
    * @brief 귀무가설이 '!='일 때의 기각역을 계산합니다.
    * @param n 표본개수
    * @param alpha 유의수준
    * @return 기각역
    */
    static double critical_region3(int n, double alpha);
public:
    /**
     * @brief 가설검정을 수행합니다.
     * @param mean 표본평균
     * @param standardDeviation 표본표준편차
     * @param dataSize 표본개수
     * @param testValue 검정값
     * @param alpha 유의수준, 0.0~1.0 사이의 값을 가집니다.
     * @param sign 부호
     * @return 기각(NULL_HYPOTHESIS_REJECT_SECCESS)과 기각실패(NULL_HYPOTHESIS_REJECT_FAIL)의 결과를 반환합니다. 잘못된 매개변수의 입력 시 -1(error)을 반환합니다.
     */
    static int hyphothesis(double mean, double standardDeviation, int dataSize, double testValue, double alpha, NullHypothesisSign sign);

    /**
     * @brief 가설검정을 수행합니다.
     * @param parameter NullHypothesisParameter 인스턴스
     * @return 기각(NULL_HYPOTHESIS_REJECT_SECCESS)과 기각실패(NULL_HYPOTHESIS_REJECT_FAIL)의 결과를 반환합니다. 잘못된 매개변수의 입력 시 -1(error)을 반환합니다.
     */
    static int hyphothesis(NullHypothesisParameter parameter);
};

#endif // NULLHYPOTHESIS_H
