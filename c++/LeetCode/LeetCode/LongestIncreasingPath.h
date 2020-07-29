#include <vector>

using namespace std;

#ifndef LONGESTINCREASINGPATH_H

#define LONGESTINCREASINGPATH_H

int longestIncreasingPath(vector<vector<int>>& matrix);

//int takeAStep(vector<vector<int>>& matrix, vector<vector<int>>& hist, int startR, int startC);
int takeAStep(vector<vector<int>>& matrix, vector<int>& hist, int startR, int startC);

#endif // !LONGESTINCREASINGPATH_H
