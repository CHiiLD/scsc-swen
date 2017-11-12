#include "foundationstatdata.h"
#include <QDebug>

FoundationStatData::FoundationStatData() :
    mean(0), standardDeviation(0), variance(0), q1(0), q2(0), q3(0)
{

}

double FoundationStatData::getMean() const
{
    return mean;
}

void FoundationStatData::setMean(double value)
{
    mean = value;
}

double FoundationStatData::getStandardDeviation() const
{
    return standardDeviation;
}

void FoundationStatData::setStandardDeviation(double value)
{
    standardDeviation = value;
}

double FoundationStatData::getVariance() const
{
    return variance;
}

void FoundationStatData::setVariance(double value)
{
    variance = value;
}

double FoundationStatData::getQ1() const
{
    return q1;
}

void FoundationStatData::setQ1(double value)
{
    q1 = value;
}

double FoundationStatData::getQ2() const
{
    return q2;
}

void FoundationStatData::setQ2(double value)
{
    q2 = value;
}

double FoundationStatData::getQ3() const
{
    return q3;
}

void FoundationStatData::setQ3(double value)
{
    q3 = value;
}

void FoundationStatData::print()
{
    Print::print();
    qDebug() << "mean: " << mean;
    qDebug() << "variance: " << variance;
    qDebug() << "standard deviation: " << standardDeviation;
    qDebug() << "first quartile: " << q1;
    qDebug() << "second quartile: " << q2;
    qDebug() << "third quartile: " << q3;
}

FoundationStatDataBuilder *FoundationStatDataBuilder::setMean(double value)
{
    mean = value;
    return this;
}

FoundationStatDataBuilder *FoundationStatDataBuilder::setStandardDeviation(double value)
{
    standardDeviation = value;
    return this;
}

FoundationStatDataBuilder *FoundationStatDataBuilder::setVariance(double value)
{
    variance = value;
    return this;
}

FoundationStatDataBuilder *FoundationStatDataBuilder::setQ1(double value)
{
    q1 = value;
    return this;
}

FoundationStatDataBuilder *FoundationStatDataBuilder::setQ2(double value)
{
    q2 = value;
    return this;
}

FoundationStatDataBuilder *FoundationStatDataBuilder::setQ3(double value)
{
    q3 = value;
    return this;
}

FoundationStatData *FoundationStatDataBuilder::build()
{
    FoundationStatData* data = new FoundationStatData();
    data->setMean(mean);
    data->setStandardDeviation(standardDeviation);
    data->setVariance(variance);
    data->setQ1(q1);
    data->setQ2(q2);
    data->setQ3(q3);
    return data;
}
