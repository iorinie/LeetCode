#include "LetterCasePermutation.h"

/*
    题目描述：
        给定一个字符串S，通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。

    示例：
        输入: S = "a1b2"
        输出: ["a1b2", "a1B2", "A1b2", "A1B2"]

        输入: S = "3z4"
        输出: ["3z4", "3Z4"]

        输入: S = "12345"
        输出: ["12345"]

    注意事项：
        1. S 的长度不超过12。
        2. S 仅由数字和字母组成。
*/

/*
    解法1：回溯
    缺点：非常多的重复解答，时间复杂度巨高无比
    知识点：
        1. 取字符串中的某个字符，能否使用下标的方式？
        2. 字母大小写转换，需要强记ascii吗？
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