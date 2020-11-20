#include "InsertionSortList.h"

/*
    题目描述：
        对链表进行插入排序。
        插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
        每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。

    插入排序算法：
        1. 插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
        2. 每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
        3. 重复直到所有输入数据插入完为止。

    示例1：
        输入: 4->2->1->3
        输出: 1->2->3->4

    示例2：
        输入: -1->5->3->4->0
        输出: -1->0->3->4->5

    示例3：
        输入: 3->2->4
        输出: 2->3->4
*/
/*
    解法1：
    缺点：
    知识点：
        1.
*/
ListNode* insertionSortList(ListNode* head) {
    if (!head) return head;

    ListNode* fake = new ListNode(0);
    fake->next = head;
    int lLen = 0; //链表有效长度
    vector<ListNode*> cache; //每次循环的目标节点
    ListNode* p = head;
    while (p) {
        lLen++;
        cache.push_back(p);
        p = p->next;
    }
    for (int i = 1; i < lLen; i++) { //循环次数，每次处理cache[i]
        int cnt = i;
        bool done = false;
        p = fake;
        while (cnt) {
            if (!done && (p->next->val > cache[i]->val)) {
                ListNode* temp = p->next;
                p->next = cache[i];
                cache[i]->next = temp;
                done = true;
            }
            p = p->next;
            cnt--;
        }
        if (!done) {
            p->next = cache[i];
        }
        p->next->next = nullptr;
    }

    return fake->next;
}

ListNode* createList(vector<int>& v) {
    ListNode* head = new ListNode(v[0]);

    ListNode* p = head;
    for (int i = 1; i < v.size(); i++) {
        ListNode* n = new ListNode(v[i]);
        p->next = n;
        p = p->next;
    }

    return head;
}