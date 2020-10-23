#include "Postordertraversal.h"
#include <stack>

/*
    ��Ŀ������
        ����һ������������������ ���� ������

    ʾ����
        ���룺[1,null,2,3]
            1
             \
             2
            /
           3
        �����[3,2,1]

    ���ף�
        �ݹ��㷨�ܼ򵥣������ͨ�������㷨�����
*/

/*
    �ⷨ1������ʾ�˵ݹ��ˣ��Ǿ��õ�����
    ȱ�㣺

    ֪ʶ�㣺
        1. ����˼·��ʱ���õݹ�Ŀ�ܣ�����ջģ�����ջ���̣�����˼��
*/
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> rslt;
    if (!root) return rslt;

    stack<TreeNode*> s;
    s.push(root);
    TreeNode* cur = root;
    while (cur->left) {
        s.push(cur->left);
        cur = cur->left;
    }
    while (!s.empty()) {
        cur = s.top();
        if (cur->right) {
            s.push(cur->right);
            TreeNode* temp = cur->right;
            cur->right = nullptr;
            cur = temp;
            while (cur->left) {
                s.push(cur->left);
                cur = cur->left;
            }
        }
        else {
            rslt.push_back(s.top()->val);
            s.pop();
        }
    }

    return rslt;
}