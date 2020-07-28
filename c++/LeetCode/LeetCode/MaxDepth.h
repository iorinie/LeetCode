#include <vector>

using namespace std;

#ifndef MAXDEPTH_H

#define MAXDEPTH_H

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root);

#endif // !1
