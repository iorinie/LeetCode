#include <vector>

using namespace std;

#ifndef FINDMODE_H

#define FINDMODE_H

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> findMode(TreeNode* root);

void dfs(TreeNode* node);

void update(int val);

#endif // !FINDMODE_H
