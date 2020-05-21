#include "LetterCasePermutation.h"

/*
    ��Ŀ������
        ����һ���ַ���S��ͨ�����ַ���S�е�ÿ����ĸת���Сд�����ǿ��Ի��һ���µ��ַ������������п��ܵõ����ַ������ϡ�

    ʾ����
        ����: S = "a1b2"
        ���: ["a1b2", "a1B2", "A1b2", "A1B2"]

        ����: S = "3z4"
        ���: ["3z4", "3Z4"]

        ����: S = "12345"
        ���: ["12345"]

    ע�����
        1. S �ĳ��Ȳ�����12��
        2. S �������ֺ���ĸ��ɡ�
*/

/*
    �ⷨ1������
    ȱ�㣺�ǳ�����ظ����ʱ�临�ӶȾ޸��ޱ�
    ֪ʶ�㣺
        1. ȡ�ַ����е�ĳ���ַ����ܷ�ʹ���±�ķ�ʽ��
        2. ��ĸ��Сдת������Ҫǿ��ascii��
*/
vector<string> letterCasePermutation(string S) {
    vector<string> rslt;
    rslt.push_back(S);
    int start = 0, end = S.size();
    recursion(S, start, end, rslt);

    return rslt;
}

void recursion(string s, int start, int end, vector<string>& rslt) {
    if (start == end) {
        return;
    }
    for (int i = start; i < end; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s.replace(i, 1, 1, s[i] - 32);
            pushStrToVec(rslt, s);
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            s.replace(i, 1, 1, s[i] + 32);
            pushStrToVec(rslt, s);
        }
        recursion(s, i + 1, end, rslt);
        if (s[i] >= 'a' && s[i] <= 'z') {
            s.replace(i, 1, 1, s[i] - 32);
            pushStrToVec(rslt, s);
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            s.replace(i, 1, 1, s[i] + 32);
            pushStrToVec(rslt, s);
        }
    }
}

void pushStrToVec(vector<string>& rslt, string s) {
    for (int i = 0; i < rslt.size(); i++) {
        if (rslt[i] == s) {
            return;
        }
    }
    rslt.push_back(s);
}