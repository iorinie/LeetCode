#include <vector>

using namespace std;

#ifndef LEVELORDER_H

#define LEVELORDER_H

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root);

#endif

