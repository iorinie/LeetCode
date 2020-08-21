#include "MinDepth.h"
#include <algorithm>

using namespace std;

/*
    题目描述：
        给定一个二叉树，找出其最小深度。
        最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

    说明：
        叶子节点是指没有子节点的节点

    示例：
        给定二叉树 [3,9,20,null,null,15,7],
        
           3
          / \
         9  20
            / \
           15  7

        返回它的最小深度  2.
*/
/*
    解法2：递归，解法1的代码精简版
    缺点：
    知识点：
        1. 如果if里面只有一句，可以不用花括号包起来
        2. 0可以代替bool运算
        3. min函数在<algorithm>中
*/
int minDepth(TreeNode* root) {
    if (!root)
        return 0;

    int leftDep = minDepth(root->left);
    int rightDep = minDepth(root->right);

    return (leftDep && rightDep) ? 1 + min(leftDep, rightDep) : 1 + leftDep + rightDep;
}

/*
    解法1：递归
    缺点：逻辑太零散，可以稍微整合一下
    知识点：
        1. 使用NULL前需要引用比如<iostream>
        2. 没有子节点的节点才是叶子结点！！！！
*/
//int minDepth(TreeNode* root) {
//    if (!root) {
//        return 0;
//    }
//    if (!root->left && !root->right) {
//        return 1;
//    }
//
//    int min = 0;
//    if (!root->left) {
//        min = minDepth(root->right);
//    }
//    else if (!root->right) {
//        min = minDepth(root->left);
//    }
//    else {
//        int leftDep = minDepth(root->left);
//        int rightDep = minDepth(root->right);
//        min = leftDep > rightDep ? rightDep : leftDep;
//    }
//
//    return min + 1;
//}