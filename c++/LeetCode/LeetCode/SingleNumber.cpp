#include "SingleNumber.h"

/*
    题目描述：
        给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

    说明：
        你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

    示例1：
        输入: [2,2,1]
        输出: 1

    示例2：
        输入: [4,1,2,1,2]
        输出: 4
*/

/*
    解法1：顺序遍历数组，依次二进制异或，最终值就是要找的数
    缺点：内存消耗太大，另外rslt初始值设为nums[0]，循环从1开始，可以少一次循环

    知识点：
        1. vector.size()返回的不是int类型需要强转？貌似是警告，不是编译错误
        2. 
*/
int singleNumber(vector<int>& nums) {
    int rslt = 0;
    for (int i = 0; i < int(nums.size()); i++) {
        rslt ^= nums[i];
    }
    return rslt;
}

/*
    解法1：不使用额外空间
    缺点：内存消耗还是很大

    知识点：
        1. 
        2.
*/
//int singleNumber(vector<int>& nums) {
//    for (int i = 1; i < int(nums.size()); i++) {
//        nums[0] ^= nums[i];
//    }
//    return nums[0];
//}