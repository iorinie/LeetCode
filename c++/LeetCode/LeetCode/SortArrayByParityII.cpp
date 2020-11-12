#include "SortArrayByParityII.h"

/*
    题目描述：
        给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。
        对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。
        你可以返回任何满足上述条件的数组作为答案。

    示例1：
        输入：[4,2,5,7]
        输出：[4,5,2,7]
        解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。

    提示：
        1. 2 <= A.length <= 20000
        2. A.length % 2 == 0
        3. 0 <= A[i] <= 1000
*/
/*
    解法1：头尾双指针
    缺点：
    知识点：
        1. 通过异或操作交换两数的原理
*/
vector<int> sortArrayByParityII(vector<int>& A) {
    int left = 0, right = A.size() - 1;
    while (1) {
        while (left < A.size() && (A[left] & 1) == 0) left += 2;
        if (left >= A.size()) break;
        while (A[right] & 1) right -= 2;
        A[left] ^= A[right];
        A[right] ^= A[left];
        A[left] ^= A[right];
        left += 2;
        right -= 2;
    }
    return A;
}