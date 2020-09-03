#include "SolveNQueens.h"

/*
    题目描述：
        n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
        给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
        每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

    示例：
        输入：4
        输出：
        [
         [".Q..",  // 解法 1
          "...Q",
          "Q...",
          "..Q."],

         ["..Q.",  // 解法 2
          "Q...",
          "...Q",
          ".Q.."]
        ]

        解释：
            4 皇后问题存在两个不同的解法。

        提示：
            皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。
*/
/*
    解法1：回溯就完了
    缺点：时间复杂度有点高
    知识点：
        1.
*/
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> rslt;

    vector<string> path;
    for (int i = 0; i < n; i++) {
        string s(n, '.');
        path.push_back(s);
    }
    recurse(n, rslt, path, 0);

    return rslt;
}

void recurse(int n, vector<vector<string>>& rslt, vector<string>& path, int curRow) {
    if (curRow - 1 >= 0) { //上一行一个皇后都没有放
        string s(n, '.');
        if (path[curRow - 1] == s) {
            return;
        }
    }
    if (curRow >= n) {
        rslt.push_back(path);
        return;
    }
    for (int i = curRow; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isCrush(n, path, i, j)) {
                continue;
            }
            path[i][j] = 'Q';
            recurse(n, rslt, path, curRow + 1);
            path[i][j] = '.';
        }
    }
}

bool isCrush(int n, vector<string>& path, int r, int c) { //同行、同列、同斜线上已有皇后，则冲突（同行肯定没有）
    for (int i = 0; i < r; i++) {
        if (path[i][c] == 'Q') { //同一列已有皇后
            return true;
        }
        if ((c - r + i >= 0 && path[i][c - r + i] == 'Q') || (c + r - i < n && path[i][c + r - i] == 'Q')) { //同一斜线上已有皇后
            return true;
        }
    }

    return false;
}