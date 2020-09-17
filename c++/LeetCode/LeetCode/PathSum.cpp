#include "PathSum.h"

/*
    题目描述：
        输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。

    示例：
        给定如下二叉树，以及目标和 sum = 22，
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

        返回：
            [
               [5,4,11,2],
               [5,8,4,5]
            ]

    提示：节点总数 <= 10000
*/
/*
    解法1：回溯
    缺点：
    知识点：
        1. 注意自定义函数的返回条件
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

    if (!(node->left) && !(node->right)) { //当前节点为叶子节点，则比较结果
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