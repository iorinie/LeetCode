#include <vector>

using namespace std;

/*
    题目描述：
        给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
        你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

    示例：
        给定 nums = [2, 7, 11, 15], target = 9
        因为 nums[0] + nums[1] = 2 + 7 = 9
        所以返回 [0, 1]
*/

/*
    解法1：将输入数组排序，然后一头一尾两指针，往中间移动，找两指针所指数字的和
    难点：由于返回值是下标，原始数组排序后，下标信息丢失，需要另外维护一组原始下标

    知识点：
        1. 引用作为函数参数传入
        2. 快排实现
*/
vector<int> twoSum(vector<int>& nums, int target) {
    //给nums排序并记录排序后的原始下标顺序
    vector<int> sourceIdx;
    for (int i = 0; i < int(nums.size()); i++) {
        sourceIdx.push_back(i);
    }
    quickSort(nums, sourceIdx, 0, nums.size() - 1);

    vector<int> rslt;
    rslt.push_back(-1);
    rslt.push_back(-1);
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        if (nums[left] + nums[right] == target) {
            if (sourceIdx[left] > sourceIdx[right]) {
                rslt[0] = sourceIdx[right];
                rslt[1] = sourceIdx[left];
            }
            else {
                rslt[0] = sourceIdx[left];
                rslt[1] = sourceIdx[right];
            }
            break;
        }
        else if (nums[left] + nums[right] < target) {
            left++;
        }
        else {
            right--;
        }
    }
    return rslt;
}

void quickSort(vector<int>& nums, vector<int>& sourceIdx, int start, int end) {
    if (start >= end) {
        return;
    }
    int base = nums[end]; //基准值
    int i = start, j = end; //左右指针
    while (i < j) {
        while (i <= end - 1 && nums[i] < base) {
            i++;
        }
        while (j >= start && nums[j] >= base) {
            j--;
        }
        if (i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            temp = sourceIdx[i];
            sourceIdx[i] = sourceIdx[j];
            sourceIdx[j] = temp;
        }
    }
    j++;
    int temp = nums[j];
    nums[j] = nums[end];
    nums[end] = temp;
    temp = sourceIdx[j];
    sourceIdx[j] = sourceIdx[end];
    sourceIdx[end] = temp;

    if (j > start) {
        quickSort(nums, sourceIdx, start, j - 1);
    }
    if (j < end) {
        quickSort(nums, sourceIdx, j + 1, end);
    }
}