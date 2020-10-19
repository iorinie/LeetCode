#include "BackspaceCompare.h"

/*
    ��Ŀ������
        ���� S �� T �����ַ����������Ƿֱ����뵽�հ׵��ı��༭�����ж϶����Ƿ���ȣ������ؽ���� # �����˸��ַ���

    ע�⣺����Կ��ı������˸��ַ����ı�����Ϊ�ա�

    ʾ��1��
        ���룺S = "ab#c", T = "ad#c"
        �����true
        ���ͣ�S �� T ������ ��ac����

    ʾ��2��
        ���룺S = "ab##", T = "c#d#"
        �����true
        ���ͣ�S �� T ������ ������

    ʾ��3��
        ���룺S = "a##c", T = "#a#c"
        �����true
        ���ͣ�S �� T ������ ��c����

    ʾ��4��
        ���룺S = "a#c", T = "b"
        �����false
        ���ͣ�S ���� ��c������ T ��Ȼ�� ��b����

    ��ʾ��
        1. 1 <= S.length <= 200
        2. 1 <= T.length <= 200
        3. S �� T ֻ����Сд��ĸ�Լ��ַ� '#'��

    ���ף�������� O(N) ��ʱ�临�ӶȺ� O(1) �Ŀռ临�ӶȽ����������
*/
/*
    �ⷨ1������Ҫ��ⷨ��˫ָ�룬��β����ʼ����
    ȱ�㣺
    ֪ʶ�㣺
        1.
*/
bool backspaceCompare(string S, string T) {
    int left = S.size() - 1, right = T.size() - 1;
    int backCnt1 = 0, backCnt2 = 0;

    while (left >= 0 || right >= 0) {
        while (left >= 0) {
            if (S[left] == '#') {
                left--;
                backCnt1++;
            }
            else if (backCnt1 > 0) {
                left--;
                backCnt1--;
            }
            else {
                break;
            }
        }
        while (right >= 0) {
            if (T[right] == '#') {
                right--;
                backCnt2++;
            }
            else if (backCnt2 > 0) {
                right--;
                backCnt2--;
            }
            else {
                break;
            }
        }
        if (left >= 0 && right >= 0) {
            if (S[left] != T[right]) return false;
        }
        else {
            if (left >= 0 || right >= 0) return false;
        }
        left--;
        right--;
    }

    return true;
}