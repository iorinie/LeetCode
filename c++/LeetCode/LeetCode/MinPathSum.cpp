#include "MinPathSum.h"

/*
    ��Ŀ������
        ����һ�������Ǹ������� m x n �������ҳ�һ�������Ͻǵ����½ǵ�·����ʹ��·���ϵ������ܺ�Ϊ��С��

    ˵����ÿ��ֻ�����»��������ƶ�һ����

    ʾ����
        ����:
        [
          [1,3,1],
          [1,5,1],
          [4,2,1]
        ]
        ���: 7
        ����: ��Ϊ·�� 1��3��1��1��1 ���ܺ���С��
*/

/*
    �ⷨ2����̬�滮�����Ժ�A���㷨�Ƚϣ�
    ȱ�㣺
    ֪ʶ�㣺
        1.
*/
int minPathSum(vector<vector<int>>& grid) {
    int rslt = 0;
    


    return rslt;
}

/*
    �ⷨ1������
    ȱ�㣺�ύ��ʱ
    ֪ʶ�㣺
        1. 
*/
//int minPathSum(vector<vector<int>>& grid) {
//    int rslt = numeric_limits<int>::max();
//    int tempSum = 0;
//
//    tempSum += grid[0][0];
//    rslt = findPath(rslt, tempSum, grid, 0, 0);
//
//    return rslt;
//}
//
//int findPath(int rslt, int tempSum, vector<vector<int>>& grid, int startH, int startV) {
//    if (startH == grid.size() - 1 && startV == grid[0].size() - 1) {
//        return tempSum;
//    }
//
//    int nextH = startH;
//    int nextV = startV;
//    //ѡ����һ������
//    if (nextV < grid[nextH].size() - 1) { //���������ߣ���������
//        nextV++;
//        int temp = findPath(rslt, tempSum + grid[nextH][nextV], grid, nextH, nextV);
//        rslt = rslt >= temp ? temp : rslt;
//        nextV--;
//    }
//    if (nextH < grid.size() - 1) { //���������ߣ���������
//        nextH++;
//        int temp = findPath(rslt, tempSum + grid[nextH][nextV], grid, nextH, nextV);
//        rslt = rslt >= temp ? temp : rslt;
//        nextH--;
//    }
//
//    return rslt;
//}