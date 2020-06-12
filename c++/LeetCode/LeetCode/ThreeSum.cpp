#include "ThreeSum.h"
#include <algorithm>

/*
    题目描述：
        给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

    示例1：
        给定数组 nums = [-1, 0, 1, 2, -1, -4]，
        满足要求的三元组集合为：
        [
          [-1, 0, 1],
          [-1, -1, 2]
        ]

    注意：
        答案中不可以包含重复的三元组。
*/

/*
    解法1：先对数组排序，然后使用三指针？
    缺点：

    知识点：
        1. 
        2.
*/
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> rslt;
    if (nums.size() < 3) {
        return rslt;
    }
    //quickSort(nums);
    sort(nums.begin(), nums.end());
    if (nums[0] > 0 || nums[nums.size() - 1] < 0) {
        return rslt;
    }
    int first = 0;
    while (first < nums.size() && nums[first] <= 0) {
        int second = first + 1;
        int third = nums.size() - 1;
        int target = -nums[first];
        while (second < third) {
            if (nums[second] + nums[third] == target) {
                vector<int> tempRslt;
                tempRslt.push_back(nums[first]);
                tempRslt.push_back(nums[second]);
                tempRslt.push_back(nums[third]);
                rslt.push_back(tempRslt);

                int offset = 1;
                while (second + offset < nums.size() && nums[second + offset] == nums[second]) {
                    offset++;
                }
                second += offset;
                third--;
            }
            else if (nums[second] + nums[third] > target) {
                third--;
            }
            else {
                second++;
            }
        }
        int offset = 1;
        while (first + offset < nums.size() && nums[first + offset] == nums[first]) {
            offset++;
        }
        first += offset;
    }

    return rslt;
}

void quickSort(vector<int>& nums) {

}