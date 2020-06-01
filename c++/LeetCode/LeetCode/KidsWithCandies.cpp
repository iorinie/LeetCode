#include "KidsWithCandies.h"

/*
    题目描述：
        给你一个数组 candies 和一个整数 extraCandies ，其中 candies[i] 代表第 i 个孩子拥有的糖果数目。
        对每一个孩子，检查是否存在一种方案，将额外的 extraCandies 个糖果分配给孩子们之后，此孩子有 最多 的糖果。注意，允许有多个孩子同时拥有 最多 的糖果数目。

    示例1：
        输入：candies = [2,3,5,1,3], extraCandies = 3
        输出：[true,true,true,false,true] 
        解释：
        孩子 1 有 2 个糖果，如果他得到所有额外的糖果（3个），那么他总共有 5 个糖果，他将成为拥有最多糖果的孩子。
        孩子 2 有 3 个糖果，如果他得到至少 2 个额外糖果，那么他将成为拥有最多糖果的孩子。
        孩子 3 有 5 个糖果，他已经是拥有最多糖果的孩子。
        孩子 4 有 1 个糖果，即使他得到所有额外的糖果，他也只有 4 个糖果，无法成为拥有糖果最多的孩子。
        孩子 5 有 3 个糖果，如果他得到至少 2 个额外糖果，那么他将成为拥有最多糖果的孩子。

    示例2：
        输入：candies = [4,2,1,1,2], extraCandies = 1
        输出：[true,false,false,false,false] 
        解释：只有 1 个额外糖果，所以不管额外糖果给谁，只有孩子 1 可以成为拥有糖果最多的孩子。

    示例3：
        输入：candies = [12,1,12], extraCandies = 10
        输出：[true,false,true]

    提示：
        1. 2 <= candies.length <= 100
        2. 1 <= candies[i] <= 100
        3. 1 <= extraCandies <= 50
*/

/*
    解法1：由于小孩子数组长度较小，时间复杂度O(N)也是可以接受的，暴力两次遍历，第一次拿最大值，第二次判断大小
    缺点：因为没有排序，有许多重复劳动或者无用劳动。

    知识点：
        1. 
*/
vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> rslt;
    int max = 0;
    for (int i = 0; i < candies.size(); i++) {
        if (candies[i] > max) {
            max = candies[i];
        }
    }
    for (int i = 0; i < candies.size(); i++) {
        bool temp = candies[i] + extraCandies >= max ? true : false;
        rslt.push_back(temp);
    }

    return rslt;
}