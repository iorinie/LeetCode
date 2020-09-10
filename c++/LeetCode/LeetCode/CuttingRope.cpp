#include "CuttingRope.h"
#include <vector>

using namespace std;

/*
    题目描述：
        给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。
        请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？
        例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

    示例1：
        输入: 2
        输出: 1
        解释: 2 = 1 + 1, 1 × 1 = 1

    示例2：
        输入: 10
        输出: 36
        解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36

    提示：2 <= n <= 58
*/
/*
    解法2：贪心
    缺点：
    知识点：
        1.
*/
int cuttingRope(int n) {
    if (n < 4) {
        return n - 1;
    }
    int rslt = 1;
    while (n > 4) {
        rslt *= 3;
        n -= 3;
    }
    return rslt * n;
}

/*
    解法1：从小到大推导结果，总结规律
    缺点：时间复杂度相对较高
    知识点：
        1.
*/
//int cuttingRope(int n) {
//    if (n == 2) {
//        return 1;
//    }
//    else if (n == 3) {
//        return 2;
//    }
//    else if (n == 4) {
//        return 4;
//    }
//    else if (n == 5) {
//        return 6;
//    }
//    else if (n == 6) {
//        return 9;
//    }
//
//    vector<int> dp(n + 1);
//    dp[2] = 1;
//    dp[3] = 2;
//    dp[4] = 4;
//    dp[5] = 6;
//    dp[6] = 9;
//    for (int i = 7; i <= n; i++) {
//        dp[i] = 3 * dp[i - 3];
//    }
//
//    return dp[n];
//}