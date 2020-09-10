#include "ValidateStackSequences.h"
#include <stack>

/*
    题目描述：
        输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
        假设压入栈的所有数字均不相等。
        例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

    示例1：
        输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
        输出：true
        解释：
            我们可以按以下顺序执行：
            push(1), push(2), push(3), push(4), pop() -> 4,
            push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

    示例2：
        输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
        输出：false
        解释：
            1 不能在 2 之前弹出。
*/
/*
    解法1：使用一个辅助栈模拟整个进出栈流程
    缺点：逻辑上可以优化一下，更改循环条件和结果的判断条件，可以写出更简洁的代码。
    知识点：
        1. stack为空时，调用top()报错
        2. while循环获取数组元素时，注意下标越界的问题
*/
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int firstIdx = 0, secondIdx = 0;
    stack<int> s;
    while (firstIdx < pushed.size()) {
        while (pushed[firstIdx] != popped[secondIdx]) {
            s.push(pushed[firstIdx]);
            firstIdx++;
            if (firstIdx >= pushed.size()) return false;
        }
        secondIdx++;
        while (secondIdx < popped.size()) {
            if (!s.empty() && s.top() == popped[secondIdx]) {
                s.pop();
            }
            else {
                break;
            }
            secondIdx++;
        }
        firstIdx++;
    }
    return s.empty();
}