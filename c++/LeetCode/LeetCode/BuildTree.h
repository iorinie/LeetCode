#include <vector>

using namespace std;

#ifndef BUILDTREE_H

#define BUILDTREE_H

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);

TreeNode* build(vector<int>& preorder, vector<int>& inorder, int rootIdx, int startInIdx, int endInIdx);

#endif // !BUILDTREE_H
