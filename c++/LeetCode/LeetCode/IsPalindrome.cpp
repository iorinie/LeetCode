#include "IsPalindrome.h"

/*
    ��Ŀ������
        ���ж�һ�������Ƿ�Ϊ��������

    ʾ��1��
        ����: 1->2
        ���: false

    ʾ��2��
        ����: 1->2->2->1
        ���: true

    ���ף�
        ���ܷ��� O(n) ʱ�临�ӶȺ� O(1) �ռ临�ӶȽ�����⣿
*/
/*
    �ⷨ1���㲻����׽ⷨ��
    ȱ�㣺���Բ���Ӹ����м�ڵ㣬������Ϊ����ʱ�����Ƚ��м�ڵ������
    ֪ʶ�㣺
        1. ͷ�����ò�����ݹ�����
*/
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;

    //��ȡ�м�ڵ㣬����������������������е������һ���е�Ŀ����ڵ�
    //ʱ��N/2���ռ�1
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

    //��������е�Ͽ�����һ���ѱ�֤�Ͽ����������������ͬ��������ת��������һ��
    //ʱ��N/2���ռ�1
    ListNode* head2 = mid->next;
    mid->next = nullptr;
    ListNode* pre = nullptr;
    while (head2) {
        ListNode* n = head2->next;
        head2->next = pre;
        pre = head2;
        head2 = n;
    }
    head2 = pre; //�����Ǹ���ӣ���ʵpre���Ƿ�ת��������ͷ

    //�Ա����������Ƿ�һһ��Ӧ
    //ʱ��N���ռ�1
    while (head) { //���������ǵȳ��ģ������ж�����
        if (head->val != head2->val) return false;

        head = head->next;
        head2 = head2->next;
    }

    //��ʱ��2N���ռ�1

    return true;
}

/*
    �ⷨ2������������ִ���������ת��Ϊ���֣����Ƚ������Ƿ���ͬ
    ȱ�㣺�������������⣬�����ȷǳ����ҽڵ�ֵ�ܴ�ʱ����������
    ֪ʶ�㣺
        1. ���������ͷ��β���β��ͷ���ɵ�������һ����
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