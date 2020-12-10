// This file will be saved as "header_practice.h"
#ifndef HEADER_PRACTICE_H
#define HEADER_PRACTICE_H
#include <vector>
using std::vector;

/* Option 1 : where the inout arguments are not named
int IncrementAndComputeVectorSum(vector<int>);
void AddOneToEach(vector<int>&);
*/

// Option 2 : where the inouts are named!
int IncrementAndComputeVectorSum(vector<int> v);
void AddOneToEach(vector<int> &v);

#endif