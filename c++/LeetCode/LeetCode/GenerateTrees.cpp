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
    解法2：分治？
    缺点：
    知识点：
        1. 已经确定了数组范围，结合二叉搜索树的性质，没有必要使用回溯的方式全排
        2. vector类型的返回，如果没有元素，可以直接写成返回{}
        3. 直接向vector中推入nullptr，也可以在for循环中走一次遍历
*/
vector<TreeNode*> generateTrees(int n) {
    if (n <= 0) {
        return {};
    }
    return buildBinarySearchTree(1, n);
}

vector<TreeNode*> buildBinarySearchTree(int start, int end) {
    vector<TreeNode*> rslt;
    if (start > end) {
        rslt.push_back(nullptr);
        return rslt;
    }

    for (int i = start; i <= end; i++) {
        vector<TreeNode*> leftNodes = buildBinarySearchTree(start, i - 1);
        vector<TreeNode*> rightNodes = buildBinarySearchTree(i + 1, end);
        for (int j = 0; j < leftNodes.size(); j++) {
            for (int k = 0; k < rightNodes.size(); k++) {
                TreeNode* tempRoot = new TreeNode(i);
                tempRoot->left = leftNodes[j];
                tempRoot->right = rightNodes[k];
                rslt.push_back(tempRoot);
            }
        }
    }

    return rslt;
}

/*
    解法1：回溯，全排列的结果生成二叉搜索树
    缺点：有些排列虽然不一样，但是生成的二叉搜索树是一样的，怎么去重？ -> 没有办法去重
    知识点：
        1.
*/
//vector<TreeNode*> generateTrees(int n) {
//    vector<TreeNode*> rslt;
//
//    vector<int> source(n, 0);
//    for (int i = 1; i <= n; i++) {
//        source[i - 1] = i;
//    }
//    vector<int> path;
//    vector<bool> visited(n, false);
//    selectBinarySearchTreeNode(rslt, source, path, visited);
//
//    return rslt;
//}
//
//void selectBinarySearchTreeNode(vector<TreeNode*>& rslt, vector<int>& source, vector<int>& path, vector<bool> visited) {
//    if (path.size() == source.size()) {
//        TreeNode* tempRoot = buildBinarySearchTree(path);
//        rslt.push_back(tempRoot);
//    }
//
//    for (int i = 0; i < source.size(); i++) {
//        if (visited[i]) {
//            continue;
//        }
//        path.push_back(source[i]);
//        visited[i] = true;
//        selectBinarySearchTreeNode(rslt, source, path, visited);
//        visited[i] = false;
//        path.pop_back();
//    }
//}
//
//TreeNode* buildBinarySearchTree(vector<int>& path) {
//    TreeNode* root = new TreeNode(path[0]);
//
//    for (int i = 1; i < path.size(); i++) {
//        TreeNode* tempNode = new TreeNode(path[i]);
//        TreeNode* p = root;
//        while (p) {
//            if (path[i] < p->val) {
//                if (p->left) {
//                    p = p->left;
//                }
//                else {
//                    p->left = tempNode;
//                    break;
//                }
//            }
//            else if (path[i] > p->val) {
//                if (p->right) {
//                    p = p->right;
//                }
//                else {
//                    p->right = tempNode;
//                    break;
//                }
//            }
//        }
//    }
//
//    return root;
//}