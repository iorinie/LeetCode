#ifndef REORDERLIST_H

#define REORDERLIST_H

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void reorderList(ListNode* head);

ListNode* findMid(ListNode* head);

ListNode* reverseList(ListNode* head);

ListNode* mergeList(ListNode* l1, ListNode* l2);

#endif // !REORDERLIST_H