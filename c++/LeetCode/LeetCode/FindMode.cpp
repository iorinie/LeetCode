#include "FindMode.h"

/*
    题目描述：
        给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。

        假定 BST 有如下定义：
            1. 结点左子树中所含结点的值小于等于当前结点的值
            2. 结点右子树中所含结点的值大于等于当前结点的值
            3. 左子树和右子树都是二叉搜索树

    例如，给出
        给定 BST [1,null,2,2],
                1
                 \
                  2
                 /
                2

    返回[2].

    提示：如果众数超过1个，不需考虑输出顺序

    进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
*/
/*
    解法1：进阶解法，充分利用BST中序遍历的非递减特性
    缺点：
    知识点：
        1. BST中序遍历的非递减特性
*/
vector<int> rslt;

int base, sameCnt, maxCnt;

vector<int> findMode(TreeNode* root) {
    dfs(root);

    return rslt;
}

void dfs(TreeNode* node) {
    if (!node) return;

    dfs(node->left);
    update(node->val);
    dfs(node->right);
}

void update(int val) {
    if (val == base) {
        sameCnt++;
    }
    else {
        base = val;
        sameCnt = 1;
    }

    if (sameCnt == maxCnt) {
        rslt.push_back(val);
    }
    else if (sameCnt > maxCnt) {
        maxCnt = sameCnt;
        rslt.clear();
        rslt.push_back(val);
    }
}