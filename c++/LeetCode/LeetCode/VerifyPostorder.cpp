#include "VerifyPostorder.h"

/*
    ��Ŀ������
        ����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�����������������򷵻� true�����򷵻� false���������������������������ֶ�������ͬ��

        �ο�������Ŷ�����������
                     5
                    / \
                   2   6
                  / \
                 1   3

    ʾ��1��
        ���룺[1,6,3,2,5]
        �����false

    ʾ��2��
        ���룺[1,3,2,6,5]
        �����true

    ��ʾ�����鳤�� <= 1000
*/
/*
    �ⷨ1���ҹ��ɣ�������ı�ע
    ȱ�㣺�ռ临�Ӷȹ���
    ֪ʶ�㣺
        1. ��isSubsquenceBTS�е����ڶ��������ɵ������������ܴ�Ŀռ����� -> �ݹ�ṹ�У�����Խ��Խ���ӣ�����ջ��ɵĿռ����ķǳ��ǳ���
*/
bool verifyPostorder(vector<int>& postorder) {
    int pLen = postorder.size();
    if (pLen == 0) {
        return true;
    }

    //��������һ����һ�������ĸ��ڵ�
    //ʣ�µ����У��϶����ո��ڵ��ֵ��Ϊ�����֣�ǰ���Ƕ��ȸ��ڵ�С�����������Ǵ����
    //���������ֵ����һ����һ���������ĸ��ڵ�
    return isSubsquenceBTS(postorder, 0, pLen - 2, pLen - 1);
}

bool isSubsquenceBTS(vector<int>& postorder, int startIdx, int endIdx, int rootIdx) {
    if (startIdx > endIdx) {
        return true;
    }

    int leftRootIdx = -2; //��С�Ҵ���±꣬���������ĸ����±�
    for (int i = startIdx; i <= endIdx; i++) {
        if (postorder[i] < postorder[rootIdx] && leftRootIdx != -2) {
            return false; //�Ѿ�ȷ�������������±������£��ұ߻��бȸ��ڵ�����������BTS
        }
        if (postorder[i] > postorder[rootIdx] && leftRootIdx == -2) { //��һ���ҵ��ȸ��ڵ�����
            leftRootIdx = i - 1;
        }
    }
    if (leftRootIdx == -2) {
        leftRootIdx = endIdx;
    }

    return isSubsquenceBTS(postorder, startIdx, leftRootIdx - 1, leftRootIdx) && isSubsquenceBTS(postorder, leftRootIdx + 1, rootIdx - 2, rootIdx - 1);
}