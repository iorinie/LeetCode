#include "Combine.h"

/*
    ��Ŀ������
        ������������ n �� k������ 1 ... n �����п��ܵ� k ��������ϡ�

    ʾ��1��
        ���룺n = 4, k = 2
        �����[
                  [1,2],
                  [1,3],
                  [1,4],
                  [2,3],
                  [2,4],
                  [3,4],
              ]
*/
/*
    �ⷨ2��������ö�٣�����ο�https://leetcode-cn.com/problems/combinations/solution/zu-he-by-leetcode-solution/
    ȱ�㣺
    ֪ʶ�㣺
        1. 
*/
//vector<vector<int>> combine(int n, int k) {
//
//}

/*
    �ⷨ1������֦�Ļ���
    ȱ�㣺ʱ�临�ӶȻ����е��
    ֪ʶ�㣺
        1. 
*/
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> rslt;

    vector<int> path;
    vector<int> visited(n + 1);
    recurse(n, k, rslt, path, visited);

    return rslt;
}

void recurse(int n, int k, vector<vector<int>>& rslt, vector<int>& path, vector<int>& visited) {
    if (path.size() >= k) {
        rslt.push_back(path);
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] || (path.size() > 0 && i < path.back()))
            continue;

        path.push_back(i);
        visited[i] = 1;
        recurse(n, k, rslt, path, visited);
        visited[i] = 0;
        path.pop_back();
    }
}