#include <vector>

using namespace std;

#ifndef INDERTIONSORTLIST_H

#define INDERTIONSORTLIST_H

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* createList(vector<int>& v);

ListNode* insertionSortList(ListNode* head);

#endif // !INDERTIONSORTLIST_H
