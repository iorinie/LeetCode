#include "IsValid.h"
#include <stack>

/*
    题目描述：
        给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
        有效字符串需满足：
            1. 左括号必须用相同类型的右括号闭合。
            2. 左括号必须以正确的顺序闭合。
        注意空字符串可被认为是有效字符串。

    示例1：
        输入: "()"
        输出: true

    示例1：
        输入: "()[]{}"
        输出: true

    示例1：
        输入: "(]"
        输出: false

    示例1：
        输入: "([)]"
        输出: false

    示例1：
        输入: "{[]}"
        输出: true
*/
/*
    解法1：使用栈，遇左括号入栈，遇右括号出栈比较
    缺点：空间复杂度较大
    知识点：
        1.
*/
bool isValid(string s) {
    stack<char> tool;
    for (int i = 0; i < s.size(); i++) {
        switch (s[i]) {
        case '(':
        case '{':
        case '[':
            tool.push(s[i]);
            break;
        case ')':
            if (tool.empty() || tool.top() != '(') {
                return false;
            }
            tool.pop();
            break;
        case '}':
            if (tool.empty() || tool.top() != '{') {
                return false;
            }
            tool.pop();
            break;
        case ']':
            if (tool.empty() || tool.top() != '[') {
                return false;
            }
            tool.pop();
            break;
        }
    }
    if (!tool.empty()) {
        return false;
    }

    return true;
}