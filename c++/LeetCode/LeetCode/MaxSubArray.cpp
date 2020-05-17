#include "MaxSubArray.h"

/*
    题目描述：
        给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

    示例：
        输入: [-2,1,-3,4,-1,2,1,-5,4],
        输出: 6
        解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

    进阶：
        如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
*/

/*
    解法1：动态规划，dp[i]表示以nums[i]结尾的最大和（这个最大和的概念，要结合代码细品），则dp数组中的最大值即为题解。
    难点：一开始只考虑到nums[i - 1]的正负，因此dp转移方式非常复杂，完全没想到直接判断dp[i - 1]的正负就行了。
    知识点：
        1. 两个for循环的循环次数是一样的，可以精简为一个for。例如MaxProfit.cpp中的处理。
        2. 注意！！！！访问未定义的vector下标，越界报错！！！！
*/
int maxSubArray(vector<int>& nums) {
    vector<int> dp;
    dp.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
        if (dp[i - 1] <= 0) {
            dp.push_back(nums[i]);
        }
        else {
            dp.push_back(dp[i - 1] + nums[i]);
        }
    }

    int max = dp[0];
    for (int i = 1; i < dp.size(); i++) {
        max = max >= dp[i] ? max : dp[i];
    }

    return max;
}