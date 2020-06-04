#include "ReverseList.h"

/*
    题目描述：
        反转一个单链表。

    示例：
        输入: 1->2->3->4->5->NULL
        输出: 5->4->3->2->1->NULL

    进阶：
        你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
*/

/*
    解法1：递归，从尾节点开始反转相关节点，并断开与之前链表的联系，返回新头结点
    缺点：

    知识点：
        1. 搞清楚链表递归中的各个变量到底指的是啥
*/
ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}