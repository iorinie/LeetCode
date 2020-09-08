#include "BuildTree.h"

/*
    题目描述：
        输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

    例如，给出
        前序遍历 preorder = [3,9,20,15,7]
        中序遍历 inorder = [9,3,15,20,7]

    返回如下的二叉树：
                3
               / \
              9  20
                /  \
               15   7
*/
/*
    解法2：参数中只传需要的上下标，不做数组的截取操作
    缺点：
    知识点：
        1. 前序中顺序是根、左、右，所以只要原根节点+左子树节点数+1就能表示右子树的根节点位置。
            rootIdx（原根节点）+（tempRootInInIdx - startInIdx）（左子树长度）+1就是这么来的
*/
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return build(preorder, inorder, 0, 0, inorder.size() - 1);
}

TreeNode* build(vector<int>& preorder, vector<int>& inorder, int rootIdx, int startInIdx, int endInIdx) {
    if (startInIdx > endInIdx)
        return NULL;

    TreeNode* tempRoot = new TreeNode(preorder[rootIdx]);
    int tempRootInInIdx = startInIdx;
    while (tempRootInInIdx <= endInIdx && inorder[tempRootInInIdx] != preorder[rootIdx]) tempRootInInIdx++;
    tempRoot->left = build(preorder, inorder, rootIdx + 1, startInIdx, tempRootInInIdx - 1);
    tempRoot->right = build(preorder, inorder, rootIdx + tempRootInInIdx - startInIdx + 1, tempRootInInIdx + 1, endInIdx);

    return tempRoot;
}

/*
    解法1：二分输入的两个数组，递归
    缺点：时空复杂度都有点高
    知识点：
        1. 使用vector<int> v2(v1.begin(), v1.end())截取vector时，是左闭右开
*/
//TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//    if (preorder.size() == 0) {
//        return NULL;
//    }
//
//    TreeNode* root = new TreeNode(preorder[0]);
//
//    int tempRootIdx = 0;
//    for (int i = 0; i < inorder.size(); i++) {
//        if (inorder[i] == preorder[0]) {
//            tempRootIdx = i;
//            break;
//        }
//    }
//
//    vector<int> leftPre(preorder.begin() + 1, preorder.begin() + 1 + tempRootIdx);
//    vector<int> rightPre(preorder.begin() + tempRootIdx + 1, preorder.end());
//    vector<int> leftIn(inorder.begin(), inorder.begin() + tempRootIdx);
//    vector<int> rightIn(inorder.begin() + tempRootIdx + 1, inorder.end());
//
//    root->left = buildTree(leftPre, leftIn);
//    root->right = buildTree(rightPre, rightIn);
//
//    return root;
//}