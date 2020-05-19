#include "RemoveNthFormEnd.h"

/*
    题目描述：
        给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

    示例：
        给定一个链表: 1->2->3->4->5, 和 n = 2.
        当删除了倒数第二个节点后，链表变为 1->2->3->5.

    说明：
        给定的 n 保证是有效的。

    进阶：
        你能尝试使用一趟扫描实现吗？
*/

/*
    解法1：头结点前增加一个节点，双指针，两指针相差N，同时走，右指针为空时，左指针的next为要删掉的节点。
    优点：head前增加节点，避免了后续一堆边界条件的判断，同时方便删节点

    知识点：
        1. 如果需要删除指针所指节点，可以将本节点的next节点复制到本节点后，删除next节点。c++是否需要调用delete？
*/
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head) {
        return head;
    }
    ListNode* p = new ListNode(0);
    p->next = head;
    ListNode* p1 = p;
    ListNode* p2 = head;
    for (int i = 0; i < n; i++) {
        p2 = p2->next;
    }
    while (p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    p1->next = p1->next->next;

    return p->next;
}