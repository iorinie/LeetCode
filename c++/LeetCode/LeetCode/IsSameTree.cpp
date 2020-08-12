#include "IsSameTree.h"

/*
    题目描述：
        给定两个二叉树，编写一个函数来检验它们是否相同。
        如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

    示例1：
        输入:
              1         1
             / \       / \
            2   3     2   3

            [1,2,3],   [1,2,3]

        输出: true

    示例2：
        输入:
              1         1
             /           \
            2             2

            [1,2],     [1,null,2]

        输出: false

    示例3：
        输入:
              1         1
             / \       / \
            2   1     1   2

            [1,2,1],   [1,1,2]

        输出: false
*/

/*
    解法1：二分递归
    难点：
    知识点：
        1.
*/
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
        return true;
    }
    if (!p || !q) {
        return false;
    }
    if (p->val != q->val) {
        return false;
    }
    bool isLeftSame = isSameTree(p->left, q->left);
    bool isRightSame = isSameTree(p->right, q->right);
    return isLeftSame && isRightSame;
}