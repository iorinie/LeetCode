#include "MovingCount.h"
#include <vector>

using namespace std;

/*
    题目描述：
        地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
        一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
        例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

    示例1：
        输入：m = 2, n = 3, k = 1
        输出：3

    示例2：
        输入：m = 3, n = 1, k = 0
        输出：1

    示例3：
        输入：m = 1, n = 2, k = 1
        输出：2

    提示：
        1. 1 <= n,m <= 100
        2. 0 <= k <= 20
*/
/*
    解法2：深度优先遍历，去掉往上往左的分支，并且更改辅助函数的返回类型
    缺点：
    知识点：
        1.
*/
int movingCount(int m, int n, int k) {
    vector<vector<int>> visited(m, vector<int>(n));

    return dfs(m, n, k, 0, 0, visited);
}

int dfs(int m, int n, int k, int r, int c, vector<vector<int>>& visited) {
    if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] || (r / 10 + r % 10 + c / 10 + c % 10 > k)) {
        return 0;
    }

    visited[r][c] = 1;

    return 1 + dfs(m, n, k, r + 1, c, visited) + dfs(m, n, k, r, c + 1, visited);
}

/*
    解法1：深度优先遍历，
    缺点：时空复杂度这么高？
    知识点：
        1.
*/
//int rslt;
//
//vector<vector<int>> visited;
//
//int movingCount(int m, int n, int k) {
//    rslt = 0;
//    for (int i = 0; i < m; i++) {
//        vector<int> tempV;
//        for (int j = 0; j < n; j++) {
//            tempV.push_back(0);
//        }
//        visited.push_back(tempV);
//    }
//
//    dfs(m, n, k, 0, 0);
//
//    return rslt;
//}
//
//void dfs(int m, int n, int k, int r, int c) {
//    if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] || (r / 10 + r % 10 + c / 10 + c % 10 > k)) {
//        return;
//    }
//
//    visited[r][c] = 1;
//    rslt++;
//
//    dfs(m, n, k, r - 1, c);
//    dfs(m, n, k, r + 1, c);
//    dfs(m, n, k, r, c - 1);
//    dfs(m, n, k, r, c + 1);
//}