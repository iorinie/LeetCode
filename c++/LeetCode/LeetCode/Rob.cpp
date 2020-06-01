#include "Rob.h"

/*
    题目描述：
        你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
        给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

    示例1：
        输入: [1,2,3,1]
        输出: 4
        解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
             偷窃到的最高金额 = 1 + 3 = 4 。

    示例2：
        输入: [2,7,9,3,1]
        输出: 12
        解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。

    示例3：
        输入: [2,1,1,2]
        输出: 4

    示例4：
        输入: [6,6,4,8,4,3,3,10]
        输出: 27

    示例4：
        输入: [2,4,8,9,9,3]
        输出: 19
*/

/*
    解法3：动态规划，dp数组存储下标i时的最大值。dp[i] = max{dp[i - 2], dp[i - 3]} + nums[i]，dp[n - 1]和dp[n - 2]中的大值即为结果
    缺点：最简的状态转移方程应为dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])

    知识点：
        1. 
*/
int rob(vector<int>& nums) {
    int rslt = 0;
    if (nums.size() == 0) {
        return rslt;
    }else if (nums.size() == 1) {
        rslt = nums[0];
        return rslt;
    }else if (nums.size() == 2) {
        rslt = nums[0] >= nums[1] ? nums[0] : nums[1];
        return rslt;
    }
    vector<int> dp;
    dp.push_back(nums[0]);
    dp.push_back(nums[1]);
    dp.push_back(nums[0] + nums[2]);
    for (int i = 3; i < nums.size(); i++) {
        int bigger = dp[i - 2] >= dp[i - 3] ? dp[i - 2] : dp[i - 3];
        dp.push_back(bigger + nums[i]);
    }
    rslt = dp[dp.size() - 1] >= dp[dp.size() - 2] ? dp[dp.size() - 1] : dp[dp.size() - 2];

    return rslt;
}

/*
    解法2：贪心算法，双指针，每个指针选+2和+3下标中数字更大的
    缺点：示例4这种情况，完美错过了最佳答案

    知识点：
        1. 
*/
//int rob(vector<int>& nums) {
//    int rslt = 0;
//    if (nums.size() == 0) {
//        return rslt;
//    }
//    if (nums.size() == 1) {
//        rslt = nums[0];
//        return rslt;
//    }
//
//    int first = 0, second = 1; //双指针
//    int sumF = 0, sumS = 0;
//    while (first < nums.size()) {
//        sumF += nums[first];
//        if (first + 3 < nums.size()) {
//            first = nums[first + 2] >= nums[first + 3] ? first + 2 : first + 3;
//        }
//        else {
//            first = first + 2;
//        }
//    }
//    while (second < nums.size()) {
//        sumS += nums[second];
//        if (second + 3 < nums.size()) {
//            second = nums[second + 2] >= nums[second + 3] ? second + 2 : second + 3;
//        }
//        else {
//            second = second + 2;
//        }
//    }
//    rslt = sumF > sumS ? sumF : sumS;
//
//    return rslt;
//}

/*
    解法1：因为每间房是非负，要求最大，不能连续访问，那就直接求奇偶下标累加中的大值
    缺点：根本就不是缺点，这题的用例误导往奇偶数想，但是其实隔两个抢可能更多，炸裂

    知识点：
        1. &的优先级比==低，因此不能直接i & 1 == 0
        2. int型变量要初始化后才能使用
*/
//int rob(vector<int>& nums) {
//    int rslt = 0, sumEven = 0, sumOdd = 0;
//    for (int i = 0; i < nums.size(); i++) {
//        if ((i & 1) == 0) { //偶数
//            sumEven += nums[i];
//        }
//        else {
//            sumOdd += nums[i];
//        }
//    }
//    rslt = sumEven > sumOdd ? sumEven : sumOdd;
//
//    return rslt;
//}