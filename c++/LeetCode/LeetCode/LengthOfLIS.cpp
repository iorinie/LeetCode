#include "LengthOfLIS.h"

/*
    题目描述：
        给定一个无序的整数数组，找到其中最长上升子序列的长度。

    示例：
        输入: [10,9,2,5,3,7,101,18]
        输出: 4 
        解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。

    说明：
        可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
        你算法的时间复杂度应该为 O(n2) 。

    进阶：
        你能将算法的时间复杂度降低到 O(n log n) 吗?
*/

/*
    解法1：动态规划，dp[i]记录以nums[i]结尾的最长上升子序列的长度，dp中的最大值即为题解。
    难点：dp[i]的确定。在前面i - 1个数中（具体哪个记为j），只有nums[j]小于nums[i]的，才是上升的，所有符合的j，加上nums[i]这个数，长度为dp[j]+1，其中最大的dp[j]+1即为dp[i]。
    知识点：
        1. vector声明后，不能直接用v[x] = y的方式赋值
*/
int lengthOfLIS(vector<int>& nums) {
    vector<int> dp;
    for (int i = 0; i < nums.size(); i++) {
        //dp[i] = 1;
        dp.push_back(1);
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = dp[i] >= dp[j] + 1 ? dp[i] : dp[j] + 1;
            }
        }
    }

    int rslt = 0;
    for (int i = 0; i < dp.size(); i++) {
        rslt = rslt >= dp[i] ? rslt : dp[i];
    }

    return rslt;
}