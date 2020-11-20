#include "InsertionSortList.h"

/*
    ��Ŀ������
        ��������в�������
        ��������Ķ�����ʾ���ϡ��ӵ�һ��Ԫ�ؿ�ʼ����������Ա���Ϊ�Ѿ����������ú�ɫ��ʾ����
        ÿ�ε���ʱ���������������Ƴ�һ��Ԫ�أ��ú�ɫ��ʾ������ԭ�ؽ�����뵽���ź���������С�

    ���������㷨��
        1. ���������ǵ����ģ�ÿ��ֻ�ƶ�һ��Ԫ�أ�ֱ������Ԫ�ؿ����γ�һ�����������б�
        2. ÿ�ε����У���������ֻ�������������Ƴ�һ���������Ԫ�أ��ҵ������������ʵ���λ�ã���������롣
        3. �ظ�ֱ�������������ݲ�����Ϊֹ��

    ʾ��1��
        ����: 4->2->1->3
        ���: 1->2->3->4

    ʾ��2��
        ����: -1->5->3->4->0
        ���: -1->0->3->4->5

    ʾ��3��
        ����: 3->2->4
        ���: 2->3->4
*/
/*
    �ⷨ1��
    ȱ�㣺
    ֪ʶ�㣺
        1.
*/
ListNode* insertionSortList(ListNode* head) {
    if (!head) return head;

    ListNode* fake = new ListNode(0);
    fake->next = head;
    int lLen = 0; //������Ч����
    vector<ListNode*> cache; //ÿ��ѭ����Ŀ��ڵ�
    ListNode* p = head;
    while (p) {
        lLen++;
        cache.push_back(p);
        p = p->next;
    }
    for (int i = 1; i < lLen; i++) { //ѭ��������ÿ�δ���cache[i]
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