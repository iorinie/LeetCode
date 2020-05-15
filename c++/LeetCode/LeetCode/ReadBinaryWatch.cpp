#include "ReadBinaryWatch.h"
#include <math.h>

/*
    题目描述：
        二进制手表顶部有 4 个 LED 代表小时（0-11），底部的 6 个 LED 代表分钟（0-59）。
        每个 LED 代表一个 0 或 1，最低位在右侧。
        0 0 1 1
        0 1 1 0 0 1
        例如，上面的二进制手表读取 “3:25”。
        给定一个非负整数 n 代表当前 LED 亮着的数量，返回所有可能的时间。

    示例：
        输入: n = 1
        返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]

    注意事项：
        1. 输出的顺序没有要求。
        2. 小时不会以零开头，比如 “01:00” 是不允许的，应为 “1:00”。
        3. 分钟必须由两位数组成，可能会以零开头，比如 “10:2” 是无效的，应为 “10:02”。
*/

/*
    解法1：回溯
    缺点：有许多明显不合法的组合，可以提前返回
    知识点：
        1. 回溯算法框架，主要是路径和选择列表，顺序遍历选择列表的元素添加到路径，递归，返回时撤销选择，另外注意结束条件
*/
vector<string> readBinaryWatch(int num) {
    vector<string> rslt;
    if (num == 0) {
        rslt.push_back("0:00");
        return rslt;
    }
    if (num >= 10) { //应该不止10以上是非法的，9也是
        return rslt;
    }
    vector<int> leds; //选择列表，0~9，代表目前可供选择的LED
    for (int i = 0; i < 10; i++) {
        leds.push_back(i);
    }
    vector<int> path; //路径，代表已经选择的LED
    backtrack(path, leds, 0, num, rslt);

    return rslt;
}

void backtrack(vector<int>& path, vector<int>& leds, int start, int num, vector<string>& rslt) {
    if (path.size() == num) {
        string s = buildTime(path);
        if (s != "") {
            rslt.push_back(s);
        }
        return;
    }

    for (int i = start; i < leds.size(); i++) {
        path.push_back(leds[i]);
        backtrack(path, leds, i + 1, num, rslt);
        path.pop_back();
    }
}


string buildTime(vector<int>& path) {
    int hour = 0;
    int minute = 0;
    for (int i = 0; i < path.size(); i++) {
        int back = path[i];
        //6~9属于小时，0~5属于分钟
        if (back >= 6 && back <= 9) {
            hour += pow(2, back - 6);
        }
        else {
            minute += pow(2, back);
        }
    }
    if (hour > 11 || minute > 59) {
        return "";
    }
    string hStr = to_string(hour);
    string mStr = to_string(minute);
    string hmStr = minute / 10 > 0 ? hStr + ":" + mStr : hStr + ":" + "0" + mStr;

    return hmStr;
}