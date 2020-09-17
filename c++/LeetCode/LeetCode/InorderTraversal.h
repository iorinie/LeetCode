#include <vector>

using namespace std;

#ifndef INORDERTRAVERSAL_H

#define INORDERTRAVERSAL_H

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root);

//void traversal(TreeNode* node, vector<int>& rslt);

#endif
