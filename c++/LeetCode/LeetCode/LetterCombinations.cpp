#include "LetterCombinations.h"

/*
    ��Ŀ������
        ����һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ�
        �������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��

    ʾ����
        ���룺"23"
        �����["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

    ˵����
        ��������Ĵ��ǰ��ֵ������еģ��������������ѡ��������˳��
*/
/*
    �ⷨ1�����ݣ�ȫ����
    ȱ�㣺
    ֪ʶ�㣺
        1.
*/
vector<string> letterCombinations(string digits) {
    vector<string> rslt;
    if (digits == "") {
        return rslt;
    }

    string path;
    recurse(rslt, digits, path);

    return rslt;
}

char alphaArray[8][4] = { //9�������뷨����2-9��Ӧ����ĸ
        {'a', 'b', 'c', '0'},
        {'d', 'e', 'f', '0'},
        {'g', 'h', 'i', '0'},
        {'j', 'k', 'l', '0'},
        {'m', 'n', 'o', '0'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v', '0'},
        {'w', 'x', 'y', 'z'},
};

void recurse(vector<string>& rslt, string digits, string path) {
    if (path.size() == digits.size()) {
        rslt.push_back(path);
        return;
    }

    int tempNum = digits[path.size()] - '0';
    for (int j = 0; j < 4; j++) {
        if (alphaArray[tempNum - 2][j] == '0')
            continue;

        path.push_back(alphaArray[tempNum - 2][j]); //ѡ��һ����ĸ
        recurse(rslt, digits, path);
        path.pop_back(); //�������ѡ��
    }
}