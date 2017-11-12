#include "nullhypothesisparameter.h"
#include <QDebug>

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

void NullHypothesisParameter::print()
{
    Print::print();
    qDebug() << "test statistic: " << testStatistic;
    qDebug() << "standard deviation: " << standardDeviation;
    qDebug() << "alpha: " << alpha;
    qDebug() << "test value: " << testValue;
    qDebug() << "data count: " << dataSize;
    switch (sign)
    {
    case NullHypothesisSign::NOT_EQUAL:
        qDebug() << "sign: " << NULL_HYPOTHESIS_SIGN_NEIN;
        break;
    case NullHypothesisSign::LESS_THEN:
        qDebug() << "sign: " << NULL_HYPOTHESIS_SIGN_LESS_THEN;
        break;
    case NullHypothesisSign::GREATER_THEN:
        qDebug() << "sign: " << NULL_HYPOTHESIS_SIGN_GREATER_THEN;
        break;
    default:
        break;
    }
}
