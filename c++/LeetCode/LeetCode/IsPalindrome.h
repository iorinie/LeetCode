#ifndef ISPALINDROME_H

#define ISPALINDROME_H

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

bool isPalindrome(ListNode* head);

#endif // !ISPALINDROME_H