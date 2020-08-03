#include "FindMagicIndex.h"

/*
    题目描述：
        魔术索引。 在数组A[0...n-1]中，有所谓的魔术索引，满足条件A[i] = i。
        给定一个有序整数数组，编写一种方法找出魔术索引，若有的话，在数组A中找出一个魔术索引，如果没有，则返回-1。若有多个魔术索引，返回索引值最小的一个。

    示例1：
        输入：nums = [0, 2, 3, 4, 5]
        输出：0
        说明: 0下标的元素为0

    示例2：
        输入：nums = [1, 1, 1]
        输出：1

    提示：nums长度在[1, 1000000]之间
*/

/*
    解法2：跳跃搜索
    缺点：

    知识点：
        1. 
*/
int findMagicIndex(vector<int>& nums) {
    for (int i = 0; i < nums.size();) {
        if (i == nums[i]) {
            return i;
        }
        i = (i + 1) >= nums[i] ? (i + 1) : nums[i];
    }
    return -1;
}

/*
    解法1：朴实无华的oN循环
    缺点：时间复杂度不够优秀

    知识点：
        1. 
*/
//int findMagicIndex(vector<int>& nums) {
//    for (int i = 0; i < nums.size(); i++) {
//        if (i == nums[i]) {
//            return i;
//        }
//    }
//    return -1;
//}