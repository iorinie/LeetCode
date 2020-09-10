#include <vector>

using namespace std;

#ifndef MOVINGCOUNT_H

#define MOVINGCOUNT_H

int movingCount(int m, int n, int k);

//void dfs(int m, int n, int k, int r, int c);

int dfs(int m, int n, int k, int r, int c, vector<vector<int>>& visited);

#endif // !MOVINGCOUNT_H
