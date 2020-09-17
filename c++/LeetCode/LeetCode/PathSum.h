#include <vector>

using namespace std;

#ifndef PATHSUM_H

#define PATHSUM_H

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> pathSum(TreeNode* root, int sum);

void dfs(vector<vector<int>>& rslt, vector<int>& path, TreeNode* node, int tempSun, int targetSum);

#endif // !PATHSUM_H
