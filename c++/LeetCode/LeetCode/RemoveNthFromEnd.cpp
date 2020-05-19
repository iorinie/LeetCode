#include "RemoveNthFormEnd.h"

/*
    ��Ŀ������
        ����һ������ɾ������ĵ����� n ���ڵ㣬���ҷ��������ͷ��㡣

    ʾ����
        ����һ������: 1->2->3->4->5, �� n = 2.
        ��ɾ���˵����ڶ����ڵ�������Ϊ 1->2->3->5.

    ˵����
        ������ n ��֤����Ч�ġ�

    ���ף�
        ���ܳ���ʹ��һ��ɨ��ʵ����
*/

/*
    �ⷨ1��ͷ���ǰ����һ���ڵ㣬˫ָ�룬��ָ�����N��ͬʱ�ߣ���ָ��Ϊ��ʱ����ָ���nextΪҪɾ���Ľڵ㡣
    �ŵ㣺headǰ���ӽڵ㣬�����˺���һ�ѱ߽��������жϣ�ͬʱ����ɾ�ڵ�

    ֪ʶ�㣺
        1. �����Ҫɾ��ָ����ָ�ڵ㣬���Խ����ڵ��next�ڵ㸴�Ƶ����ڵ��ɾ��next�ڵ㡣c++�Ƿ���Ҫ����delete��
*/
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head) {
        return head;
    }
    ListNode* p = new ListNode(0);
    p->next = head;
    ListNode* p1 = p;
    ListNode* p2 = head;
    for (int i = 0; i < n; i++) {
        p2 = p2->next;
    }
    while (p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    p1->next = p1->next->next;

    return p->next;
}