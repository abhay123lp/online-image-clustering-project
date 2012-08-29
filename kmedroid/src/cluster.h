// HERC Lab 2012
// zhangf@email.sc.edu
/////////////////////////////
#ifndef KMEDROID_CLUSTER_H_
#define KMEDROID_CLUSTER_H_

#include <cfloat>
#include <cstdlib>
#include <time.h>
#include <vector>

#include <boost/unordered_set.hpp>
#include "distance_matrix.h"

#define MAX_DISTANCE FLT_MAX
#define UNDEFINED_DISTANCE -1
#define NAN_POINT_VALUE -1

namespace kmedroid {

using std::pair;
using std::vector;
using boost::unordered_set;
  
class Cluster : public unordered_set<int> {
 public:
  Cluster() { centroid_ = NAN_POINT_VALUE; }
  virtual ~Cluster() { }

  void ElectCentroid(const DistanceMatrix& matrix);
  void RandomizeCentroid();
    
  int get_centroid() { return centroid_; }
  void set_centroid(int centroid) { centroid_ = centroid; }

  void Print() const;

 private:
  int centroid_;
};

class ClusterSet : public vector<Cluster> {
 public:
  ClusterSet() { }
  virtual ~ClusterSet() { }
  
  void AddPoint(int point, const DistanceMatrix& matrix);
  void ReClustering(const DistanceMatrix& matrix);

  void Print() const;
};
  
}  // namespace kmedroid
#endif  // KMEDROID_CLUSTER_H_
