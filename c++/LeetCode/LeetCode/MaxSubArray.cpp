#include "MaxSubArray.h"

/*
    ��Ŀ������
        ����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�

    ʾ����
        ����: [-2,1,-3,4,-1,2,1,-5,4],
        ���: 6
        ����: ���������� [4,-1,2,1] �ĺ����Ϊ 6��

    ���ף�
        ������Ѿ�ʵ�ָ��Ӷ�Ϊ O(n) �Ľⷨ������ʹ�ø�Ϊ����ķ��η���⡣
*/

/*
    �ⷨ1����̬�滮��max = {��ǰiֵ��ǰ��i-1��maxֵ������maxֵ�𵽵�ǰֵǰ�ۼӵ���ֵ+��ǰiֵ}
    �ѵ㣺
    ֪ʶ�㣺
        1. 
        2. 
*/
int maxSubArray(vector<int>& nums) {
    int max = nums[0];
    if (nums.size() == 1) {
        return max;
    }
    int tempPositive = 0; //����maxֵ�𵽵�ǰֵǰ�ۼӵ���ֵ
    for (int i = 1; i < nums.size(); i++) {
        max = maxOfThree(nums[i], max, tempPositive + nums[i]);
    }

    return max;
}

int maxOfThree(int a, int b, int c) {

}