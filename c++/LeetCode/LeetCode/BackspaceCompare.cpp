#include "BackspaceCompare.h"

/*
    题目描述：
        给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。

    注意：如果对空文本输入退格字符，文本继续为空。

    示例1：
        输入：S = "ab#c", T = "ad#c"
        输出：true
        解释：S 和 T 都会变成 “ac”。

    示例2：
        输入：S = "ab##", T = "c#d#"
        输出：true
        解释：S 和 T 都会变成 “”。

    示例3：
        输入：S = "a##c", T = "#a#c"
        输出：true
        解释：S 和 T 都会变成 “c”。

    示例4：
        输入：S = "a#c", T = "b"
        输出：false
        解释：S 会变成 “c”，但 T 仍然是 “b”。

    提示：
        1. 1 <= S.length <= 200
        2. 1 <= T.length <= 200
        3. S 和 T 只含有小写字母以及字符 '#'。

    进阶：你可以用 O(N) 的时间复杂度和 O(1) 的空间复杂度解决该问题吗？
*/
/*
    解法1：进阶要求解法，双指针，从尾部开始遍历
    缺点：
    知识点：
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