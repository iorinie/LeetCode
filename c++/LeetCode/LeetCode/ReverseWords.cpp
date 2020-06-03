#include "ReverseWords.h"

/*
    题目描述：
        给定一个字符串，逐个翻转字符串中的每个单词。

    示例：
        输入: "the sky is blue"
        输出: "blue is sky the"

        输入: "  hello world!  "
        输出: "world! hello"
        解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。

        输入: "a good   example"
        输出: "example good a"
        解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

    说明：
        1. 无空格字符构成一个单词。
        2. 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
        3. 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
*/

/*
    解法1：
    缺点：
    知识点：
        1.
        2.
*/
string reverseWords(string s) {
    if (s == "") {
        return s;
    }
    //翻转整个字符串
    int i = 0, j = s.size() - 1;
    while (i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    //每个单词单独翻转
    string rslt;
    //int curIdx = 0;
    int start = 0, end = 0;
    while (end < s.size()) {
        while (start < s.size() && s[start] == ' ') {
            start++;
        }
        end = start + 1;
        while (end < s.size() && s[end] != ' ') {
            end++;
        }
        if (end > s.size()) {
            end = s.size();
        }
        for (int i = end - 1; i >= start; i--) {
            //rslt[curIdx++] = s[i];
            rslt.push_back(s[i]);
        }
        //rslt[curIdx++] = ' ';
        rslt.push_back(' ');
        start = end;
    }
    int len = rslt.size() - 1;
    while (len >= 0 && rslt.at(len) == ' ') {
        rslt.pop_back();
        len--;
    }

    return rslt;
}