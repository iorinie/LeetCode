#include<vector>
#include<string>

using namespace std;

#ifndef LETTERCASEPERMUTATION_H

#define LETTERCASEPERMUTATION_H

vector<string> letterCasePermutation(string S);

void dfs(string s, int start, string temp, vector<string>& rslt);

//void recursion(string s, int start, int end, vector<string>& rslt);
//
//void pushStrToVec(vector<string>& rslt, string s);

#endif