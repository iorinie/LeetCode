#include "MovingCount.h"
#include <vector>

using namespace std;

/*
    ��Ŀ������
        ������һ��m��n�еķ��񣬴����� [0,0] ������ [m-1,n-1] ��
        һ�������˴����� [0, 0] �ĸ��ӿ�ʼ�ƶ�����ÿ�ο��������ҡ��ϡ����ƶ�һ�񣨲����ƶ��������⣩��Ҳ���ܽ�������������������λ֮�ʹ���k�ĸ��ӡ�
        ���磬��kΪ18ʱ���������ܹ����뷽�� [35, 37] ����Ϊ3+5+3+7=18���������ܽ��뷽�� [35, 38]����Ϊ3+5+3+8=19�����ʸû������ܹ�������ٸ����ӣ�

    ʾ��1��
        ���룺m = 2, n = 3, k = 1
        �����3

    ʾ��2��
        ���룺m = 3, n = 1, k = 0
        �����1

    ʾ��3��
        ���룺m = 1, n = 2, k = 1
        �����2

    ��ʾ��
        1. 1 <= n,m <= 100
        2. 0 <= k <= 20
*/
/*
    �ⷨ2��������ȱ�����ȥ����������ķ�֧�����Ҹ��ĸ��������ķ�������
    ȱ�㣺
    ֪ʶ�㣺
        1.
*/
int movingCount(int m, int n, int k) {
    vector<vector<int>> visited(m, vector<int>(n));

    return dfs(m, n, k, 0, 0, visited);
}

int dfs(int m, int n, int k, int r, int c, vector<vector<int>>& visited) {
    if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] || (r / 10 + r % 10 + c / 10 + c % 10 > k)) {
        return 0;
    }

    visited[r][c] = 1;

    return 1 + dfs(m, n, k, r + 1, c, visited) + dfs(m, n, k, r, c + 1, visited);
}

/*
    �ⷨ1��������ȱ�����
    ȱ�㣺ʱ�ո��Ӷ���ô�ߣ�
    ֪ʶ�㣺
        1.
*/
//int rslt;
//
//vector<vector<int>> visited;
//
//int movingCount(int m, int n, int k) {
//    rslt = 0;
//    for (int i = 0; i < m; i++) {
//        vector<int> tempV;
//        for (int j = 0; j < n; j++) {
//            tempV.push_back(0);
//        }
//        visited.push_back(tempV);
//    }
//
//    dfs(m, n, k, 0, 0);
//
//    return rslt;
//}
//
//void dfs(int m, int n, int k, int r, int c) {
//    if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] || (r / 10 + r % 10 + c / 10 + c % 10 > k)) {
//        return;
//    }
//
//    visited[r][c] = 1;
//    rslt++;
//
//    dfs(m, n, k, r - 1, c);
//    dfs(m, n, k, r + 1, c);
//    dfs(m, n, k, r, c - 1);
//    dfs(m, n, k, r, c + 1);
//}