#include "CanPartition.h"
#include <algorithm>

/*
    ��Ŀ������
        ����һ��ֻ�����������ķǿ����顣�Ƿ���Խ��������ָ�������Ӽ���ʹ�������Ӽ���Ԫ�غ���ȡ�

    ע�⣺
        1. ÿ�������е�Ԫ�ز��ᳬ�� 100
        2. ����Ĵ�С���ᳬ�� 200

    ʾ��1��
        ���룺[1, 5, 11, 5]
        �����true
        ���ͣ�������Էָ�� [1, 5, 5] �� [11]

    ʾ��2��
        ���룺[1, 2, 3, 5]
        �����false
        ���ͣ����鲻�ָܷ������Ԫ�غ���ȵ��Ӽ�
*/
/*
    �ⷨ2��ת��Ϊ�������⣬��̬�滮
    ȱ�㣺ÿһ�е�״ֻ̬����һ���йأ����Բ��ö�ά���鱣��dp
    ֪ʶ�㣺
        1.
*/
bool canPartition(vector<int>& nums) {
    int nLen = nums.size();
    if (nLen <= 1) return false;

    int sum = 0;
    int maxSub = 0;
    for (int i = 0; i < nLen; i++) {
        sum += nums[i];
        if (nums[i] > maxSub) maxSub = nums[i];
    }
    if (sum & 1) return false;
    int target = sum / 2;
    if (maxSub > target) return false;

    vector<vector<bool>> dp(nLen, vector<bool>(target + 1, true));
    for (int j = 1; j <= target; j++) {
        dp[0][j] = nums[0] == j;
    }
    for (int i = 1; i < nLen; i++) {
        for (int j = 1; j <= target; j++) {
            if (nums[i] > j) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
            }
        }
    }

    return dp[nLen - 1][target];
}

/*
    �ⷨ3��ת��Ϊ�������⣬��̬�滮���ⷨ2�Ż���
    ȱ�㣺
    ֪ʶ�㣺
        1.
*/
//bool canPartition(vector<int>& nums) {
//    int nLen = nums.size();
//    if (nLen <= 1) return false;
//
//    int sum = 0;
//    int maxSub = 0;
//    for (int i = 0; i < nLen; i++) {
//        sum += nums[i];
//        if (nums[i] > maxSub) maxSub = nums[i];
//    }
//    if (sum & 1) return false;
//    int target = sum / 2;
//    if (maxSub > target) return false;
//
//    vector<bool> dp(target + 1, true);
//    for (int j = 1; j <= target; j++) {
//        dp[j] = nums[0] == j;
//    }
//    for (int i = 1; i < nLen; i++) {
//        for (int j = target; j > 0; j--) {
//            if (nums[i] <= j) {
//                dp[j] = dp[j] || dp[j - nums[i]];
//            }
//        }
//    }
//
//    return dp[target];
//}

/*
    �ⷨ1��ȫ���бȽ��ܺ͵�һ��
    ȱ�㣺��ʱ ��ʱ ��ʱ��
    ֪ʶ�㣺
        1.
*/
//bool canPartition(vector<int>& nums) {
//    if (nums.size() <= 1) return false;
//
//    int sum = 0;
//    for (int i = 0; i < nums.size(); i++) {
//        sum += nums[i];
//    }
//    if (sum & 0x1) return false;
//
//    sort(nums.begin(), nums.end());
//
//    return dfs(nums, 0, 0, sum / 2);
//}
//
//bool dfs(vector<int>& nums, int startIdx, int tempSum, int target) {
//    if (startIdx == nums.size()) return false;
//
//    if (tempSum == target) return true;
//
//    for (int i = startIdx; i < nums.size() - 1; i++) {
//        bool isPart = dfs(nums, i + 1, tempSum + nums[i], target);
//        if (isPart) return true;
//    }
//
//    return false;
//}