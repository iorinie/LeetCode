#include "MaxProduct.h"
#include <iostream>

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
    解法1：动态规划，dp数组记录以下标i结尾的最大连续子数组的乘积
    难点：针对不同情况设置的累积变量，把自己都绕晕了，极差的思路，面向测试用例编程。已经理清楚逻辑并做了修改。
    知识点：
        1. 
*/
int maxProduct(vector<int>& nums) {
    int max = 0;
    
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    max = dp[0];

    int notZeroMul = nums[0] == 0 ? 1 : nums[0]; //从非0开始，到目前下标的乘积
    int negtiveCnt = nums[0] < 0 ? 1 : 0; //目前为止负数的个数，遇到0重置
    int shouldOut = nums[0] == 0 ? 1 : nums[0]; //第一个负数与之前所有连续正数的乘积

    for (int i = 1; i < nums.size(); i++) {
        if (notZeroMul * nums[i] > 0) { //自己前面非0数开始，一直乘到自己，都是正数，则最大连续即为这个乘积
            dp[i] = notZeroMul * nums[i];
        }
        else if (notZeroMul * nums[i] == 0) { //自己是0
            dp[i] = nums[i];
        }
        else { //自己前面非0数开始，一直乘到自己，是负数，则除去shouldOut（前面有0的情况其实有bug，这里需要更细致的区分）
            dp[i] = notZeroMul * nums[i] / shouldOut;
        }
        cout << dp[i] << endl;
        max = max >= dp[i] ? max : dp[i];

        if (nums[i] > 0) {
            notZeroMul *= nums[i];

            shouldOut = negtiveCnt >= 1 ? shouldOut : shouldOut * nums[i];
        }
        else if (nums[i] == 0) {
            notZeroMul = 1;
            negtiveCnt = 0;
            shouldOut = 1;
        }
        else {
            notZeroMul *= nums[i];
            negtiveCnt++;
            shouldOut = negtiveCnt > 1 ? shouldOut : shouldOut * nums[i];
        }
    }

    return max;
}