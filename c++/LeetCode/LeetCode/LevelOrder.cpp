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
    �ⷨ1��ʹ�ö��еĹ����������
    ȱ�㣺��ʵ����Ҫά��pushCount�������������Ƕ��еĳ��ȣ��ڶ���whileʹ��for�����ˣ�ֻҪ�ܱ�֤ÿ���ڲ�ѭ���ܹ���ͬ������нڵ�Ӷ�����ȡ������

    ֪ʶ�㣺
        1. �з���ֵ�ĺ��������ֱ�Ӳ�Я������return�����÷��ǲ����ʼ�����ص�
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
        while (pushCount > 0) {
            tn = q.front();
            q.pop();
            tempR.push_back(tn->val);
            if (tn->left) {
                q.push(tn->left);
            }
            if (tn->right) {
                q.push(tn->right);
            }
            pushCount--;
        }
        rslt.push_back(tempR);
        pushCount = q.size();
    }

    return rslt;
}