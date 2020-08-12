#include "MaxProduct.h"
#include <iostream>

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
    �ⷨ1����̬�滮��dp�����¼���±�i��β���������������ĳ˻�
    �ѵ㣺��Բ�ͬ������õ��ۻ����������Լ��������ˣ������˼·���������������̡��Ѿ�������߼��������޸ġ�
    ֪ʶ�㣺
        1. 
*/
int maxProduct(vector<int>& nums) {
    int max = 0;
    
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    max = dp[0];

    int notZeroMul = nums[0] == 0 ? 1 : nums[0]; //�ӷ�0��ʼ����Ŀǰ�±�ĳ˻�
    int negtiveCnt = nums[0] < 0 ? 1 : 0; //ĿǰΪֹ�����ĸ���������0����
    int shouldOut = nums[0] == 0 ? 1 : nums[0]; //��һ��������֮ǰ�������������ĳ˻�

    for (int i = 1; i < nums.size(); i++) {
        if (notZeroMul * nums[i] > 0) { //�Լ�ǰ���0����ʼ��һֱ�˵��Լ������������������������Ϊ����˻�
            dp[i] = notZeroMul * nums[i];
        }
        else if (notZeroMul * nums[i] == 0) { //�Լ���0
            dp[i] = nums[i];
        }
        else { //�Լ�ǰ���0����ʼ��һֱ�˵��Լ����Ǹ��������ȥshouldOut��ǰ����0�������ʵ��bug��������Ҫ��ϸ�µ����֣�
            dp[i] = notZeroMul * nums[i] / shouldOut;
        }
        cout << dp[i] << endl;
        max = max >= dp[i] ? max : dp[i];

        if (nums[i] > 0) {
            notZeroMul *= nums[i];

            shouldOut = negtiveCnt >= 1 ? shouldOut : shouldOut * nums[i];
        }
        else if (nums[i] == 0) {
            notZeroMul = 1;
            negtiveCnt = 0;
            shouldOut = 1;
        }
        else {
            notZeroMul *= nums[i];
            negtiveCnt++;
            shouldOut = negtiveCnt > 1 ? shouldOut : shouldOut * nums[i];
        }
    }

    return max;
}