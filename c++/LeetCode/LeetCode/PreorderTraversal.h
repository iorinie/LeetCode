#include <vector>

using namespace std;

#ifndef PREORDERTRAVERSAL_H

#define PREORDERTRAVERSAL_H

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode* root);

#endif
