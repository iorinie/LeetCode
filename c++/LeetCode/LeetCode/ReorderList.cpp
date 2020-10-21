#include "ReorderList.h"
#include <deque>

using namespace std;

/*
    题目描述：
        给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
        将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
        你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

    示例1：
        给定链表 1->2->3->4, 重新排列为 1->4->2->3.

    示例2：
        给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
*/
/*
    解法2：中间断开，翻转后链，合并两链
    缺点：
    知识点：
        1. 快慢指针找链表中点
        2. 递归翻转链表
        3. 递归合并两个链表
        4. 如何使用迭代替换递归
*/
void reorderList(ListNode* head) {
    if (!head || !head->next || !head->next->next) return;

    ListNode* mid = findMid(head);
    ListNode* cache = mid->next;
    mid->next = nullptr;
    ListNode* reverseCache = reverseList(cache);
    mergeList(head, reverseCache);
}

ListNode* findMid(ListNode* head) {
    ListNode* fast = head, * slow = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

ListNode* reverseList(ListNode* head) {
    if (!head->next) return head;

    ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}

//ListNode* reverseList(ListNode* head) {
//    ListNode* prev = nullptr;
//    ListNode* curr = head;
//    while (curr != nullptr) {
//        ListNode* nextTemp = curr->next;
//        curr->next = prev;
//        prev = curr;
//        curr = nextTemp;
//    }
//    return prev;
//}

ListNode* mergeList(ListNode* l1, ListNode* l2) {
    if (!l2) return l1;

    ListNode* cache = mergeList(l1->next, l2->next);
    l1->next = l2;
    l2->next = cache;

    return l1;
}

//void mergeList(ListNode* l1, ListNode* l2) {
//    ListNode* l1_tmp;
//    ListNode* l2_tmp;
//    while (l1 != nullptr && l2 != nullptr) {
//        l1_tmp = l1->next;
//        l2_tmp = l2->next;
//
//        l1->next = l2;
//        l1 = l1_tmp;
//
//        l2->next = l1;
//        l2 = l2_tmp;
//    }
//}

/*
    解法1：双端队列入队，头尾依次出队，循环拼接
    缺点：时空复杂度过高，就算使用辅助结构，也可以使用vector
    知识点：
        1. 注意看返回值
*/
//void reorderList(ListNode* head) {
//    if (!head || !head->next || !head->next->next) return;
//
//    deque<ListNode*> deq;
//    ListNode* p = head;
//    while (p) {
//        deq.push_back(p);
//        p = p->next;
//    }
//    while (!deq.empty()) {
//        ListNode* front = deq.front();
//        deq.pop_front();
//        if (p) p->next = front;
//        if (!deq.empty()) {
//            ListNode* back = deq.back();
//            deq.pop_back();
//            front->next = back;
//            p = back;
//        }
//        else {
//            p = front;
//        }
//    }
//    p->next = nullptr;
//}