#include<iostream>

#ifndef MINDEPTH_H

#define MINDEPTH_H

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode* root);

#endif // !MINDEPTH_H