// LeetCode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "ValidateStackSequences.h"

using namespace std;

int main()
{
    /*vector<int> pushed = { 1,2,3,4,5 };
    vector<int> popped = { 4,5,3,2,1 };*/
    /*vector<int> pushed = { 1,2,3,4,5 };
    vector<int> popped = { 4,3,5,1,2 };*/
    /*vector<int> pushed = { 1,0 };
    vector<int> popped = { 1,0 };*/
    vector<int> pushed = { 8,9,2,3,7,0,5,4,6,1 };
    vector<int> popped = { 6,8,2,1,3,9,0,7,4,5 };
    cout << validateStackSequences(pushed, popped) << endl;

    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
