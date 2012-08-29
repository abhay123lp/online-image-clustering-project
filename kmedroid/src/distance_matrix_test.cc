// HERC 2012
// zhangf@email.sc.edu

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include "distance_matrix.h"

using namespace std;
using kmedroid::DistanceMatrix;

int main(int argc, char ** argv) {
  DistanceMatrix matrix_instance;
  for (int i = 0; i < 1000; ++i) {
    for (int j = 0; j < i; ++j) {
      matrix_instance.Set(i, j, abs(i-j));
    }
  }

  for (int i = 0; i < 1000; ++i) {
    for (int j = 0; j < i; ++j) {
      float dist = matrix_instance.Get(i, j);
      assert(dist == abs(i-j));
    }
  }
} 
