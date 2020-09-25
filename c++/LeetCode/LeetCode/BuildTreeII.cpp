#include "BuildTreeII.h"
#include <map>

/*
    ��Ŀ������
        ����һ��������������������������������

    ע�⣺����Լ�������û���ظ���Ԫ�ء�

    ���磬����
        ������� inorder = [9,3,15,20,7]
        ������� postorder = [9,15,7,20,3]

    �������µĶ�������
                3
               / \
              9  20
                /  \
               15   7
*/
/*
    �ⷨ1��
    ȱ�㣺
    ֪ʶ�㣺
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