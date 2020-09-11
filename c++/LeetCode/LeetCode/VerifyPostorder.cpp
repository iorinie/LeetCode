#include "VerifyPostorder.h"

/*
    题目描述：
        输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。

        参考以下这颗二叉搜索树：
                     5
                    / \
                   2   6
                  / \
                 1   3

    示例1：
        输入：[1,6,3,2,5]
        输出：false

    示例2：
        输入：[1,3,2,6,5]
        输出：true

    提示：数组长度 <= 1000
*/
/*
    解法1：找规律，看代码的备注
    缺点：空间复杂度过高
    知识点：
        1. 将isSubsquenceBTS中倒数第二个参数干掉，可以提升很大的空间性能 -> 递归结构中，参数越多越复杂，调用栈造成的空间消耗非常非常大？
*/
bool verifyPostorder(vector<int>& postorder) {
    int pLen = postorder.size();
    if (pLen == 0) {
        return true;
    }

    //数组的最后一个数一定是树的根节点
    //剩下的数中，肯定按照根节点的值分为两部分，前面是都比根节点小的数，后面是大的数
    //并且两部分的最后一个数一定是子树的根节点
    return isSubsquenceBTS(postorder, 0, pLen - 2, pLen - 1);
}

bool isSubsquenceBTS(vector<int>& postorder, int startIdx, int endIdx, int rootIdx) {
    if (startIdx > endIdx) {
        return true;
    }

    int leftRootIdx = -2; //左小右大的下标，即左子树的根的下标
    for (int i = startIdx; i <= endIdx; i++) {
        if (postorder[i] < postorder[rootIdx] && leftRootIdx != -2) {
            return false; //已经确认了左子树根下标的情况下，右边还有比根节点大的数，则不是BTS
        }
        if (postorder[i] > postorder[rootIdx] && leftRootIdx == -2) { //第一次找到比根节点大的数
            leftRootIdx = i - 1;
        }
    }
    if (leftRootIdx == -2) {
        leftRootIdx = endIdx;
    }

    return isSubsquenceBTS(postorder, startIdx, leftRootIdx - 1, leftRootIdx) && isSubsquenceBTS(postorder, leftRootIdx + 1, rootIdx - 2, rootIdx - 1);
}