#include "Multiply.h"
#include <vector>

/*
    题目描述：
        给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

    示例1：
        输入: num1 = "2", num2 = "3"
        输出: "6"

    示例1：
        输入: num1 = "123", num2 = "456"
        输出: "56088"

    说明：
        1. num1 和 num2 的长度小于110。
        2. num1 和 num2 只包含数字 0-9。
        3. num1 和 num2 均不以零开头，除非是数字 0 本身。
        4. 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
*/
/*
    解法1：看注释
    缺点：时空复杂度高，特别是空间复杂度，辅助二维数组可以简化为数组
    知识点：
        1.
*/
string multiply(string num1, string num2) {
    string rslt;

    int len1 = num1.size(), len2 = num2.size();
    //模仿中国乘法计算方法设置二维数组
    vector<vector<int>> vec(len2, vector<int>(len1 + len2, 0));
    for (int j = len2 - 1; j >= 0; j--) {
        int carry = 0;
        int num2Int = num2[j] - '0';
        int startEnd = len2 - 1 - j;
        for (int i = len1 - 1; i >= 0; i--) {
            int num1Int = num1[i] - '0';
            vec[len2 - j - 1][len1 + len2 - 1 -startEnd] = (num2Int * num1Int) % 10 + carry;
            carry = (num2Int * num1Int) / 10;
            startEnd++;
        }
        if (carry > 0) {
            vec[len2 - j - 1][len1 + len2 - 1 - startEnd] = carry;
        }
    }
    //二维数组按位相加
    int carry = 0;
    for (int j = len1 + len2 - 1; j >= 0; j--) {
        int sum = carry;
        for (int i = 0; i < len2; i++) {
            sum += vec[i][j];
        }
        rslt += to_string(sum % 10);
        carry = sum / 10;
    }
    if (carry > 0) {
        rslt += to_string(carry);
    }
    //干掉最后面的0
    for (int i = rslt.size() - 1; i >= 0; i--) {
        if (rslt[i] != '0') {
            break;
        }
        if (i == 0) {
            break;
        }
        rslt.erase(rslt.end() - 1);
    }
    reverse(rslt.begin(), rslt.end());

    return rslt;
}