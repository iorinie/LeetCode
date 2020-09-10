#include "IsSubStructure.h"
#include <queue>

using namespace std;

/*
    ��Ŀ������
        �������ö�����A��B���ж�B�ǲ���A���ӽṹ��(Լ��������������һ�������ӽṹ)
        B��A���ӽṹ�� �� A���г��ֺ�B��ͬ�Ľṹ�ͽڵ�ֵ��

        ����:
            �������� A:
                 3
                / \
               4   5
              / \
             1   2

            �������� B:
               4
              /
             1
        ���� true����Ϊ B �� A ��һ������ӵ����ͬ�Ľṹ�ͽڵ�ֵ��

    ʾ��1��
        ���룺A = [1,2,3], B = [3,1]
        �����false

    ʾ��2��
        ���룺A = [3,4,5,1,2], B = [4,1]
        �����true
*/
/*
    �ⷨ2����ʹ�ö��а��ղ��������A�������Ż��Զ��庯���߼�
    ȱ�㣺
    ֪ʶ�㣺
        1. 
*/
bool isSubStructure(TreeNode* A, TreeNode* B) {
    if (!A || !B)
        return false;

    return isSame(A, B) && isSubStructure(A->left, B) && isSubStructure(A->right, B); //����ݹ������̫����
}

bool isSame(TreeNode* A, TreeNode* B) {
    if (!B)
        return true;
    if (!A)
        return false;
    return A->val == B->val && isSame(A->left, B->left) && isSame(A->right, B->right);
}

/*
    �ⷨ1��ʹ�ö��а��ղ��������A��ÿ���ڵ�����B���Ƚ�
    ȱ�㣺�ռ临�Ӷȹ��ߣ�ʱ�临�Ӷ����Ż��ռ䣬��ע�Ͳ���
    ֪ʶ�㣺
        1. 
*/
//bool isSubStructure(TreeNode* A, TreeNode* B) {
//    if (!A || !B) {
//        return false;
//    }
//    // int curHeight = 0; //�����ڵ�ĸ߶�
//    // int maxHeight = calMaxHeight(); //������������߶�
//    queue<TreeNode*> q;
//    q.push(A);
//    while (!q.empty()) {
//        // curHeight++;
//        // if (curHeight > maxHeight) {
//        //     break;
//        // }
//        int tempQLen = q.size();
//        for (int i = 0; i < tempQLen; i++) {
//            TreeNode* tempNode = q.front();
//            if (isSame(tempNode, B)) {
//                return true;
//            }
//            q.pop();
//            if (tempNode->left)
//                q.push(tempNode->left);
//            if (tempNode->right)
//                q.push(tempNode->right);
//        }
//    }
//    return false;
//}
//
//bool isSame(TreeNode* A, TreeNode* B) {
//    if (!A && !B)
//        return true;
//    if (!A)
//        return false;
//    if (!B)
//        return true;
//    if (A->val != B->val)
//        return false;
//
//    return isSame(A->left, B->left) && isSame(A->right, B->right);
//}