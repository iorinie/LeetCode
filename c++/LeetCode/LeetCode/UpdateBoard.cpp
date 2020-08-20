#include "UpdateBoard.h"

/*
    题目描述：
        让我们一起来玩扫雷游戏！
        给定一个代表游戏板的二维字符矩阵。 'M' 代表一个未挖出的地雷，'E' 代表一个未挖出的空方块，'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的已挖出的空白方块，数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，'X' 则表示一个已挖出的地雷。
        现在给出在所有未挖出的方块中（'M'或者'E'）的下一个点击位置（行和列索引），根据以下规则，返回相应位置被点击后对应的面板：

        1. 如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X'。
        2. 如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的未挖出方块都应该被递归地揭露。
        3. 如果一个至少与一个地雷相邻的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。
        4. 如果在此次点击中，若无更多方块可被揭露，则返回面板。

    示例1：
        输入：
            [['E', 'E', 'E', 'E', 'E'],
             ['E', 'E', 'M', 'E', 'E'],
             ['E', 'E', 'E', 'E', 'E'],
             ['E', 'E', 'E', 'E', 'E']]

            Click : [3,0]

        输出：
            [['B', '1', 'E', '1', 'B'],
             ['B', '1', 'M', '1', 'B'],
             ['B', '1', '1', '1', 'B'],
             ['B', 'B', 'B', 'B', 'B']]

    示例2：
        输入：
            [['B', '1', 'E', '1', 'B'],
             ['B', '1', 'M', '1', 'B'],
             ['B', '1', '1', '1', 'B'],
             ['B', 'B', 'B', 'B', 'B']]

            Click : [1,2]

        输出：
            [['B', '1', 'E', '1', 'B'],
             ['B', '1', 'X', '1', 'B'],
             ['B', '1', '1', '1', 'B'],
             ['B', 'B', 'B', 'B', 'B']]

    注意：
        1. 输入矩阵的宽和高的范围为 [1,50]。
        2. 点击的位置只能是未被挖出的方块 ('M' 或者 'E')，这也意味着面板至少包含一个可点击的方块。
        3. 输入面板不会是游戏结束的状态（即有地雷已被挖出）。
        4. 简单起见，未提及的规则在这个问题中可被忽略。例如，当游戏结束时你不需要挖出所有地雷，考虑所有你可能赢得游戏或标记方块的情况。
*/
/*
    解法1：递归每个可访问的格子，使用辅助数组记录历史
    缺点：
    知识点：
        1.
*/
vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    if (board[click[0]][click[1]] == 'M') { //点击的位置是地雷，满足处理规则1
        board[click[0]][click[1]] = 'X';
        return board;
    }

    int mineNear = 0; //点击的位置相邻的地雷数量
    //遍历相邻的位置
    for (int i = -1; i <= 1; i++) {
        if (click[0] + i < 0 || click[0] + i >= board.size()) {
            continue;
        }
        for (int j = -1; j <= 1; j++) {
            if (click[1] + j < 0 || click[1] + j >= board[click[0] + i].size() || (i == 0 && j == 0)) {
                continue;
            }
            if (board[click[0] + i][click[1] + j] == 'M') {
                mineNear++;
            }
        }
    }
    if (mineNear > 0) { //点击的位置与地雷相邻，满足处理规则3
        board[click[0]][click[1]] = mineNear + '0';
        return board;
    }

    //点击的位置附近没有地雷，满足处理规则2
    vector<vector<int>> mineNums(board.size(), vector<int>(board[0].size(), 0));
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    //递归地揭露相邻的位置
    recurseBoard(board, mineNums, visited, click[0], click[1]);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (visited[i][j] && board[i][j] == 'E') {
                if (mineNums[i][j] > 0) {
                    board[i][j] = mineNums[i][j] + '0';
                }
                else {
                    board[i][j] = 'B';
                }
            }
        }
    }

    return board;
}

void recurseBoard(vector<vector<char>>& board, vector<vector<int>>& mineNums, vector<vector<bool>>& visited, int row, int colum) {
    if (row < 0 || row >= board.size() || colum < 0 || colum >= board[row].size() || visited[row][colum]) {
        return;
    }
    for (int i = -1; i <= 1; i++) {
        if (row + i < 0 || row + i >= board.size()) {
            continue;
        }
        for (int j = -1; j <= 1; j++) {
            if (colum + j < 0 || colum + j >= board[row + i].size() || (i == 0 && j == 0)) {
                continue;
            }
            if (board[row + i][colum + j] == 'M' && !visited[row + i][colum + j]) { //不更改标记
                visited[row + i][colum + j] = true;
                updateMineNums(mineNums, row + i, colum + j);
            }
        }
    }
    visited[row][colum] = true;
    if (mineNums[row][colum] == 0) {
        recurseBoard(board, mineNums, visited, row - 1, colum - 1);
        recurseBoard(board, mineNums, visited, row - 1, colum);
        recurseBoard(board, mineNums, visited, row - 1, colum + 1);
        recurseBoard(board, mineNums, visited, row, colum - 1);
        recurseBoard(board, mineNums, visited, row, colum + 1);
        recurseBoard(board, mineNums, visited, row + 1, colum - 1);
        recurseBoard(board, mineNums, visited, row + 1, colum);
        recurseBoard(board, mineNums, visited, row + 1, colum + 1);
    }
}

void updateMineNums(vector<vector<int>>& mineNums, int row, int colum) {
    for (int i = -1; i <= 1; i++) {
        if (row + i < 0 || row + i >= mineNums.size()) {
            continue;
        }
        for (int j = -1; j <= 1; j++) {
            if (colum + j < 0 || colum + j >= mineNums[row + i].size() || (i == 0 && j == 0)) {
                continue;
            }
            mineNums[row + i][colum + j] += 1;
        }
    }
}