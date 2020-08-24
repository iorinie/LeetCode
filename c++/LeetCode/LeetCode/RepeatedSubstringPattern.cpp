#include "RepeatedSubstringPattern.h"

/*
    题目描述：
        给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。

    示例1：
        输入："abab"
        输出：True
        解释：可由子字符串 "ab" 重复两次构成。

    示例2：
        输入："aba"
        输出：False

    示例3：
        输入："abcabcabcabc"
        输出：True
        解释：可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)
*/
/*
    解法2：这个想不到
    缺点：
    知识点：
        1.
*/
bool repeatedSubstringPattern(string s) {
    string ss = s + s;
    string subSs = ss.substr(1, ss.size() - 2);
    return subSs.find(s) != s.npos;
}

/*
    解法1：看注释
    缺点：时间负责度比较高，因为内外两层的right移动有大量重复的路径
    知识点：
        1.
*/
//bool repeatedSubstringPattern(string s) {
//    if (s.size() == 1) {
//        return false;
//    }
//
//    int left = 0;
//    int right = 1; //滑动窗口左右边界，左边界不动
//    int window = 0; //滑动窗口大小
//    while (right < s.size()) {
//        left = 0;
//        while (s[right] != s[left]) {
//            right++;
//            if (right >= s.size()) { //直到越界都没有重复的字母，如"abcde"
//                return false;
//            }
//        }
//        //有重复的字母，可能后续都重复，如"ababab"，但也不一定，如"abaabaaba"
//        window = right - left;
//        int fakeRight = right;
//        while (s[fakeRight] == s[left]) {
//            left++;
//            fakeRight++;
//            if (fakeRight >= s.size()) { //从第一个重复字母开始，后续所有字母都相同
//                break;
//            }
//        }
//        if (fakeRight >= s.size()) { //从第一个重复字母开始，后续所有字母都相同
//            break;
//        }
//        right++;
//    }
//    //如果左边界下标刚好走完一个重复路径，则符合条件
//    return left % window == 0;
//}