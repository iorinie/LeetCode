#include "IsSubStructure.h"
#include <queue>

using namespace std;

/*
    题目描述：
        输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
        B是A的子结构， 即 A中有出现和B相同的结构和节点值。

        例如:
            给定的树 A:
                 3
                / \
               4   5
              / \
             1   2

            给定的树 B:
               4
              /
             1
        返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。

    示例1：
        输入：A = [1,2,3], B = [3,1]
        输出：false

    示例2：
        输入：A = [3,4,5,1,2], B = [4,1]
        输出：true
*/
/*
    解法2：不使用队列按照层序遍历树A，并且优化自定义函数逻辑
    缺点：
    知识点：
        1. 
*/
bool isSubStructure(TreeNode* A, TreeNode* B) {
    if (!A || !B)
        return false;

    return isSame(A, B) && isSubStructure(A->left, B) && isSubStructure(A->right, B); //这个递归真的是太赞了
}

bool isSame(TreeNode* A, TreeNode* B) {
    if (!B)
        return true;
    if (!A)
        return false;
    return A->val == B->val && isSame(A->left, B->left) && isSame(A->right, B->right);
}

/*
    解法1：使用队列按照层序遍历树A，每个节点与树B作比较
    缺点：空间复杂度过高，时间复杂度有优化空间，见注释部分
    知识点：
        1. 
*/
//bool isSubStructure(TreeNode* A, TreeNode* B) {
//    if (!A || !B) {
//        return false;
//    }
//    // int curHeight = 0; //遍历节点的高度
//    // int maxHeight = calMaxHeight(); //允许遍历的最大高度
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