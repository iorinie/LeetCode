#include <vector>

using namespace std;

#ifndef POSTORDERTRAVERSAL_H

#define POSTORDERTRAVERSAL_H

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> postorderTraversal(TreeNode* root);

#endif // !POSTORDERTRAVERSAL_H
