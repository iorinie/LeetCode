#include "GenerateTrees.h"

/*
    题目描述：
        给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。

    示例：
        输入：3
    输出：
    [
      [1,null,3,2],
      [3,2,null,1],
      [3,1,null,null,2],
      [2,1,3],
      [1,null,2,null,3]
    ]

    解释：
    以上的输出对应以下 5 种不同结构的二叉搜索树：

       1         3     3      2      1
        \       /     /      / \      \
         3     2     1      1   3      2
        /     /       \                 \
       2     1         2                 3

    提示：
        0 <= n <= 8
*/
/*
    解法1：回溯，全排列的结果生成二叉搜索树
    缺点：
    知识点：
        1.
*/
vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> rslt;

    vector<int> source;
    for (int i = 1; i <= n; i++) {
        source.push_back(i);
    }
    vector<int> path;
    selectBinarySearchTreeNode(rslt, source, path);

    return rslt;
}

void selectBinarySearchTreeNode(vector<TreeNode*>& rslt, vector<int>& source, vector<int>& path) {
    if (path.size() == source.size()) {
        TreeNode* tempRoot = buildBinarySearchTree(path);
        rslt.push_back(tempRoot);
    }

    for (int i = 0; i < source.size(); i++) {
        path.push_back(source[i]);
        selectBinarySearchTreeNode(rslt, source, path);
        path.pop_back();
    }
}

TreeNode* buildBinarySearchTree(vector<int>& path) {
    TreeNode* root = new TreeNode(path[0]);

    for (int i = 1; i < path.size(); i++) {
        TreeNode* tempNode = new TreeNode(path[i]);
        TreeNode* p = root;
        while (p) {
            if (p->val > i) {
                if (p->left) {
                    p = p->left;
                }
                else {
                    p->left = tempNode;
                    break;
                } 
            }
            else {
                if (p->right) {
                    p = p->right;
                }
                else {
                    p->right = tempNode;
                }
            }
        }
    }

    return root;
}