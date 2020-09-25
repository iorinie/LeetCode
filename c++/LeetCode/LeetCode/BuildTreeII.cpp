#include "BuildTreeII.h"
#include <map>

/*
    题目描述：
        根据一棵树的中序遍历与后序遍历构造二叉树。

    注意：你可以假设树中没有重复的元素。

    例如，给出
        中序遍历 inorder = [9,3,15,20,7]
        后序遍历 postorder = [9,15,7,20,3]

    返回如下的二叉树：
                3
               / \
              9  20
                /  \
               15   7
*/
/*
    解法1：
    缺点：
    知识点：
        1. 
*/
map<int, int> m;

TreeNode* buildTreeII(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.size() == 0) return NULL;

    for (int i = 0; i < inorder.size(); i++) {
        m[inorder[i]] = i;
    }

    return buildII(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}

TreeNode* buildII(vector<int>& inorder, int iStartIdx, int iEndIdx, vector<int>& postorder, int pStartIdx, int pEndIdx) {
    if (pStartIdx > pEndIdx) return NULL;

    TreeNode* root = new TreeNode(postorder[pEndIdx]);

    int rootInInorder = m[postorder[pEndIdx]];
    root->left = buildII(inorder, iStartIdx, rootInInorder - 1, postorder, pStartIdx, pStartIdx + rootInInorder - iStartIdx - 1);
    root->right = buildII(inorder, rootInInorder + 1, iEndIdx, postorder, pStartIdx + rootInInorder - iStartIdx, pEndIdx - 1);

    return root;
}