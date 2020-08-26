#include <vector>
#include <string>

using namespace std;

#ifndef LETTERCOMBINATIONS_H

#define LETTERCOMBINATIONS_H

vector<string> letterCombinations(string digits);

void recurse(vector<string>& rslt, string digits, string path);

#endif // !LETTERCOMBINATIONS_H
