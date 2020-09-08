#include "BuildTree.h"

/*
    ��Ŀ������
        ����ĳ��������ǰ���������������Ľ�������ؽ��ö����������������ǰ���������������Ľ���ж������ظ������֡�

    ���磬����
        ǰ����� preorder = [3,9,20,15,7]
        ������� inorder = [9,3,15,20,7]

    �������µĶ�������
                3
               / \
              9  20
                /  \
               15   7
*/
/*
    �ⷨ2��������ֻ����Ҫ�����±꣬��������Ľ�ȡ����
    ȱ�㣺
    ֪ʶ�㣺
        1. ǰ����˳���Ǹ������ң�����ֻҪԭ���ڵ�+�������ڵ���+1���ܱ�ʾ�������ĸ��ڵ�λ�á�
            rootIdx��ԭ���ڵ㣩+��tempRootInInIdx - startInIdx�������������ȣ�+1������ô����
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
    �ⷨ1������������������飬�ݹ�
    ȱ�㣺ʱ�ո��Ӷȶ��е��
    ֪ʶ�㣺
        1. ʹ��vector<int> v2(v1.begin(), v1.end())��ȡvectorʱ��������ҿ�
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