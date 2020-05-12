#include <cstddef>

using namespace std;

#ifndef ADDTWONUMS_H

#define ADDTWONUMS_H

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

#endif