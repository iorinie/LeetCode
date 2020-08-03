#include <vector>

using namespace std;

#ifndef GENERATETREES_H

#define GENERATETREES_H

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<TreeNode*> generateTrees(int n);

void selectBinarySearchTreeNode(vector<TreeNode*>& rslt, vector<int>& source, vector<int>& path);

TreeNode* buildBinarySearchTree(vector<int>& path);

#endif // !GENERATETREES_H
