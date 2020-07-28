#include "MaxDepth.h"

/*
    题目描述：
        给定一个二叉树，找出其最大深度。
        二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

    说明：
        叶子节点是指没有子节点的节点。
    
    示例：
        给定二叉树 [3,9,20,null,null,15,7]，
            3
           / \
          9  20
            /  \
           15   7
        返回它的最大深度 3 。
*/

/*
    解法1：
    缺点：很多if判断可以精简掉，用比较统一的方式返回

    知识点：
        1. 指针类型的属性，需要使用->left而不是.left
*/
int maxDepth(TreeNode* root) {
    int rslt = 0;

    if (!root) {
        return rslt;
    }

    rslt++;
    int tempLeft = 0;
    int tempRight = 0;
    if (root->left) {
        tempLeft = maxDepth(root->left);
    }
    if (root->right) {
        tempRight = maxDepth(root->right);
    }
    int bigger = tempLeft > tempRight ? tempLeft : tempRight;

    return rslt + bigger;
}