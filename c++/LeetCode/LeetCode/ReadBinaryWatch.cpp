#include "ReadBinaryWatch.h"

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
    缺点：
    知识点：
        1. 
        2. 
        3. 
*/
vector<string> readBinaryWatch(int num) {
    vector<string> rslt;
    if (num == 0) {
        rslt.push_back("0:00");
        return rslt;
    }
    vector<int> watch; //记录手表亮点情况，下标0~9代表从下往上、从右往左的LED，对应的值1为亮，0为不亮，
    for (int i = 0; i < 10; i++) {
        watch.push_back(0);
    }
    for (int i = 0; i < num; i++) {
        lightUpOne(watch, i, num, rslt);
        turnOffOne(watch, i, num, rslt);
    }

    return rslt;
}

void lightUpOne(vector<int>& watch, int idx, int target, vector<string>& rslt) {
    if (lightedCnt(watch) == target) {

    }
}

void turnOffOne(vector<int>& watch, int idx, int target, vector<string>& rslt) {

}

//手表有几个LED亮了
int lightedCnt(vector<int>& watch) {
    int cnt = 0;
    for (int i = 0; i < watch.size(); i++) {
        if (watch[i] == 1) {
            cnt++;
        }
    }
    return cnt;
}

string buildTime(int hour, int minute) {
    string hStr = to_string(hour);
    string mStr = to_string(minute);
    string hmStr = minute / 10 > 0 ? hStr + ":" + mStr : hStr + ":" + "0" + mStr;

    return hmStr;
}