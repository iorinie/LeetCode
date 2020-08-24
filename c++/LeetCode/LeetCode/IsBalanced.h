#include <iostream>

#ifndef ISBALANCED_H

#define ISBALANCED_H

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isBalanced(TreeNode* node);

bool recordDepth(TreeNode* node);

#endif // !ISBALANCED_H
