#include "BinaryTreePaths.h"

/*
    题目描述：
        给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。

    示例：
        输入：
            1
           / \
          2   3
           \
            5

        输出：["1->2->5", "1->3"]

        解释：所有根节点到叶子节点的路径为: 1->2->5, 1->3
*/
/*
    解法1：深度优先搜索，遇到叶子结点记录结果
    缺点：时间复杂度有点高，和调用string.substr()有关系，可以通过更改逻辑方式避免这个调用
    知识点：
        1. 注意题干特别提示了叶子结点的定义，需要特别注意递归的终止条件
        2. +=的操作，表达式右边仍然可以出现+
*/
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> rslt;
    if (!root) {
        return rslt;
    }

    string path;
    dfs(rslt, path, root);

    return rslt;
}

void dfs(vector<string>& rslt, string path, TreeNode* node) {
    path += "->" + to_string(node->val);
    if (!(node->left) && !(node->right)) {
        rslt.push_back(path.substr(2));
        return;
    }
    if (node->left)
        dfs(rslt, path, node->left);
    if (node->right)
        dfs(rslt, path, node->right);
}