#include "CanPartition.h"
#include <algorithm>

/*
    题目描述：
        给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

    注意：
        1. 每个数组中的元素不会超过 100
        2. 数组的大小不会超过 200

    示例1：
        输入：[1, 5, 11, 5]
        输出：true
        解释：数组可以分割成 [1, 5, 5] 和 [11]

    示例2：
        输入：[1, 2, 3, 5]
        输出：false
        解释：数组不能分割成两个元素和相等的子集
*/
/*
    解法2：背包问题，动态规划
    缺点：
    知识点：
        1.
*/
bool canPartition(vector<int>& nums) {
    return true;
}

/*
    解法1：全排列比较总和的一半
    缺点：超时 超时 超时！
    知识点：
        1.
*/
//bool canPartition(vector<int>& nums) {
//    if (nums.size() <= 1) return false;
//
//    int sum = 0;
//    for (int i = 0; i < nums.size(); i++) {
//        sum += nums[i];
//    }
//    if (sum & 0x1) return false;
//
//    sort(nums.begin(), nums.end());
//
//    return dfs(nums, 0, 0, sum / 2);
//}
//
//bool dfs(vector<int>& nums, int startIdx, int tempSum, int target) {
//    if (startIdx == nums.size()) return false;
//
//    if (tempSum == target) return true;
//
//    for (int i = startIdx; i < nums.size() - 1; i++) {
//        bool isPart = dfs(nums, i + 1, tempSum + nums[i], target);
//        if (isPart) return true;
//    }
//
//    return false;
//}