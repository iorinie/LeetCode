#include "FindDuplicate.h"

/*
    题目描述：
        给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。

    示例1：
        输入: [1,3,4,2,2]
        输出: 2

    示例2：
        输入: [3,1,3,4,2]
        输出: 3

    说明：
        1. 不能更改原数组（假设数组是只读的）。
        2. 只能使用额外的 O(1) 的空间。
        3. 时间复杂度小于 O(n2) 。
        4. 数组中只有一个重复的数字，但它可能不止重复出现一次。
*/

/*
    解法1：如果没有重复数字的话，那么1应该在下标0、2在下标1、3在下标2，以此类推，如果某个数字对不上下标，则将其与应该在的下标数字做交换，交换时如果数字相等，则找到结果
    缺点：会改变原数组，不符合说明

    知识点：
        1. 不能改原数组，则限制不能做排序；空间复杂度为O1，则限制不能使用map来做
        2.
*/
int findDuplicate(vector<int>& nums) {
    int ptr = 0;
    while (ptr < nums.size()) {
        if (nums[ptr] != ptr + 1) {
            if (nums[ptr] == nums[nums[ptr] - 1]) {
                return nums[ptr];
            }
            int temp = nums[nums[ptr] - 1];
            nums[nums[ptr] - 1] = nums[ptr];
            nums[ptr] = temp;
        }
        else {
            ptr++;
        }
    }

    return 0;
}