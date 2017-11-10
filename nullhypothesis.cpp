#include "nullhypothesis.h"
#include <math.h>
#define PI 3.141592

// 가설검정---------------------------
// 1. t분포 (데이터의 개수가 30개 이하)
double NullHypothesis::student(int number, double t)		// t 분포 공식 (number : 표본 크기)
{
    int k = number - 1;	// t분포의 자유도는 n-1
    return tgamma((k + 1) / 2.0) / (sqrt((double)k*PI)*tgamma(k / 2.0)*pow(1.0 + t*t / k, (k + 1.0) / 2.0));
}

double NullHypothesis::t_integration(double alpha, int num)	// 적분(alpha,표본크기)
{
    double n = 1000.0;
    double sum = 0.0;
    double i = 0.0;
    for (;; i += 1.0 / n)
    {
        double w = student(num, i) / n;
        sum += w;
        if ((0.5 - sum) > alpha) continue;	// t분포의 범위는 무한대, 좌우대칭이기 때문에
        break;								// 0부터 더한 값을 0.5에서 빼면 오른쪽 꼬리 확률값이 나오게 된다.
    }
    return i;
}

//2. Z분포 (데이터의 개수가 30개 초과)
double NullHypothesis::standard_normal(double z)		// 표준정규분포 공식
{
    return exp(-(z*z) / 2.0) / sqrt(2.0*PI);
}

double NullHypothesis::z_integration(double alpha)	// 적분(alpha)
{
    double n = 1000.0;
    double sum = 0.0;
    double i = 0.0;
    for (;; i += 1.0 / n)
    {
        double w = standard_normal(i) / n;
        sum += w;
        if ((0.5 - sum) > alpha) continue;	// z분포의 범위는 무한대, 좌우대칭이기 때문에
        break;								// 0부터 더한 값을 0.5에서 빼면 오른쪽 꼬리 확률값이 나오게 된다.
    }
    return i;
}

double NullHypothesis::critical_region1(int n, double alpha)	// 기각역(>일때)
{
    if (n <= 30)	// 소표본 -> t분포 이용
        return t_integration(alpha, n);
    else    // 대표본 -> z분포 이용
        return z_integration(alpha);
}

double NullHypothesis::critical_region2(int n, double alpha)	// 기각역(<일때)
{
    if (n <= 30)	// 소표본 -> t분포 이용
        return -t_integration(alpha, n);
    else   // 대표본 -> z분포 이용
        return -z_integration(alpha);
}

double NullHypothesis::critical_region3(int n, double alpha)	// 기각역(!=일때)
{
    if (n <= 30)	// 소표본 -> t분포 이용
        return t_integration(alpha / 2.0, n);
    else   // 대표본 -> z분포 이용
        return z_integration(alpha / 2.0);
}

// 가설검정
int NullHypothesis::hyphothesis(double testStatistic, double standardDeviation, int dataSize, double testValue, double alpha, NullHypothesisSign sign)
{	// avg:표본평균,std:표본표준편차,n:표본개수,mu_zero:가설에서 비교하고 싶은 평균값,alpha=: 귀무가설이 참일 때 귀무가설을 기각하는 오류를 범할 확률(유의수준),sign:<,>,!=
    if(dataSize < 1)
        return -1;

    if(!(0.0 <= alpha && alpha <= 1.0))
        return -1;

    int result;
    double test_statistic = (testStatistic - testValue) / (standardDeviation / sqrt(dataSize));// 검정 통계량

    switch (sign)
    {
    case NullHypothesisSign::LESS_THEN:
        result = test_statistic >= critical_region1(dataSize, alpha) ? NULL_HYPOTHESIS_REJECT_SECCESS : NULL_HYPOTHESIS_REJECT_FAIL;
        break;
    case NullHypothesisSign::GREATER_THEN:
        result = test_statistic <= critical_region2(dataSize, alpha) ? NULL_HYPOTHESIS_REJECT_SECCESS : NULL_HYPOTHESIS_REJECT_FAIL;
        break;
    case NullHypothesisSign::NOT_EQUAL:
        result = test_statistic >= critical_region3(dataSize, alpha) ? NULL_HYPOTHESIS_REJECT_SECCESS : NULL_HYPOTHESIS_REJECT_FAIL;
        break;
    default:
        result = -1;
        break;
    }
    return result;
}

int NullHypothesis::hyphothesis(NullHypothesisParameter parameter)
{
    double xbar = parameter.getTestStatistic();
    double std = parameter.getStandardDeviation();
    int n = parameter.getDataSize();
    double tValue = parameter.getTestValue();
    double alpha = parameter.getAlpha();
    NullHypothesisSign sign = parameter.getSign();
    return hyphothesis(xbar, std, n, tValue, alpha, sign);
}
