#include <vector>

using namespace std;

#ifndef UPDATEBOARD_H

#define UPDATEBOARD_H

vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click);

void recurseBoard(vector<vector<char>>& board, vector<vector<int>>& mineNums, vector<vector<bool>>& visited, int row, int colum);

void updateMineNums(vector<vector<int>>& mineNums, int row, int colum);

#endif // !UPDATEBOARD_H
