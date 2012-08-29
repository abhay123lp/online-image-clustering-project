#include "vector"
#include "cmath"
using namespace std;


double Dist(double * node_x, double * node_y, int dim_num)
{
    int i;
    double sum=0;
    for(i=0;i<dim_num;i++)
    {
        sum+=(node_x[i]-node_y[i])*(node_x[i]-node_y[i]);
    }
    sum=sqrt(sum);
    return sum;
}

void DBScan_CPU(double ** nodes, int * cluster_no, int node_num, int dim_num, double eps)
{
   double tmp;
   int cur_no=0;
   for(i=0;i<node_num;i++)
   {
      cluster_no=-1;
   }
   for(i=0;i<node_num;i++)
   {
      if(cluster_no[i]==-1)
      {
          cluster_no[i]=cur_no;
          for(j=i+1;j<node_num;j++)
          {
             if(cluster_no[j]==-1)
             {
                tmp=Dist(nodes,i,j,dim_num);
                if(tmp<=eps)
                {
                    cluster_no[j]=cluster_no[i];
                }
             }
             else
             {
             }
          }
      }
      else
      {
      }
   }
}

void DBScan_Expand()
