#include "RepeatedSubstringPattern.h"

/*
    ��Ŀ������
        ����һ���ǿյ��ַ������ж����Ƿ����������һ���Ӵ��ظ���ι��ɡ��������ַ���ֻ����СдӢ����ĸ�����ҳ��Ȳ�����10000��

    ʾ��1��
        ���룺"abab"
        �����True
        ���ͣ��������ַ��� "ab" �ظ����ι��ɡ�

    ʾ��2��
        ���룺"aba"
        �����False

    ʾ��3��
        ���룺"abcabcabcabc"
        �����True
        ���ͣ��������ַ��� "abc" �ظ��Ĵι��ɡ� (�������ַ��� "abcabc" �ظ����ι��ɡ�)
*/
/*
    �ⷨ2������벻��
    ȱ�㣺
    ֪ʶ�㣺
        1.
*/
bool repeatedSubstringPattern(string s) {
    string ss = s + s;
    string subSs = ss.substr(1, ss.size() - 2);
    return subSs.find(s) != s.npos;
}

/*
    �ⷨ1����ע��
    ȱ�㣺ʱ�为��ȱȽϸߣ���Ϊ���������right�ƶ��д����ظ���·��
    ֪ʶ�㣺
        1.
*/
//bool repeatedSubstringPattern(string s) {
//    if (s.size() == 1) {
//        return false;
//    }
//
//    int left = 0;
//    int right = 1; //�����������ұ߽磬��߽粻��
//    int window = 0; //�������ڴ�С
//    while (right < s.size()) {
//        left = 0;
//        while (s[right] != s[left]) {
//            right++;
//            if (right >= s.size()) { //ֱ��Խ�綼û���ظ�����ĸ����"abcde"
//                return false;
//            }
//        }
//        //���ظ�����ĸ�����ܺ������ظ�����"ababab"����Ҳ��һ������"abaabaaba"
//        window = right - left;
//        int fakeRight = right;
//        while (s[fakeRight] == s[left]) {
//            left++;
//            fakeRight++;
//            if (fakeRight >= s.size()) { //�ӵ�һ���ظ���ĸ��ʼ������������ĸ����ͬ
//                break;
//            }
//        }
//        if (fakeRight >= s.size()) { //�ӵ�һ���ظ���ĸ��ʼ������������ĸ����ͬ
//            break;
//        }
//        right++;
//    }
//    //�����߽��±�պ�����һ���ظ�·�������������
//    return left % window == 0;
//}