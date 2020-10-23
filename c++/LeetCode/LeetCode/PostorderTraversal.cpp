#include "Postordertraversal.h"
#include <stack>

/*
    题目描述：
        给定一个二叉树，返回它的 后序 遍历。

    示例：
        输入：[1,null,2,3]
            1
             \
             2
            /
           3
        输出：[3,2,1]

    进阶：
        递归算法很简单，你可以通过迭代算法完成吗？
*/

/*
    解法1：都提示了递归了，那就用迭代吧
    缺点：

    知识点：
        1. 理不清思路的时候，用递归的框架，画个栈模拟出入栈过程，帮助思考
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