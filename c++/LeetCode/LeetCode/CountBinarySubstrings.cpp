#include "CountBinarySubstrings.h"

/*
    题目描述：
        给定一个字符串 s，计算具有相同数量0和1的非空(连续)子字符串的数量，并且这些子字符串中的所有0和所有1都是组合在一起的。
        重复出现的子串要计算它们出现的次数。

    示例1：
        输入: "00110011"
        输出: 6
        解释: 有6个子串具有相同数量的连续1和0：“0011”，“01”，“1100”，“10”，“0011” 和 “01”。

        请注意，一些重复出现的子串要计算它们出现的次数。

        另外，“00110011”不是有效的子串，因为所有的0（和1）没有组合在一起。 

    示例2：
        输入: "10101"
        输出: 4
        解释: 有4个子串：“10”，“01”，“10”，“01”，它们具有相同数量的连续1和0。 

    注意：
        1. s.length 在1到50,000之间。
        2. s 只包含“0”或“1”字符。
*/
/*
    解法2：记录所有相同数的长度，依次比较取较小值累加
    缺点：
    知识点：
        1.
*/
int countBinarySubstrings(string s) {
    int rslt = 0;
    if (s.size() <= 1) {
        return rslt;
    }

    int last = 0, cur = 1; //不论当前数字是啥，当前相同的数量都为1
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            cur++;
        }
        else {
            if (last != 0) {
                rslt += cur < last ? cur : last;
            }   
            last = cur;
            cur = 1;
        }
    }
    rslt += cur < last ? cur : last;
    
    return rslt;
}

/*
    解法1：双指针，左指针指向相同数的起始位置，右指针指向结尾位置，从右指针往后，找不同数的个数
    缺点：有大量的重复操作，时间复杂度太高
    知识点：
        1.
*/
//int countBinarySubstrings(string s) {
//    int rslt = 0;
//    if (s.size() <= 1) {
//        return rslt;
//    }
//
//    int left = 0, right = 1;
//    while (right < s.size()) {
//        if (s[left] == s[right] && right + 1 < s.size()) {
//            right++;
//        }
//        else {
//            if (s[left] == s[right]) { //相等说明right过界了
//                break;
//            }
//            else {
//                int offset = 0;
//                while (right + offset < s.size() && offset < right - left && s[right + offset] != s[left]) {
//                    rslt++;
//                    offset++;
//                }
//                left = right;
//                right++;
//            }
//        }
//    }
//
//    return rslt;
//}