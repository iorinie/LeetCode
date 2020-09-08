#include "Exist.h"

/*
    题目描述：
        请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
        路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。
        如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。
        例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

        [["a","b","c","e"],
        ["s","f","c","s"],
        ["a","d","e","e"]]

        但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。

    示例1：
        输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
        输出：true

    示例2：
        输入：board = [["a","b"],["c","d"]], word = "abcd"
        输出：false
*/
/*
    解法1：回溯，
    缺点：时空复杂度中等
    知识点：
        1. 
*/
bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == word[0]) {
                if (exist(board, word, i, j, 0))
                    return true;
            }
        }
    }
    return false;
}

bool exist(vector<vector<char>>& board, string word, int curR, int curC, int curTarIdx) {
    if (curTarIdx >= word.size()) {
        return true;
    }

    if (curR < 0 || curR >= board.size() || curC < 0 || curC >= board[curR].size() || board[curR][curC] == '.' || board[curR][curC] != word[curTarIdx]) {
        return false;
    }

    char tempC = board[curR][curC];
    board[curR][curC] = '.';
    bool rslt = exist(board, word, curR - 1, curC, curTarIdx + 1) || exist(board, word, curR + 1, curC, curTarIdx + 1) ||
        exist(board, word, curR, curC - 1, curTarIdx + 1) || exist(board, word, curR, curC + 1, curTarIdx + 1);

    board[curR][curC] = tempC;

    return rslt;
}