#include "AddStrings.h"
#include <stack>
#include <map>

/*
    题目描述：
        给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

    注意：
        1. num1 和num2 的长度都小于 5100.
        2. num1 和num2 都只包含数字 0-9.
        3. num1 和num2 都不包含任何前导零。
        4. 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
*/
/*
    解法1：使用两个栈
    缺点：时空复杂度都很高
    知识点：
        1. stack将char推入后，类型是const char
*/
string addStrings(string num1, string num2) {
    string rslt;

    map<char, int> refc2i;
    refc2i['0'] = 0;
    refc2i['1'] = 1;
    refc2i['2'] = 2;
    refc2i['3'] = 3;
    refc2i['4'] = 4;
    refc2i['5'] = 5;
    refc2i['6'] = 6;
    refc2i['7'] = 7;
    refc2i['8'] = 8;
    refc2i['9'] = 9;
    map<int, char> refi2c;
    refi2c[0] = '0';
    refi2c[1] = '1';
    refi2c[2] = '2';
    refi2c[3] = '3';
    refi2c[4] = '4';
    refi2c[5] = '5';
    refi2c[6] = '6';
    refi2c[7] = '7';
    refi2c[8] = '8';
    refi2c[9] = '9';

    stack<char> s1, s2;
    for (int i = 0; i < num1.size(); i++) {
        s1.push(num1[i]);
    }
    for (int i = 0; i < num2.size(); i++) {
        s2.push(num2[i]);
    }
    int adv = 0; //进位
    while (!s1.empty() || !s2.empty() || adv != 0) {
        int a = 0, b = 0;
        if (!s1.empty()) {
            a = refc2i[s1.top()];
            s1.pop();
        }
        if (!s2.empty()) {
            b = refc2i[s2.top()];
            s2.pop();
        }
        rslt.insert(0, 1, refi2c[(a + b + adv) % 10]);
        adv = (a + b + adv) / 10;
    }

    return rslt;
}