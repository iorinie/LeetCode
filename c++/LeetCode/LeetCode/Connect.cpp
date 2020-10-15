#include "Connect.h"

/*
    题目描述：
        给定一个二叉树
        struct Node {
            int val;
            Node *left;
            Node *right;
            Node *next;
        }
        填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
        初始状态下，所有 next 指针都被设置为 NULL。

    进阶：
        1. 你只能使用常量级额外空间。
        2. 使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。

    示例1：
        输入：root = [1,2,3,4,5,null,7]
        输出：[1,#,2,3,#,4,5,7,#]
        解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。
*/
/*
    解法1：
    缺点：
    知识点：
        1. 参数中又有*又有&是什么意思？
*/
Node* connect(Node* root) {
    if (!root) return root;

    Node* start = root;
    while (start) {
        Node* pre = NULL, * nextStart = NULL;
        for (Node* n = start; n; n = n->next) {
            if (n->left) help(pre, n->left, nextStart);
            if (n->right) help(pre, n->right, nextStart);
        }
        start = nextStart;
    }

    return root;
}

void help(Node*& pre, Node*& cur, Node*& nextStart) {
    if (pre) pre->next = cur;

    if (!nextStart) nextStart = cur;

    pre = cur;
}