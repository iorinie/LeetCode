#include <string>
#include <vector>

using namespace std;

#ifndef GETPERMUTATION_H

#define GETPERMUTATION_H

string getPermutation(int n, int k);

void recurse(int n, int k, string& rslt, vector<int>& tempV);

#endif // !GETPERMUTATION_H
