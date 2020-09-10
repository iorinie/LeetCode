#include <iostream>

#ifndef ISSUBSTRUCTURE_H

#define ISSUBSTRUCTURE_H

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSubStructure(TreeNode* A, TreeNode* B);

bool isSame(TreeNode* A, TreeNode* B);

#endif // !ISSUBSTRUCTURE_H