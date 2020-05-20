#include "InorderTraversal.h"

/*
    ��Ŀ������
        ����һ���������������������� ������

    ʾ����
        ���룺[1,null,2,3]
            1
             \
             2
            /  
           3   
        �����[1,3,2]

    ���ף�
        �ݹ��㷨�ܼ򵥣������ͨ�������㷨�����
*/

/*
    �ⷨ1������ʾ�˵ݹ��ˣ����øо��Բ��������
    ȱ�㣺

    ֪ʶ�㣺
        1. ����ˢ����ʱ������Ҫ��static����Ϊ�ᵼ���ظ�����һֱ����
*/
vector<int> inorderTraversal(TreeNode* root) {
    //static vector<int> rslt;
    vector<int> rslt;
    if (!root) {
        return rslt;
    }
    traversal(root, rslt);

    return rslt;
}

void traversal(TreeNode* node, vector<int>& rslt) {
    if (!node) {
        return;
    }
    if (node->left) {
        traversal(node->left, rslt);
        //rslt.push_back(node->left->val);
    }
    rslt.push_back(node->val);
    if (node->right) {
        traversal(node->right, rslt);
        //rslt.push_back(node->right->val);
    }
}