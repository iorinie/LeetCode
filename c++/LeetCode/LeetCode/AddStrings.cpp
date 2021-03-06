﻿#include "AddStrings.h"
#include <stack>
#include <map>
#include <vector>

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
    解法3：活用字符与ascii码的关系、字符串的翻转
    缺点：
    知识点：
        1. 数字的char，减去'0'，相当于ascii码相减，结果即为int
*/
string addStrings(string num1, string num2) {
    string rslt;

    int len1 = num1.size() - 1, len2 = num2.size() - 1, carry = 0;
    while (len1 >= 0 || len2 >= 0 || carry != 0) {
        if (len1 >= 0) {
            carry += num1[len1--] - '0';
        }
        if (len2 >= 0) {
            carry += num2[len2--] - '0';
        }
        rslt.push_back(char('0' + (carry % 10)));
        carry /= 10;
    }
    reverse(rslt.begin(), rslt.end());

    return rslt;
}

/*
    解法2：直接从后往前遍历入参，时空复杂度都小了些
    缺点：
    知识点：
        1. 
*/
//string addStrings(string num1, string num2) {
//    string rslt;
//
//    map<char, int> refc2i;
//    refc2i['0'] = 0;
//    refc2i['1'] = 1;
//    refc2i['2'] = 2;
//    refc2i['3'] = 3;
//    refc2i['4'] = 4;
//    refc2i['5'] = 5;
//    refc2i['6'] = 6;
//    refc2i['7'] = 7;
//    refc2i['8'] = 8;
//    refc2i['9'] = 9;
//    vector<char> refi2c;
//    refi2c.push_back('0');
//    refi2c.push_back('1');
//    refi2c.push_back('2');
//    refi2c.push_back('3');
//    refi2c.push_back('4');
//    refi2c.push_back('5');
//    refi2c.push_back('6');
//    refi2c.push_back('7');
//    refi2c.push_back('8');
//    refi2c.push_back('9');
//    stack<int> st;
//
//    int adv = 0;
//    while (!num1.empty() || !num2.empty() || adv != 0) {
//        int a = 0, b = 0;
//        if (!num1.empty()) {
//            a = refc2i[num1.back()];
//            num1.pop_back();
//        }
//        if (!num2.empty()) {
//            b = refc2i[num2.back()];
//            num2.pop_back();
//        }
//        st.push((a + b + adv) % 10);
//        adv = (a + b + adv) / 10;
//    }
//
//    while (!st.empty()) {
//        rslt.push_back(refi2c[st.top()]);
//        st.pop();
//    }
//
//    return rslt;
//}

/*
    解法1：使用两个栈
    缺点：时空复杂度都很高
    知识点：
        1. stack将char推入后，类型是const char
*/
//string addStrings(string num1, string num2) {
//    string rslt;
//
//    map<char, int> refc2i;
//    refc2i['0'] = 0;
//    refc2i['1'] = 1;
//    refc2i['2'] = 2;
//    refc2i['3'] = 3;
//    refc2i['4'] = 4;
//    refc2i['5'] = 5;
//    refc2i['6'] = 6;
//    refc2i['7'] = 7;
//    refc2i['8'] = 8;
//    refc2i['9'] = 9;
//    /*map<int, char> refi2c;
//    refi2c[0] = '0';
//    refi2c[1] = '1';
//    refi2c[2] = '2';
//    refi2c[3] = '3';
//    refi2c[4] = '4';
//    refi2c[5] = '5';
//    refi2c[6] = '6';
//    refi2c[7] = '7';
//    refi2c[8] = '8';
//    refi2c[9] = '9';*/
//    vector<char> refi2c;
//    refi2c.push_back('0');
//    refi2c.push_back('1');
//    refi2c.push_back('2');
//    refi2c.push_back('3');
//    refi2c.push_back('4');
//    refi2c.push_back('5');
//    refi2c.push_back('6');
//    refi2c.push_back('7');
//    refi2c.push_back('8');
//    refi2c.push_back('9');
//
//    stack<char> s1, s2;
//    for (int i = 0; i < num1.size(); i++) {
//        s1.push(num1[i]);
//    }
//    for (int i = 0; i < num2.size(); i++) {
//        s2.push(num2[i]);
//    }
//    int adv = 0; //进位
//    while (!s1.empty() || !s2.empty() || adv != 0) {
//        int a = 0, b = 0;
//        if (!s1.empty()) {
//            a = refc2i[s1.top()];
//            s1.pop();
//        }
//        if (!s2.empty()) {
//            b = refc2i[s2.top()];
//            s2.pop();
//        }
//        rslt.insert(0, 1, refi2c[(a + b + adv) % 10]);
//        adv = (a + b + adv) / 10;
//    }
//
//    return rslt;
//}