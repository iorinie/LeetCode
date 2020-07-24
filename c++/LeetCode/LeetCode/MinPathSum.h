#include <vector>

using namespace std;

#ifndef MINPATHSUM_H

#define MINPATHSUM_H

int minPathSum(vector<vector<int>>& grid);

int findPath(int rslt, int tempSum, vector<vector<int>>& grid, int startH, int startV);

#endif // !MINPATHSUM_H
