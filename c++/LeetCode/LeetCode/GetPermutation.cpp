#include "GetPermutation.h"

/*
    题目描述：
        给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。
        按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
        1. "123"
        2. "132"
        3. "213"
        4. "231"
        5. "312"
        6. "321"
        给定 n 和 k，返回第 k 个排列。

    说明：
        1. 给定 n 的范围是 [1, 9]。
        2. 给定 k 的范围是[1,  n!]。

    示例1：
        输入：n = 3, k = 3
        输出："213"

    示例2：
        输入：n = 4, k = 9
        输出："2314"

    示例3：
        输入：n = 8, k = 33856
        输出："?"
*/
/*
    解法2：数学归纳法，算了吧，要天分的
    缺点：
    知识点：
        1.
*/
//string getPermutation(int n, int k) {
//
//}

/*
    解法1：回溯
    缺点：超时，加上剪枝，才是正常人能想到的方法
    知识点：
        1. string作为函数参数时，是值拷贝，如果需要改变其值，需要传地址进去
*/
vector<int> factorial; //阶乘信息

vector<int> visited; //某个数字是否已经访问过

string getPermutation(int n, int k) {
    string rslt;

    factorial.push_back(1);
    for (int i = 1; i <= n; i++) {
        factorial.push_back(factorial[i - 1] * i);
    }
    for (int i = 0; i < n; i++) {
        visited.push_back(false);
    }
    vector<int> tempV;
    recurse(n, k, rslt, tempV);
    rslt = "";
    for (int i = 0; i < tempV.size(); i++) {
        rslt += tempV[i] + '0';
    }

    return rslt;
}

void recurse(int n, int k, string& rslt, vector<int>& tempV) {
    if (tempV.size() == n) {
        return;
    }

    int cnt = factorial[n - 1 - tempV.size()];
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;
        if (cnt < k) {
            k -= cnt;
            continue;
        }
        tempV.push_back(i + 1);
        visited[i] = true;
        recurse(n, k, rslt, tempV);

        return; //这里直接返回很重要
    }
}