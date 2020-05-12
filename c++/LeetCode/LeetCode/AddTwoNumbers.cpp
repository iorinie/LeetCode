#include <cstddef>

using namespace std;

/*
    题目描述：
        给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
        如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
        您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

    示例：
        输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
        输出：7 -> 0 -> 8
        原因：342 + 465 = 807
*/

/*
    解法1：同步并顺序遍历两个链表，两数相加，保留进位
    缺点：使用更优的while条件，可以使代码更优雅

    知识点：
        1. 结构体构造函数类型及使用
        2. 指针作为函数参数传入、作为返回值返回
        3. c++的true/false（0/1？）判断方式
        4. new/delete与malloc/free的区别
        5. 变量作用域，new、static等原理
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* p, * p1, * p2;
    int adv = 0;
    int tempV = (l1->val + l2->val + adv) % 10;
    adv = (l1->val + l2->val + adv) / 10;
    //ListNode rslt = { tempV };
    ListNode* rslt = new ListNode(tempV);
    //p = &rslt;
    p = rslt;
    p1 = l1->next;
    p2 = l2->next;
    while (p1 || p2) {
        int a = 0, b = 0;
        if (p1) {
            a = p1->val;
            p1 = p1->next;
        }
        if (p2) {
            b = p2->val;
            p2 = p2->next;
        }
        tempV = (a + b + adv) % 10;
        adv = (a + b + adv) / 10;
        ListNode* tempNode = new ListNode(tempV);
        p->next = tempNode;
        p = p->next;
    }
    if (adv != 0) {
        ListNode* tempNode = new ListNode(adv);
        p->next = tempNode;
    }
    return rslt;
}