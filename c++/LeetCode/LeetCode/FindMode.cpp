#include "FindMode.h"

/*
    ��Ŀ������
        ����һ������ֵͬ�Ķ�����������BST�����ҳ� BST �е���������������Ƶ����ߵ�Ԫ�أ���

        �ٶ� BST �����¶��壺
            1. �������������������ֵС�ڵ��ڵ�ǰ����ֵ
            2. �������������������ֵ���ڵ��ڵ�ǰ����ֵ
            3. �����������������Ƕ���������

    ���磬����
        ���� BST [1,null,2,2],
                1
                 \
                  2
                 /
                2

    ����[2].

    ��ʾ�������������1�������迼�����˳��

    ���ף�����Բ�ʹ�ö���Ŀռ��𣿣������ɵݹ��������ʽ����ջ�Ŀ��������������ڣ�
*/
/*
    �ⷨ1�����׽ⷨ���������BST��������ķǵݼ�����
    ȱ�㣺
    ֪ʶ�㣺
        1. BST��������ķǵݼ�����
*/
vector<int> rslt;

int base, sameCnt, maxCnt;

vector<int> findMode(TreeNode* root) {
    dfs(root);

    return rslt;
}

void dfs(TreeNode* node) {
    if (!node) return;

    dfs(node->left);
    update(node->val);
    dfs(node->right);
}

void update(int val) {
    if (val == base) {
        sameCnt++;
    }
    else {
        base = val;
        sameCnt = 1;
    }

    if (sameCnt == maxCnt) {
        rslt.push_back(val);
    }
    else if (sameCnt > maxCnt) {
        maxCnt = sameCnt;
        rslt.clear();
        rslt.push_back(val);
    }
}