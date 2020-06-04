#include "ReverseList.h"

/*
    ��Ŀ������
        ��תһ��������

    ʾ����
        ����: 1->2->3->4->5->NULL
        ���: 5->4->3->2->1->NULL

    ���ף�
        ����Ե�����ݹ�ط�ת�������ܷ������ַ����������⣿
*/

/*
    �ⷨ1���ݹ飬��β�ڵ㿪ʼ��ת��ؽڵ㣬���Ͽ���֮ǰ�������ϵ��������ͷ���
    ȱ�㣺

    ֪ʶ�㣺
        1. ���������ݹ��еĸ�����������ָ����ɶ
*/
ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}