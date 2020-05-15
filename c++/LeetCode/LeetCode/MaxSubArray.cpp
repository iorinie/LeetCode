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
    解法1：动态规划，max = {当前i值，前面i-1的max值，更新max值起到当前值前累加的正值+当前i值}
    难点：
    知识点：
        1. 
        2. 
*/
int maxSubArray(vector<int>& nums) {
    int max = nums[0];
    if (nums.size() == 1) {
        return max;
    }
    int tempPositive = 0; //更新max值起到当前值前累加的正值
    for (int i = 1; i < nums.size(); i++) {
        max = maxOfThree(nums[i], max, tempPositive + nums[i]);
    }

    return max;
}

int maxOfThree(int a, int b, int c) {

}