#include "ValidPalindrome.h"

/*
    题目描述：
        给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

    示例：
        输入: "aba"
        输出: True

        输入: "abca"
        输出: True
        解释: 你可以删除c字符。

        输入: "cuppucu"
        输出: True

        请注意，字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。
*/

/*
    解法1：一头一尾双指针
    缺点：某些情况下（如："cuppucu"）会出现分支的情况，回溯思路比较复杂，代码不够优雅。可以将两种情况各判断一次，只要满足其一，就是回文
    知识点：
        1. 
*/
bool validPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    int remainDelCnt = 1;
    bool needRecall = false;
    int recallLeft = 0, recallRight = 0;
    while (left < right) {
        if (s.at(left) == s.at(right)) {
            left++;
            right--;
        }
        else {
            if (remainDelCnt < 1) {
                if (needRecall) { //只能回退一次
                    left = recallLeft;
                    right = recallRight;
                    recallLeft = 0;
                    recallRight = 0;
                    needRecall = false;
                    continue;
                }
                else {
                    return false;
                }
            }
            bool leftPlus = false;
            if (s.at(left + 1) == s.at(right)) {
                leftPlus = true;
            }
            if (s.at(left) == s.at(right - 1)) {
                if (leftPlus) {
                    needRecall = true;
                    recallLeft = left;
                    recallRight = right - 1;
                }
                else {
                    right--;
                }
            }
            if (leftPlus) {
                left++;
            }
            remainDelCnt--;
        }
    }
    return true;
}