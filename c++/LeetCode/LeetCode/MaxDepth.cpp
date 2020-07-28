#include "MaxDepth.h"

/*
    ��Ŀ������
        ����һ�����������ҳ��������ȡ�
        �����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����

    ˵����
        Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
    
    ʾ����
        ���������� [3,9,20,null,null,15,7]��
            3
           / \
          9  20
            /  \
           15   7
        �������������� 3 ��
*/

/*
    �ⷨ1��
    ȱ�㣺�ܶ�if�жϿ��Ծ�������ñȽ�ͳһ�ķ�ʽ����

    ֪ʶ�㣺
        1. ָ�����͵����ԣ���Ҫʹ��->left������.left
*/
int maxDepth(TreeNode* root) {
    int rslt = 0;

    if (!root) {
        return rslt;
    }

    rslt++;
    int tempLeft = 0;
    int tempRight = 0;
    if (root->left) {
        tempLeft = maxDepth(root->left);
    }
    if (root->right) {
        tempRight = maxDepth(root->right);
    }
    int bigger = tempLeft > tempRight ? tempLeft : tempRight;

    return rslt + bigger;
}