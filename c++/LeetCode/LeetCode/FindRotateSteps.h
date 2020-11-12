#include <string>

using namespace std;

#ifndef FINDROTATESTEPS_H

#define FINDROTATESTEPS_H

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int findRotateSteps(string ring, string key);

//int dfs(string& ring, string& key, int clockIdx, int tarIdx);

void dfs(string& ring, string& key, int clockIdx, int tarIdx, TreeNode* node);

int calMinVal(TreeNode* root);

#endif // !FINDROTATESTEPS_H
