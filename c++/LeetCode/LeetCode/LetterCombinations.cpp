#include "LetterCombinations.h"

/*
    题目描述：
        给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
        给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

    示例：
        输入："23"
        输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

    说明：
        尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
*/
/*
    解法1：回溯，全排列
    缺点：
    知识点：
        1.
*/
vector<string> letterCombinations(string digits) {
    vector<string> rslt;
    if (digits == "") {
        return rslt;
    }

    string path;
    recurse(rslt, digits, path);

    return rslt;
}

char alphaArray[8][4] = { //9宫格输入法数字2-9对应的字母
        {'a', 'b', 'c', '0'},
        {'d', 'e', 'f', '0'},
        {'g', 'h', 'i', '0'},
        {'j', 'k', 'l', '0'},
        {'m', 'n', 'o', '0'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v', '0'},
        {'w', 'x', 'y', 'z'},
};

void recurse(vector<string>& rslt, string digits, string path) {
    if (path.size() == digits.size()) {
        rslt.push_back(path);
        return;
    }

    int tempNum = digits[path.size()] - '0';
    for (int j = 0; j < 4; j++) {
        if (alphaArray[tempNum - 2][j] == '0')
            continue;

        path.push_back(alphaArray[tempNum - 2][j]); //选择一个字母
        recurse(rslt, digits, path);
        path.pop_back(); //撤销这个选择
    }
}