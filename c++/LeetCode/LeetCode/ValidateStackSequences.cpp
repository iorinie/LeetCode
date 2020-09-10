#include "ValidateStackSequences.h"
#include <stack>

/*
    ��Ŀ������
        ���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
        ����ѹ��ջ���������־�����ȡ�
        ���磬���� {1,2,3,4,5} ��ĳջ��ѹջ���У����� {4,5,3,2,1} �Ǹ�ѹջ���ж�Ӧ��һ���������У��� {4,3,5,1,2} �Ͳ������Ǹ�ѹջ���еĵ������С�

    ʾ��1��
        ���룺pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
        �����true
        ���ͣ�
            ���ǿ��԰�����˳��ִ�У�
            push(1), push(2), push(3), push(4), pop() -> 4,
            push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

    ʾ��2��
        ���룺pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
        �����false
        ���ͣ�
            1 ������ 2 ֮ǰ������
*/
/*
    �ⷨ1��ʹ��һ������ջģ����������ջ����
    ȱ�㣺�߼��Ͽ����Ż�һ�£�����ѭ�������ͽ�����ж�����������д�������Ĵ��롣
    ֪ʶ�㣺
        1. stackΪ��ʱ������top()����
        2. whileѭ����ȡ����Ԫ��ʱ��ע���±�Խ�������
*/
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int firstIdx = 0, secondIdx = 0;
    stack<int> s;
    while (firstIdx < pushed.size()) {
        while (pushed[firstIdx] != popped[secondIdx]) {
            s.push(pushed[firstIdx]);
            firstIdx++;
            if (firstIdx >= pushed.size()) return false;
        }
        secondIdx++;
        while (secondIdx < popped.size()) {
            if (!s.empty() && s.top() == popped[secondIdx]) {
                s.pop();
            }
            else {
                break;
            }
            secondIdx++;
        }
        firstIdx++;
    }
    return s.empty();
}