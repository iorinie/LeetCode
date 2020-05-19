#include <cstddef>

#ifndef REMOVENTHFROMEND_H

#define REMOVENTHFROMEND_H

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n);

#endif
