#include "InorderTraversal.h"
#include <stack>

/*
    题目描述：
        给定一个二叉树，返回它的中序 遍历。

    示例：
        输入：[1,null,2,3]
            1
             \
             2
            /  
           3   
        输出：[1,3,2]

    进阶：
        递归算法很简单，你可以通过迭代算法完成吗？
*/
/*
    解法2：迭代，使用栈模拟递归过程
    缺点：

    知识点：
        1. 
*/
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> rslt;

    TreeNode* p = root;
    stack<TreeNode*> s;
    while (p) {
        s.push(p);
        p = p->left;
    }
    while (!s.empty()) {
        TreeNode* n = s.top();
        s.pop();
        rslt.push_back(n->val);
        p = n->right;
        while (p) {
            s.push(p);
            p = p->left;
        }
    }

    return rslt;
}

/*
    解法1：都提示了递归了，不用感觉对不起出题者
    缺点：

    知识点：
        1. 网上刷题临时变量不要用static，因为会导致重复调用一直叠加
*/
//vector<int> inorderTraversal(TreeNode* root) {
//    //static vector<int> rslt;
//    vector<int> rslt;
//    if (!root) {
//        return rslt;
//    }
//    traversal(root, rslt);
//
//    return rslt;
//}
//
//void traversal(TreeNode* node, vector<int>& rslt) {
//    if (!node) {
//        return;
//    }
//    if (node->left) {
//        traversal(node->left, rslt);
//        //rslt.push_back(node->left->val);
//    }
//    rslt.push_back(node->val);
//    if (node->right) {
//        traversal(node->right, rslt);
//        //rslt.push_back(node->right->val);
//    }
//}