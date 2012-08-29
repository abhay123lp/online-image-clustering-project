 
typedef {POINTSET, GAUSSIAN} NODE_SET_STATUS;

#define NUM_DIMENSION 16

class point : vector<double>
{
public:
   friend double euclidian_dist(const point &, const point &); 
};

class cluster
{
public:
   NODE_SET_STATUS nss;
   list<point *> pointset;

   int dim_num;
   int node_num;

   double * delta;
   double * miu;
public:
   
public:
   node_set();
   ~node_set();
   
   friend double Dist(const node_set &, const node_set &);
   friend double minDist(const node_set &, const node_set &);
   friend double maxDist(const node_set &, const node_set &);
   friend double avgDist(const node_set &, const node_set &); 
   friend void Gaussian_transform();
    
}
