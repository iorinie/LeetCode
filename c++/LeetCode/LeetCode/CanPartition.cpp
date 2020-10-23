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
    解法2：转换为背包问题，动态规划
    缺点：每一行的状态只和上一层有关，可以不用二维数组保存dp
    知识点：
        1.
*/
bool canPartition(vector<int>& nums) {
    int nLen = nums.size();
    if (nLen <= 1) return false;

    int sum = 0;
    int maxSub = 0;
    for (int i = 0; i < nLen; i++) {
        sum += nums[i];
        if (nums[i] > maxSub) maxSub = nums[i];
    }
    if (sum & 1) return false;
    int target = sum / 2;
    if (maxSub > target) return false;

    vector<vector<bool>> dp(nLen, vector<bool>(target + 1, true));
    for (int j = 1; j <= target; j++) {
        dp[0][j] = nums[0] == j;
    }
    for (int i = 1; i < nLen; i++) {
        for (int j = 1; j <= target; j++) {
            if (nums[i] > j) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
            }
        }
    }

    return dp[nLen - 1][target];
}

/*
    解法3：转换为背包问题，动态规划，解法2优化版
    缺点：
    知识点：
        1.
*/
//bool canPartition(vector<int>& nums) {
//    int nLen = nums.size();
//    if (nLen <= 1) return false;
//
//    int sum = 0;
//    int maxSub = 0;
//    for (int i = 0; i < nLen; i++) {
//        sum += nums[i];
//        if (nums[i] > maxSub) maxSub = nums[i];
//    }
//    if (sum & 1) return false;
//    int target = sum / 2;
//    if (maxSub > target) return false;
//
//    vector<bool> dp(target + 1, true);
//    for (int j = 1; j <= target; j++) {
//        dp[j] = nums[0] == j;
//    }
//    for (int i = 1; i < nLen; i++) {
//        for (int j = target; j > 0; j--) {
//            if (nums[i] <= j) {
//                dp[j] = dp[j] || dp[j - nums[i]];
//            }
//        }
//    }
//
//    return dp[target];
//}

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