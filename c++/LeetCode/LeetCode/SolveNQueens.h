#include <vector>
#include <string>

using namespace std;

#ifndef SOLVENQUEENS_H

#define SOLVENQUEENS_H

vector<vector<string>> solveNQueens(int n);

void recurse(int n, vector<vector<string>>& rslt, vector<string>& path, int curRow);

bool isCrush(int n, vector<string>& path, int r, int c);

#endif // !SOLVENQUEENS_H