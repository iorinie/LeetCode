#include "LengthOfLongestSubstring.h"

/*
    题目描述：
        给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

    示例：
        输入: "abcabcbb"
        输出: 3 
        解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

        输入: "bbbbb"
        输出: 1
        解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

        输入: "pwwkew"
        输出: 3
        解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。

        请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

/*
    解法1：使用两个指针维持一个滑动窗口，保持窗口中的子串没有重复字符，记录窗口中子串的最大长度
    缺点：滑动窗口的数据结构和重复字符判断方式可以有更优的形式，减少时间复杂度
    知识点：
        1. string.size()返回的类型不是int
        2. 使用多个指针解题时，需要明确每个指针的作用范围
        3. 嵌套循环的内层循环里对外层变量自增时，需要关注内层自增会不会导致越界
*/
int lengthOfLongestSubstring(string s) {
    int max = 0;
    string window; //滑动窗口，用于保留不重复的子串
    int left = 0, right = 0; //左右指针，右指针用于添加字符到window，左指针用于将重复的字符从window中删掉
    while (right < int(s.size())) {
        char rC = s[right];
        int repeatIdx = window.find(rC);
        while (repeatIdx == -1) {
            window.push_back(rC);
            //max = right - left > max ? right - left : max;
            max = int(window.size()) > max ? window.size() : max;
            right++;
            if (right >= int(s.size())) {
                break;
            }
            rC = s[right];
            repeatIdx = window.find(rC);
        }
        if (right >= int(s.size())) {
            break;
        }
        window.push_back(rC);
        while (left <= repeatIdx) {
            window.erase(0, 1);
            left++;
        }
        left = 0;
        right++;
    }

    return max;
}