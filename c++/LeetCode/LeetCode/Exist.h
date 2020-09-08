#include <vector>
#include <string>

using namespace std;

#ifndef EXIST_H

#define EXIST_H

bool exist(vector<vector<char>>& board, string word);

bool exist(vector<vector<char>>& board, string word, int curR, int curC, int curTarIdx);

#endif // !EXIST_H
