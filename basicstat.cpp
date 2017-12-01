#include "basicstat.h"
#include "math.h"

int FoundationStat::mean(dataset data, double& mean)
{
    if(data.empty())
        return -1;

    double sum = 0;
    for(auto iter = data.begin(); iter != data.end(); ++iter)
        sum += *iter;
    mean = sum / data.size();
    return OK;
}

int FoundationStat::variance(dataset data, double& variance)
{
    double size = data.size(), sum;
    if(sumOfDeviationSquare(data, sum) != 0)
        return -1;

    if(size == 1)
        variance = 0;
    else
        variance = sum / (size - 1);

    return OK;
}

int FoundationStat::standardDeviation(dataset data, double& deviation)
{
    double variance;

    if(FoundationStat::variance(data, variance) != 0)
        return -1;

    deviation = sqrt(variance);
    return OK;
}

int FoundationStat::pecentile(dataset data, double pth, double& value)
{
    if(data.empty())
        return -1;

    if(!(0.0 <= pth && pth <= 1.0))
        return -1;

    data.sort(); // 데이터 정렬
    double np = data.size() * pth;
    auto iter = data.begin();
    int index;

    if(int(np) != np)
    {
        index = ceil(np) - 1;
        std::advance(iter, index);
        value = *iter;
    }
    else
    {
        double k1, k2;
        index = int(np) - 1;
        std::advance(iter, index);
        k1 = *iter;

        iter = data.begin();
        std::advance(iter, index + 1);
        k2 = *iter;

        value = (k1 + k2) / 2;
    }

    return OK;
}

int FoundationStat::correlationCoefficient(dataset dataX, dataset dataY, double& value)
{
    int size = dataX.size();
    dataset::iterator iterX, iterY;
    double S_xy = 0.0, meanX, meanY, sumX, sumY;

    if(dataX.size() != dataY.size())
        return -1;

    if(mean(dataX, meanX) != 0)
        return -1;

    if(mean(dataY, meanY) != 0)
        return -1;

    if(sumOfDeviationSquare(dataX, sumX) != 0)
        return -1;

    if(sumOfDeviationSquare(dataY, sumY) != 0)
        return -1;

    for(int i = 0; i < size; ++i)
    {
        iterX = dataX.begin();
        iterY = dataY.begin();
        std::advance(iterX, i);
        std::advance(iterY, i);
        S_xy += (*iterX - meanX) * (*iterY - meanY);
    }
    double S_xx = (sqrt(sumX));
    double S_yy = (sqrt(sumY));
    value = S_xy / (S_xx * S_yy);
    return OK;
}

int FoundationStat::sumOfDeviationSquare(dataset data, double& value)
{
    double mean;
    if(FoundationStat::mean(data, mean) != 0)
        return -1;

    value = 0;
    for(auto iter = data.begin(); iter != data.end(); ++iter)
        value += pow(mean - *iter, 2);

    return OK;
}
