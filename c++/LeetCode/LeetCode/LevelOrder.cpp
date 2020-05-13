#include "LevelOrder.h"
#include <queue>

/*
    题目描述：
        给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

    示例：
        二叉树：[3,9,20,null,null,15,7],
            3
           / \
          9  20
            /  \
           15   7
        返回其层次遍历结果：
        [
            [3],
            [9,20],
            [15,7]
        ]
*/

/*
    解法1：广度优先搜索
    缺点：

    知识点：
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
    TreeNode* tn; //记录每次pop出来的节点
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