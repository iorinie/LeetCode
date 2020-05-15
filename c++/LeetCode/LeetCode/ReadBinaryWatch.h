#include <vector>
#include <string>

using namespace std;

#ifndef READBINARYWATCH_H

#define READBINARYWATCH_H

vector<string> readBinaryWatch(int num);

void backtrack(vector<int>& path, vector<int>& leds, int start, int num, vector<string>& rslt);

string buildTime(vector<int>& path);

#endif