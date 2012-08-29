// HERC 2012
// zhangf@email.sc.edu

#include <cassert>
#include <utility>
#include <iostream>

#include "distance_matrix.h"

namespace kmedroid {

using std::make_pair;
using std::cerr;
using std::endl;

float DistanceMatrix::Get(int x, int y) const {
  // Always set the point with smaller number in the front of the pair
  if (x == y)
    return 0.0;
  CoordinatePair xy;
  if (x > y)
    xy = make_pair(y, x);
  else
    xy = make_pair(x, y);

  unordered_map<CoordinatePair, float>::const_iterator it =
      find(xy);
  if (it == end()) {
    return MAX_DISTANCE;
  } else {
    return it->second;
  }
}

void DistanceMatrix::Set(int x, int y, float distance) {
  if (x ==y)
    return;
  CoordinatePair xy;
  if (x > y)
    xy = make_pair(y, x);
  else
    xy = make_pair(x, y);
  (*this)[xy] = distance;
}

void DistanceMatrix::Print() const {
  for (DistanceMatrix::const_iterator it =
           begin(); it != end(); ++it) {
    cerr << "(" << it->first.first << "," <<it->first.second << ") : "
         << it->second <<endl;
  }
} 

}  // namespace kmedroid
