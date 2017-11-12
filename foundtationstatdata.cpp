#include "foundtationstatdata.h"
#include <QDebug>

FoundtationStatData::FoundtationStatData() :
    mean(0), standardDeviation(0), variance(0), q1(0), q2(0), q3(0)
{

}

double FoundtationStatData::getMean() const
{
    return mean;
}

void FoundtationStatData::setMean(double value)
{
    mean = value;
}

double FoundtationStatData::getStandardDeviation() const
{
    return standardDeviation;
}

void FoundtationStatData::setStandardDeviation(double value)
{
    standardDeviation = value;
}

double FoundtationStatData::getVariance() const
{
    return variance;
}

void FoundtationStatData::setVariance(double value)
{
    variance = value;
}

double FoundtationStatData::getQ1() const
{
    return q1;
}

void FoundtationStatData::setQ1(double value)
{
    q1 = value;
}

double FoundtationStatData::getQ2() const
{
    return q2;
}

void FoundtationStatData::setQ2(double value)
{
    q2 = value;
}

double FoundtationStatData::getQ3() const
{
    return q3;
}

void FoundtationStatData::setQ3(double value)
{
    q3 = value;
}

void FoundtationStatData::print()
{
    Print::print();
    qDebug() << "mean: " << mean;
    qDebug() << "variance: " << variance;
    qDebug() << "standard deviation: " << standardDeviation;
    qDebug() << "first quartile: " << q1;
    qDebug() << "second quartile: " << q2;
    qDebug() << "third quartile: " << q3;
}
