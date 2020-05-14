#include <vector>
#include <string>

using namespace std;

#ifndef READBINARYWATCH_H

#define READBINARYWATCH_H

vector<string> readBinaryWatch(int num);

void lightUpOne(vector<int>& watch, int idx, int target, vector<string>& rslt);

void turnOffOne(vector<int>& watch, int idx, int target, vector<string>& rslt);

int lightedCnt(vector<int>& watch);

string buildTime(int hour, int minute);

#endif