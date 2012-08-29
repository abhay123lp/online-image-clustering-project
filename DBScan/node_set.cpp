#include "DBScan.h"

double point::euclidian_dist(const point &p1, const point &p2);
{
    int i;
    double sum=0;
    for(i=0;i<p1.size();i++)
    {
        sum+=(p1[i]-p2[i])*(p1[i]-p2[i]);
    }
    sum=sqrt(sum);
    return sum;
}


