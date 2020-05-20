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
    �ⷨ1����̬�滮��dp[i]��ʾ��nums[i]��β�����ͣ�������͵ĸ��Ҫ��ϴ���ϸƷ������dp�����е����ֵ��Ϊ��⡣
    �ѵ㣺һ��ʼֻ���ǵ�nums[i - 1]�����������dpת�Ʒ�ʽ�ǳ����ӣ���ȫû�뵽ֱ���ж�dp[i - 1]�����������ˡ�
    ֪ʶ�㣺
        1. ����forѭ����ѭ��������һ���ģ����Ծ���Ϊһ��for������MaxProfit.cpp�еĴ�����
        2. ע�⣡����������δ�����vector�±꣬Խ�籨����������
*/
int maxSubArray(vector<int>& nums) {
    vector<int> dp;
    dp.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
        if (dp[i - 1] <= 0) {
            dp.push_back(nums[i]);
        }
        else {
            dp.push_back(dp[i - 1] + nums[i]);
        }
    }

    int max = dp[0];
    for (int i = 1; i < dp.size(); i++) {
        max = max >= dp[i] ? max : dp[i];
    }

    return max;
}