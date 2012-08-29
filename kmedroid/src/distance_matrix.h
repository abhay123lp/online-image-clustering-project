// HERC Lab 2012
// zhangf@email.sc.edu
///////////////////////////////////
// This header file defines the distance matrix

#ifndef KMEDROID_DISTANCE_MATRIX_H_
#define KMEDROID_DISTANCE_MATRIX_H_

#include <cfloat>
#include <boost/unordered_map.hpp>
#include <iostream>

#define MAX_DISTANCE FLT_MAX
#define UNDEFINED_DISTANCE -1
#define NAN_POINT_VALUE -1

namespace kmedroid {

using std::pair;
using boost::unordered_map;

typedef std::pair<int, int> CoordinatePair;

// the distance matrix is implemented by boost::unordered_map. It provides
// A set and a get function. If the get function cannot find the distance
// entry, it returns MAX_DISTANCE which is defined as the maximum value of
// an single precision float point number.  
class DistanceMatrix : public unordered_map<CoordinatePair, float> {
 public:
  float Get(int x, int y) const;
  void Set(int x, int y, float distance);

  void Print() const;
};

}  // namespace kmedroid
#endif  // KMEDROID_DISTANCE_MATRIX_H_
