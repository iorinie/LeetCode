#include "Combine.h"

/*
    题目描述：
        给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

    示例1：
        输入：n = 4, k = 2
        输出：[
                  [1,2],
                  [1,3],
                  [1,4],
                  [2,3],
                  [2,4],
                  [3,4],
              ]
*/
/*
    解法2：二进制枚举，具体参考https://leetcode-cn.com/problems/combinations/solution/zu-he-by-leetcode-solution/
    缺点：
    知识点：
        1. 
*/
//vector<vector<int>> combine(int n, int k) {
//
//}

/*
    解法1：带剪枝的回溯
    缺点：时间复杂度还是有点高
    知识点：
        1. 
*/
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> rslt;

    vector<int> path;
    vector<int> visited(n + 1);
    recurse(n, k, rslt, path, visited);

    return rslt;
}

void recurse(int n, int k, vector<vector<int>>& rslt, vector<int>& path, vector<int>& visited) {
    if (path.size() >= k) {
        rslt.push_back(path);
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] || (path.size() > 0 && i < path.back()))
            continue;

        path.push_back(i);
        visited[i] = 1;
        recurse(n, k, rslt, path, visited);
        visited[i] = 0;
        path.pop_back();
    }
}