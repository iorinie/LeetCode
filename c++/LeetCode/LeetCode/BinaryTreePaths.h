#include <vector>
#include <string>

using namespace std;

#ifndef BINARYTREEPATHS_H

#define BINARYTREEPATHS_H

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<string> binaryTreePaths(TreeNode* root);

void dfs(vector<string>& rslt, string path, TreeNode* node);

#endif // !BINARYTREEPATHS_H
