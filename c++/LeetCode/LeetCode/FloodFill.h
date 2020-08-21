#include <vector>

using namespace std;

#ifndef FLOODFILL_H

#define FLOODFILL_H

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor);

void changeColor(vector<vector<int>>& image, vector<vector<int>>& visited, int sr, int sc, int newColor, int preColor);

#endif // !FLOODFILL_H
