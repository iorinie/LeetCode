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
    �ⷨ2���������⣬��̬�滮
    ȱ�㣺
    ֪ʶ�㣺
        1.
*/
bool canPartition(vector<int>& nums) {
    return true;
}

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