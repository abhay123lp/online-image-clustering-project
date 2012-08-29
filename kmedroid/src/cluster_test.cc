// HERC Lab 2012
// zhangf@email.sc.edu
/////////////////////////////

#include <iostream>
#include <vector>

#include "cluster.h"
#include "distance_matrix.h"
#include "gtest/gtest.h"

using kmedroid::Cluster;
using kmedroid::ClusterSet;
using kmedroid::DistanceMatrix;
using std::vector;
using std::cerr;
using std::endl;

class ClusterTest : public testing::Test {
 public:
  void SetUp() {
    distance_matrix_.Set(0, 1, 6);
    distance_matrix_.Set(0, 2, 7);
    distance_matrix_.Set(0, 3, 2);
    distance_matrix_.Set(0, 4, 3);
    distance_matrix_.Set(0, 5, 9);

    distance_matrix_.Set(1, 2, 5);
    distance_matrix_.Set(1, 3, 10);
    distance_matrix_.Set(1, 4, 11);
    distance_matrix_.Set(1, 5, 11);

    distance_matrix_.Set(2, 3, 2);
    distance_matrix_.Set(2, 4, 2);
    distance_matrix_.Set(2, 5, 5);

    distance_matrix_.Set(3, 4, 1);
    distance_matrix_.Set(3, 5, 2);

    distance_matrix_.Set(4, 5, 12);

    cluster_.insert(0);
    cluster_.insert(1);
    cluster_.insert(2);
    cluster_.insert(3);
    cluster_.insert(4);   
    cluster_.insert(5);
  }
 public:
  DistanceMatrix distance_matrix_;
  Cluster cluster_;
};

class ClusterSetTest : public testing::Test {
 public:
  void SetUp() {
    vector<int> point_set;
    point_set.push_back(1);
    point_set.push_back(2);
    point_set.push_back(3);
    point_set.push_back(4);
    point_set.push_back(5);

    point_set.push_back(21);
    point_set.push_back(22);
    point_set.push_back(23);
    point_set.push_back(24);
    point_set.push_back(25);

    point_set.push_back(41);
    point_set.push_back(42);
    point_set.push_back(43);
    point_set.push_back(44);
    point_set.push_back(45);
    
    for (vector<int>::const_iterator it_i = point_set.begin();
         it_i != point_set.end(); ++it_i) {
      for (vector<int>::const_iterator it_j = it_i;
         it_j != point_set.end(); ++it_j) {
        distance_matrix_.Set(*it_i, *it_j, abs(*it_i - *it_j));
      }
    }
    
    Cluster temporary_cluster;
    temporary_cluster.insert(1);
    cluster_set_.push_back(temporary_cluster);
    temporary_cluster.clear();

    temporary_cluster.insert(21);
    cluster_set_.push_back(temporary_cluster);
    temporary_cluster.clear();

    temporary_cluster.insert(41);
    cluster_set_.push_back(temporary_cluster);
    temporary_cluster.clear();
    
    for (int i =  0; i < cluster_set_.size(); ++i) {
      cluster_set_[i].RandomizeCentroid();
    }
  }
 public:
  DistanceMatrix distance_matrix_;
  ClusterSet cluster_set_;
};

TEST_F(ClusterTest, TestElectCentroid) {
  cluster_.RandomizeCentroid();
  cluster_.ElectCentroid(distance_matrix_);
  assert(cluster_.get_centroid() == 3);
}

TEST_F(ClusterSetTest, TestAddPoint) {
  // cluster_set_.Print();
  cluster_set_.AddPoint(5, distance_matrix_);
  cluster_set_.AddPoint(25, distance_matrix_);
  cluster_set_.AddPoint(45, distance_matrix_);
  // cluster_set_.Print();
  assert(cluster_set_[0].find(5) != cluster_set_[0].end());
  assert(cluster_set_[1].find(25) != cluster_set_[1].end());
  assert(cluster_set_[2].find(45) != cluster_set_[2].end());
}

TEST_F(ClusterSetTest, TestReCluster) {
  cluster_set_.AddPoint(2, distance_matrix_);
  cluster_set_.AddPoint(3, distance_matrix_);
  cluster_set_.AddPoint(4, distance_matrix_);
  cluster_set_.AddPoint(5, distance_matrix_);
  cluster_set_.AddPoint(22, distance_matrix_);
  cluster_set_.AddPoint(23, distance_matrix_);
  cluster_set_.AddPoint(24, distance_matrix_);
  cluster_set_.AddPoint(25, distance_matrix_);
  cluster_set_.AddPoint(42, distance_matrix_);
  cluster_set_.AddPoint(43, distance_matrix_);
  cluster_set_.AddPoint(44, distance_matrix_);
  cluster_set_.AddPoint(45, distance_matrix_);  

  cluster_set_.ReClustering(distance_matrix_);

  assert(cluster_set_[0].get_centroid() == 3);
  assert(cluster_set_[1].get_centroid() == 23);
  assert(cluster_set_[2].get_centroid() == 43);
}


int main(int argc, char ** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

