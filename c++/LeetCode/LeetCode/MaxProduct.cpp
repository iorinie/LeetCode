#include "MaxProduct.h"

/*
    题目描述：
        给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

    示例：
        输入: [2,3,-2,4]
        输出: 6
        解释: 子数组 [2,3] 有最大乘积 6。

        输入: [-2,0,-1]
        输出: 0
        解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

        输入: [-2,3,-4]
        输出: 24
*/

/*
    解法1：动态规划，dp[i]表示以nums[i]结尾的最大乘积
    难点：
    知识点：
        1. 
*/
int maxProduct(vector<int>& nums) {
    vector<int> dp;
    vector<int> dp_;
    dp.push_back(nums[0]);
    dp_.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
        if (dp_[i - 1] * nums[i] < 0) {
            dp.push_back(nums[i]);
        }
        else {
            dp.push_back(dp_[i - 1] * nums[i]);
        }
        if (dp_[i - 1] * nums[i] != 0) {
            dp_.push_back(dp_[i - 1] * nums[i]);
        }
        else {
            dp_.push_back(nums[i]);
        }
    }

    int max = dp[0];
    for (int i = 1; i < dp.size(); i++) {
        max = max >= dp[i] ? max : dp[i];
    }

    return max;
}