#include "MinArray.h"

/*
    题目描述：
        把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
        输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。

    示例1：
        输入：[3,4,5,1,2]
        输出：1

    示例2：
        输入：[2,2,2,0,1]
        输出：0

    示例3：
        输入：[1,2,3,4,5]
        输出：1
*/

/*
    解法1：二分查找
    缺点：mid和right相同时，算法复杂度退化

    知识点：
        1. 最后一个else是精髓
*/
int minArray(vector<int>& numbers) {
    int rslt = numbers[0];

    int left = 0, right = numbers.size() - 1;
    if (numbers[left] < numbers[right]) {
        return rslt;
    }
    while (left < right) {
        int mid = left + ((right - left) >> 1);
        if (numbers[right] > numbers[mid]) {
            right = mid;
        }
        else if (numbers[right] < numbers[mid]) {
            left = mid + 1;
        }
        else {
            right--;
        }
    }

    return numbers[left];
}