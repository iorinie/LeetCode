#include "PreorderTraversal.h"
#include <stack>

/*
    ��Ŀ������
        ����һ������������������ ǰ�� ������

    ʾ����
        ���룺[1,null,2,3]
            1
             \
             2
            /
           3
        �����[1,2,3]

    ���ף�
        �ݹ��㷨�ܼ򵥣������ͨ�������㷨�����
*/

/*
    �ⷨ1������ʾ�˵ݹ��ˣ��Ǿ��õ�����
    ȱ�㣺

    ֪ʶ�㣺
        1. ʹ��ջ��ʱ�򣬵�ǰ�ڵ�����ҽڵ���ջ˳������Ŀ��Ҫ�ı���˳���෴��
*/
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> rslt;
    if (!root) {
        return rslt;
    }
    stack<TreeNode*> tns;
    tns.push(root);
    while (!tns.empty()) {
        TreeNode* cn = tns.top();
        tns.pop();
        rslt.push_back(cn->val);
        if (cn->right) {
            tns.push(cn->right);
        }
        if (cn->left) {
            tns.push(cn->left);
        }
    }

    return rslt;
}