#include <iostream>

#ifndef ISBALANCED_H

#define ISBALANCED_H

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct MultpRtn {
	bool isB;
	int depth;
};

bool isBalanced(TreeNode* node);

MultpRtn isBST(TreeNode* node);

#endif // !ISBALANCED_H