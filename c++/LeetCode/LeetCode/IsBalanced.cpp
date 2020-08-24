#include "IsBalanced.h"
#include <algorithm>

using namespace std;

/*
    题目描述：
        给定一个二叉树，判断它是否是高度平衡的二叉树。
        本题中，一棵高度平衡二叉树定义为：
            一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

    示例1：
        输入：[3,9,20,null,null,15,7]
                   3
                  / \
                 9  20
                    / \
                   15  7

        输出：true

    示例2：
        输入：[1,2,2,3,3,null,null,4,4]
                   1
                  / \
                 2   2
                / \
               3   3
              / \
             4   4

        输出：false

    示例3：
        输入：[1,2,2,3,null,null,3,4,null,null,4]
                   1
                  / \
                 2   2
                /     \
               3       3
              /         \
             4           4

        输出：false
*/
/*
    解法1：深度优先遍历，递归地判断左右子树是否为高度平衡的二叉树，返回是否高度平衡及高度信息
    缺点：
    知识点：
        1. 函数返回值多个时，使用结构体返回，或将多个需要返回的变量以引用方式传参进去
*/
bool isBalanced(TreeNode* root) {
    return isBST(root).isB;
}

MultpRtn isBST(TreeNode* node) {
    if (!node) { //空节点，平衡
        return MultpRtn{ true, 0 };
    }

    MultpRtn leftRtn = isBST(node->left);
    MultpRtn rightRtn = isBST(node->right);
    if (!leftRtn.isB || !rightRtn.isB) {
        return MultpRtn{ false, 0 };
    }
    if (abs(leftRtn.depth - rightRtn.depth) > 1) {
        return MultpRtn{ false, 0 };
    }

    return MultpRtn{ true, max(leftRtn.depth, rightRtn.depth) + 1 };
}