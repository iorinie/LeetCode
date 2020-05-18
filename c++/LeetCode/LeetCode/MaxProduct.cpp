#include "MaxProduct.h"

/*
    ��Ŀ������
        ����һ���������� nums �������ҳ������г˻��������������飨�������������ٰ���һ�����֣��������ظ�����������Ӧ�ĳ˻���

    ʾ����
        ����: [2,3,-2,4]
        ���: 6
        ����: ������ [2,3] �����˻� 6��

        ����: [-2,0,-1]
        ���: 0
        ����: �������Ϊ 2, ��Ϊ [-2,-1] ���������顣

        ����: [-2,3,-4]
        ���: 24
*/

/*
    �ⷨ1����̬�滮��dp[i]��ʾ��nums[i]��β�����˻�
    �ѵ㣺
    ֪ʶ�㣺
        1. 
*/
int maxProduct(vector<int>& nums) {
    vector<int> dp;
    vector<int> dp_;
    dp.push_back(nums[0]);
    dp_.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
        if (dp_[i - 1] * nums[i] < 0) {
            dp.push_back(nums[i]);
        }
        else {
            dp.push_back(dp_[i - 1] * nums[i]);
        }
        if (dp_[i - 1] * nums[i] != 0) {
            dp_.push_back(dp_[i - 1] * nums[i]);
        }
        else {
            dp_.push_back(nums[i]);
        }
    }

    int max = dp[0];
    for (int i = 1; i < dp.size(); i++) {
        max = max >= dp[i] ? max : dp[i];
    }

    return max;
}