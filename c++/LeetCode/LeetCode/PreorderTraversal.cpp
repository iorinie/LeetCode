#include "PreorderTraversal.h"
#include <stack>

/*
    题目描述：
        给定一个二叉树，返回它的 前序 遍历。

    示例：
        输入：[1,null,2,3]
            1
             \
             2
            /
           3
        输出：[1,2,3]

    进阶：
        递归算法很简单，你可以通过迭代算法完成吗？
*/

/*
    解法1：都提示了递归了，那就用迭代吧
    缺点：

    知识点：
        1. 使用栈的时候，当前节点的左右节点入栈顺序与题目需要的遍历顺序相反。
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