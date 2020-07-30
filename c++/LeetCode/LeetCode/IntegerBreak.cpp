#include "IntegerBreak.h"
#include <vector>

using namespace std;

/*
    题目描述：
        给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。

    示例1：
        输入: 2
        输出: 1
        解释: 2 = 1 + 1, 1 × 1 = 1。

    示例2：
        输入: 10
        输出: 36
        解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。

    说明：
        你可以假设 n 不小于 2 且不大于 58。
*/
/*
    解法2：这题其实就是‘割绳子’问题，可以用动态规划做
    缺点：怎么把几个小的数整合起来
    知识点：
        1.
*/
int integerBreak(int n) {
    if (n == 2) {
        return 1;
    }
    if (n == 3) {
        return 2;
    }
    if (n == 4) {
        return 4;
    }
    if (n == 5) {
        return 6;
    }
    if (n == 6) {
        return 9;
    }

    vector<int> dp(n + 1);
    dp[4] = 4;
    dp[5] = 6;
    dp[6] = 9;
    for (int i = 7; i <= n; i++) {
        dp[i] = 3 * dp[i - 3];
    }

    return dp[n];
}

/*
    解法1：数学归纳，最大值和3、4有关，有点类似于贪心
    缺点：纯凭直觉，没有严格证明，并且没有活用套路类型的算法，比如动态规划
    知识点：
        1.
*/
//int integerBreak(int n) {
//    if (n == 2) {
//        return 1;
//    }
//    if (n == 3) {
//        return 2;
//    }
//
//    int rslt = 1;
//
//    while (n / 3 != 0) {
//        if (n == 4) {
//            rslt *= 4;
//            n -= 4;
//            break;
//        }
//        rslt *= 3;
//        n -= 3;
//    }
//    if (n != 0) {
//        rslt *= n;
//    }
//
//    return rslt;
//}