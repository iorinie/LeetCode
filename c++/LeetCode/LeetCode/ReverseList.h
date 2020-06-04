#include <cstddef>

#ifndef REVERSELIST_H

#define REVERSELIST_H

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head);

#endif // !REVERSELIST_H
