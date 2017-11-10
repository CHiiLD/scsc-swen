#include "nullhypothesisparameter.h"

NullHypothesisParameter::NullHypothesisParameter() :
    testStatistic(0), standardDeviation(0), dataSize(0), testValue(0), alpha(0), sign(NullHypothesisSign::NONE)
{

}

NullHypothesisParameter::NullHypothesisParameter(double testStatistic, double standardDeviation, int dataSize, double testValue, double alpha, NullHypothesisSign sign) :
    testStatistic(testStatistic), standardDeviation(standardDeviation), dataSize(dataSize), testValue(testValue), alpha(alpha), sign(sign)
{

}

double NullHypothesisParameter::getTestStatistic() const
{
    return testStatistic;
}

void NullHypothesisParameter::setTestStatistic(double value)
{
    testStatistic = value;
}

double NullHypothesisParameter::getStandardDeviation() const
{
    return standardDeviation;
}

void NullHypothesisParameter::setStandardDeviation(double value)
{
    standardDeviation = value;
}

int NullHypothesisParameter::getDataSize() const
{
    return dataSize;
}

void NullHypothesisParameter::setDataSize(int value)
{
    dataSize = value;
}

double NullHypothesisParameter::getAlpha() const
{
    return alpha;
}

void NullHypothesisParameter::setAlpha(double value)
{
    alpha = value;
}

NullHypothesisSign NullHypothesisParameter::getSign() const
{
    return sign;
}

void NullHypothesisParameter::setSign(const NullHypothesisSign &value)
{
    sign = value;
}

double NullHypothesisParameter::getTestValue() const
{
    return testValue;
}

void NullHypothesisParameter::setTestValue(double value)
{
    testValue = value;
}
