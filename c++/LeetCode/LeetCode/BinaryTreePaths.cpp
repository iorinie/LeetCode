#include "BinaryTreePaths.h"

/*
    ��Ŀ������
        ����һ������ n������������ 1 ... n Ϊ�ڵ�����ɵ� ���������� ��

    ʾ����
        ���룺
            1
           / \
          2   3
           \
            5

        �����["1->2->5", "1->3"]

        ���ͣ����и��ڵ㵽Ҷ�ӽڵ��·��Ϊ: 1->2->5, 1->3
*/
/*
    �ⷨ1�������������������Ҷ�ӽ���¼���
    ȱ�㣺ʱ�临�Ӷ��е�ߣ��͵���string.substr()�й�ϵ������ͨ�������߼���ʽ�����������
    ֪ʶ�㣺
        1. ע������ر���ʾ��Ҷ�ӽ��Ķ��壬��Ҫ�ر�ע��ݹ����ֹ����
        2. +=�Ĳ��������ʽ�ұ���Ȼ���Գ���+
*/
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> rslt;
    if (!root) {
        return rslt;
    }

    string path;
    dfs(rslt, path, root);

    return rslt;
}

void dfs(vector<string>& rslt, string path, TreeNode* node) {
    path += "->" + to_string(node->val);
    if (!(node->left) && !(node->right)) {
        rslt.push_back(path.substr(2));
        return;
    }
    if (node->left)
        dfs(rslt, path, node->left);
    if (node->right)
        dfs(rslt, path, node->right);
}