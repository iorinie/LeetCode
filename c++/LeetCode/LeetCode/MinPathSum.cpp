#include "MinPathSum.h"

/*
    题目描述：
        给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

    说明：每次只能向下或者向右移动一步。

    示例：
        输入:
        [
          [1,3,1],
          [1,5,1],
          [4,2,1]
        ]
        输出: 7
        解释: 因为路径 1→3→1→1→1 的总和最小。
*/

/*
    解法2：动态规划（可以和A星算法比较）
    缺点：
    知识点：
        1.
*/
int minPathSum(vector<vector<int>>& grid) {
    int rslt = 0;
    


    return rslt;
}

/*
    解法1：回溯
    缺点：提交超时
    知识点：
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
//    //选择下一个坐标
//    if (nextV < grid[nextH].size() - 1) { //可以往右走，就往右走
//        nextV++;
//        int temp = findPath(rslt, tempSum + grid[nextH][nextV], grid, nextH, nextV);
//        rslt = rslt >= temp ? temp : rslt;
//        nextV--;
//    }
//    if (nextH < grid.size() - 1) { //可以往下走，就往下走
//        nextH++;
//        int temp = findPath(rslt, tempSum + grid[nextH][nextV], grid, nextH, nextV);
//        rslt = rslt >= temp ? temp : rslt;
//        nextH--;
//    }
//
//    return rslt;
//}