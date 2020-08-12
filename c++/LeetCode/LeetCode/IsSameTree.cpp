#include "IsSameTree.h"

/*
    ��Ŀ������
        ������������������дһ�����������������Ƿ���ͬ��
        ����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�

    ʾ��1��
        ����:
              1         1
             / \       / \
            2   3     2   3

            [1,2,3],   [1,2,3]

        ���: true

    ʾ��2��
        ����:
              1         1
             /           \
            2             2

            [1,2],     [1,null,2]

        ���: false

    ʾ��3��
        ����:
              1         1
             / \       / \
            2   1     1   2

            [1,2,1],   [1,1,2]

        ���: false
*/

/*
    �ⷨ1�����ֵݹ�
    �ѵ㣺
    ֪ʶ�㣺
        1.
*/
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
        return true;
    }
    if (!p || !q) {
        return false;
    }
    if (p->val != q->val) {
        return false;
    }
    bool isLeftSame = isSameTree(p->left, q->left);
    bool isRightSame = isSameTree(p->right, q->right);
    return isLeftSame && isRightSame;
}