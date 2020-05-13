#include "LevelOrder.h"
#include <queue>

/*
    ��Ŀ������
        ����һ�������������㷵���䰴 ������� �õ��Ľڵ�ֵ�� �������أ������ҷ������нڵ㣩��

    ʾ����
        ��������[3,9,20,null,null,15,7],
            3
           / \
          9  20
            /  \
           15   7
        �������α��������
        [
            [3],
            [9,20],
            [15,7]
        ]
*/

/*
    �ⷨ1�������������
    ȱ�㣺

    ֪ʶ�㣺
        1. 
        2. 
        3. 
*/
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> rslt;

    if (!root) {
        return rslt;
    }

    queue<TreeNode*> q;
    TreeNode* tn; //��¼ÿ��pop�����Ľڵ�
    int pushCount = 0;
    q.push(root);
    pushCount++;
    while (!q.empty()) {
        vector<int> tempR;
        TreeNode* l = NULL, * r = NULL;
        while (pushCount > 0) {
            tn = q.front();
            q.pop();
            tempR.push_back(tn->val);
            if (tn->left) {
                l = tn->left;
            }
            if (tn->right) {
                r = tn->right;
            }
            pushCount--;
        }
        rslt.push_back(tempR);
        if (l) {
            q.push(l);
            pushCount++;
        }
        if (r) {
            q.push(r);
            pushCount++;
        }
    }

    return rslt;
}