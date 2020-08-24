#include "IsBalanced.h"

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
    解法1：深度优先遍历，每层记录自己的高度，上层判断是否高度平衡，递归返回
    缺点：
    知识点：
        1.
*/
bool isBalanced(TreeNode* root) {
    return recordDepth(root);
}

bool recordDepth(TreeNode* node) {
    if (!node) {
        return true;
    }

    recordDepth(node->left);
    recordDepth(node->right);

    return true;
}