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
    解法1：使用队列的广度优先搜索
    缺点：其实不需要维护pushCount，本质上它就是队列的长度，第二层while使用for就行了，只要能保证每次内层循环能够把同层的所有节点从队列中取出就行

    知识点：
        1. 有返回值的函数，如果直接不携带数据return，调用方是不会初始化返回的
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