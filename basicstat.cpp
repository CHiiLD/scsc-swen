#include "basicstat.h"
#include "math.h"

int BasicStat::mean(std::list<double> data, double& mean)
{
    if(data.empty())
        return -1;

    double sum = 0;
    for(auto iter = data.begin(); iter != data.end(); ++iter)
        sum += *iter;
    mean = sum / data.size();
    return 0;
}

int BasicStat::variance(std::list<double> data, double& variance)
{
    double size = data.size(), sum;
    if(sumOfDeviationSquare(data, sum) != 0)
        return -1;

    variance = sum / (size - 1);
    return 0;
}

int BasicStat::standardDeviation(std::list<double> data, double& deviation)
{
    double variance;

    if(BasicStat::variance(data, variance) != 0)
        return -1;

    deviation = sqrt(variance);
    return 0;
}

int BasicStat::pecentile(std::list<double> data, double pth, double& value)
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

    return 0;
}

int BasicStat::correlationCoefficient(std::list<double> dataX, std::list<double> dataY, double& value)
{
    int size = dataX.size();
    std::list<double>::iterator iterX, iterY;
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
    return 0;
}

int BasicStat::sumOfDeviationSquare(std::list<double> data, double& value)
{
    double mean;

    if(BasicStat::mean(data, mean) != 0)
        return -1;

    for(auto iter = data.begin(); iter != data.end(); ++iter)
        value += pow(mean - *iter, 2);

    return 0;
}
