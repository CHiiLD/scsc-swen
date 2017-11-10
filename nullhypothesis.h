#ifndef NULLHYPOTHESIS_H
#define NULLHYPOTHESIS_H

#include "nullhypothesisparameter.h"

#define NULL_HYPOTHESIS_REJECT_FAIL 0
#define NULL_HYPOTHESIS_REJECT_SECCESS 1

class NullHypothesis
{
private:
    static double student(int number, double t);
    static double t_integration(double alpha, int num);
    static double standard_normal(double z);
    static double z_integration(double alpha);
    static double critical_region1(int n, double alpha);
    static double critical_region2(int n, double alpha);
    static double critical_region3(int n, double alpha);
public:
    static int hyphothesis(double testStatistic, double standardDeviation, int dataSize, double testValue, double alpha, NullHypothesisSign sign);
    static int hyphothesis(NullHypothesisParameter parameter);
};

#endif // NULLHYPOTHESIS_H
