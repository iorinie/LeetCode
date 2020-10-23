#include "IsPalindrome.h"

/*
    题目描述：
        请判断一个链表是否为回文链表。

    示例1：
        输入: 1->2
        输出: false

    示例2：
        输入: 1->2->2->1
        输出: true

    进阶：
        你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
*/
/*
    解法1：算不算进阶解法？
    缺点：可以不添加辅助中间节点，链表长度为奇数时，不比较中间节点就行了
    知识点：
        1. 头结点最好不参与递归或迭代
*/
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;

    //获取中间节点，如果链表长度是奇数，则在中点后增加一个中点的拷贝节点
    //时间N/2，空间1
    ListNode *slow = head, *fast = head;
    ListNode* mid = nullptr;
    while (true) {
        if (!fast->next) {
            ListNode* sup = new ListNode(slow->val);
            mid = slow;
            sup->next = mid->next;
            mid->next = sup;
            break;
        }
        if (!fast->next->next) {
            mid = slow;
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    //将链表从中点断开（上一步已保证断开后的两个链表长度相同），并翻转其中任意一个
    //时间N/2，空间1
    ListNode* head2 = mid->next;
    mid->next = nullptr;
    ListNode* pre = nullptr;
    while (head2) {
        ListNode* n = head2->next;
        head2->next = pre;
        pre = head2;
        head2 = n;
    }
    head2 = pre; //这里是个大坑，其实pre才是翻转链表后的新头

    //对比两个链表，是否一一对应
    //时间N，空间1
    while (head) { //两个链表是等长的，无需判断两个
        if (head->val != head2->val) return false;

        head = head->next;
        head2 = head2->next;
    }

    //总时间2N，空间1

    return true;
}

/*
    解法2：将链表的数字从两个方向转化为数字，最后比较数字是否相同
    缺点：变量的容量问题，链表长度非常大并且节点值很大时，会有问题
    知识点：
        1. 回文链表从头往尾或从尾往头生成的数字是一样的
*/
//bool isPalindrome(ListNode* head) {
//    unsigned long listToNum = 0, revListToNum = 0, carry = 1;
//    while (head) {
//        listToNum = listToNum * 10 + head->val;
//        revListToNum = revListToNum + carry * head->val;
//        carry *= 10;
//        head = head->next;
//    }
//
//    return listToNum == revListToNum;
//}