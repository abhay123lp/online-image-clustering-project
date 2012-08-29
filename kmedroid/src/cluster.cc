// HERC Lab 2012
// zhangf@email.sc.edu
/////////////////////////////
#include <iostream>
#include <vector>

#include "cluster.h"

namespace kmedroid {

using kmedroid::DistanceMatrix;
using std::cerr;
using std::endl;

void Cluster::ElectCentroid(const DistanceMatrix& matrix) {
  int best_centroid = centroid_;
  float min_distance_sum = MAX_DISTANCE;
  
  for (boost::unordered_set<int>::const_iterator it = begin();
       it != end(); ++it) {
    float distance_sum = 0.0;
    for (boost::unordered_set<int>::const_iterator inner_it = begin();
         inner_it != end(); ++inner_it) {
      float distance = abs(matrix.Get(*it, *inner_it));
      assert(distance != MAX_DISTANCE);
      distance_sum += distance;
    }
    if (distance_sum < min_distance_sum) {
      min_distance_sum = distance_sum;
      best_centroid = *it;
    }
  }
  centroid_ = best_centroid;
}

void Cluster::RandomizeCentroid() {
  srand(time(0));
  int position = rand() % size();
  int i = 0;
  boost::unordered_set<int>::const_iterator it;
  for (it = begin(), i = 0; i < position; ++i, ++it);
  centroid_ = *it;
}

void Cluster::Print() const {
  cerr << "centroid : " << centroid_<< endl;
  cerr << "data : "<< endl;
  for (boost::unordered_set<int>::const_iterator it = begin();
       it != end(); ++it) {
    cerr << *it << " ";
  }
  cerr << endl;
}

void ClusterSet::AddPoint(int point, const DistanceMatrix& matrix){
  assert(point >=0);

  float min_distance = MAX_DISTANCE;
  vector<Cluster>::iterator closest_cluster_it = begin();

  for (vector<Cluster>::iterator it = begin();
       it != end(); ++it) {
    float current_distance = matrix.Get(point, it->get_centroid());
    // cerr << point << "," << it->get_centroid() << "," << current_distance << endl;
    if (current_distance < min_distance) {
      min_distance = current_distance;
      closest_cluster_it = it;
    }
  }
  closest_cluster_it->insert(point);   
}

void ClusterSet::ReClustering(const DistanceMatrix& matrix) {
  for (vector<Cluster>::iterator it = begin();
       it != end(); ++it) {
    it->ElectCentroid(matrix);
  }
  vector<int> new_centroids;
  vector<int> points;
  for (vector<Cluster>::iterator it = begin();
       it != end(); ++it) {
    new_centroids.push_back(it->get_centroid());
    for (boost::unordered_set<int>::const_iterator it_cluster = it->begin();
         it_cluster != it->end(); ++it_cluster) {
      points.push_back(*it_cluster);
    }
    it->clear();
  }
  
  for (vector<int>::iterator it_i = points.begin(); it_i != points.end();
       ++it_i) {
     AddPoint(*it_i, matrix);
  }
}

void ClusterSet::Print() const {
  cerr << "Cluster set : " << endl;
  for (vector<Cluster>::const_iterator it = begin();
       it != end(); ++it) {
    it->Print();
  }
}

}
    
