#include <vector>

using namespace std;

#ifndef SHOPPINGOFFERS_H

#define SHOPPINGOFFERS_H

int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs);

void recurse(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int curPrice);

bool isNeedsEmpty(vector<int>& needs);

bool isTooMuch(vector<int>& needs, vector<int>& option);

#endif // !SHOPPINGOFFERS_H
