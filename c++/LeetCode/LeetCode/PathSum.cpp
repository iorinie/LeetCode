#include "PathSum.h"

/*
    ��Ŀ������
        ����һ�ö�������һ����������ӡ���������нڵ�ֵ�ĺ�Ϊ��������������·���������ĸ��ڵ㿪ʼ����һֱ��Ҷ�ڵ��������Ľڵ��γ�һ��·����

    ʾ����
        �������¶��������Լ�Ŀ��� sum = 22��
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

        ���أ�
            [
               [5,4,11,2],
               [5,8,4,5]
            ]

    ��ʾ���ڵ����� <= 10000
*/
/*
    �ⷨ1������
    ȱ�㣺
    ֪ʶ�㣺
        1. ע���Զ��庯���ķ�������
*/
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> rslt;
    if (!root) {
        return rslt;
    }

    vector<int> path;
    dfs(rslt, path, root, 0, sum);

    return rslt;
}

void dfs(vector<vector<int>>& rslt, vector<int>& path, TreeNode* node, int tempSun, int targetSum) {
    path.push_back(node->val);
    tempSun += node->val;

    if (!(node->left) && !(node->right)) { //��ǰ�ڵ�ΪҶ�ӽڵ㣬��ȽϽ��
        if (tempSun == targetSum) {
            rslt.push_back(path);
        }
        path.pop_back();
        return;
    }

    if (node->left) dfs(rslt, path, node->left, tempSun, targetSum);
    if (node->right) dfs(rslt, path, node->right, tempSun, targetSum);
    path.pop_back();
}