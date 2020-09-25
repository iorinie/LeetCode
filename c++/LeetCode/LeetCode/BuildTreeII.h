#include <vector>

using namespace std;

#ifndef BUILDTREEII_H

#define BUILDTREEII_H

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTreeII(vector<int>& inorder, vector<int>& postorder);

TreeNode* buildII(vector<int>& inorder, int iStartIdx, int iEndIdx, vector<int>& postorder, int pStartIdx, int pEndIdx);

#endif // !BUILDTREEII_H