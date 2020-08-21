#include "MinDepth.h"
#include <algorithm>

using namespace std;

/*
    ��Ŀ������
        ����һ�����������ҳ�����С��ȡ�
        ��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������

    ˵����
        Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ�

    ʾ����
        ���������� [3,9,20,null,null,15,7],
        
           3
          / \
         9  20
            / \
           15  7

        ����������С���  2.
*/
/*
    �ⷨ2���ݹ飬�ⷨ1�Ĵ��뾫���
    ȱ�㣺
    ֪ʶ�㣺
        1. ���if����ֻ��һ�䣬���Բ��û����Ű�����
        2. 0���Դ���bool����
        3. min������<algorithm>��
*/
int minDepth(TreeNode* root) {
    if (!root)
        return 0;

    int leftDep = minDepth(root->left);
    int rightDep = minDepth(root->right);

    return (leftDep && rightDep) ? 1 + min(leftDep, rightDep) : 1 + leftDep + rightDep;
}

/*
    �ⷨ1���ݹ�
    ȱ�㣺�߼�̫��ɢ��������΢����һ��
    ֪ʶ�㣺
        1. ʹ��NULLǰ��Ҫ���ñ���<iostream>
        2. û���ӽڵ�Ľڵ����Ҷ�ӽ�㣡������
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