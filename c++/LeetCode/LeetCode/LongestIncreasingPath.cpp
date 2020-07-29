#include "LongestIncreasingPath.h"

/*
    题目描述：
        给定一个整数矩阵，找出最长递增路径的长度。
        对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。

    示例1：
        输入: nums = 
        [
          [9,9,4],
          [6,6,8],
          [2,1,1]
        ] 
        输出: 4 
        解释: 最长递增路径为 [1, 2, 6, 9]。

    示例2：
        输入: nums = 
        [
          [3,4,5],
          [3,2,6],
          [2,2,1]
        ] 
        输出: 4 
        解释: 最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
*/

/*
    解法2：动态规划？优先队列？
    缺点：

    知识点：
        1.
*/
int longestIncreasingPath(vector<vector<int>>& matrix) {

}


/*
    解法1：遍历整个二维数组，递归，符合条件就走一步，返回某个几点能够往后走的最大步数
    缺点：超时 超时 超时，有很多重复的判断。增加hist备忘录后，时间复杂度尚可，但是内存消耗过多。将二维备忘录变为一维，消耗内存变化不大。

    知识点：
        1. 
*/
int longestIncreasingPath(vector<vector<int>>& matrix) {
    int max = 0;

    if (matrix.size() == 0) {
        return max;
    }
    //vector<vector<int>> hist(matrix.size(), vector<int>(matrix[0].size(), -1));
    vector<int> hist(matrix.size() * matrix[0].size(), -1);
    for (int r = 0; r < matrix.size(); r++) {
        for (int c = 0; c < matrix[r].size(); c++) {
            int tempStep = takeAStep(matrix, hist, r, c);
            max = max >= tempStep ? max : tempStep;
        }
    }

    return max;
}

//int takeAStep(vector<vector<int>>& matrix, vector<vector<int>>& hist, int startR, int startC) {
int takeAStep(vector<vector<int>>& matrix, vector<int>& hist, int startR, int startC) {
    int max = 0;
    if (startR - 1 >= 0 && matrix[startR - 1][startC] > matrix[startR][startC]) {
        //int tempStep = hist[startR - 1][startC];
        int tempStep = hist[(startR - 1) * matrix[startR - 1].size() + startC];
        if (tempStep == -1) {
            tempStep = takeAStep(matrix, hist, startR - 1, startC);
            //hist[startR - 1][startC] = tempStep;
            hist[(startR - 1) * matrix[startR - 1].size() + startC] = tempStep;
        }
        max = max >= tempStep ? max : tempStep;
    }
    if (startR + 1 < matrix.size() && matrix[startR + 1][startC] > matrix[startR][startC]) {
        //int tempStep = hist[startR + 1][startC];
        int tempStep = hist[(startR + 1) * matrix[startR + 1].size() + startC];
        if (tempStep == -1) {
            tempStep = takeAStep(matrix, hist, startR + 1, startC);
            //hist[startR + 1][startC] = tempStep;
            hist[(startR + 1) * matrix[startR + 1].size() + startC] = tempStep;
        }
        max = max >= tempStep ? max : tempStep;
    }
    if (startC - 1 >= 0 && matrix[startR][startC - 1] > matrix[startR][startC]) {
        //int tempStep = hist[startR][startC - 1];
        int tempStep = hist[(startR) * matrix[startR].size() + startC - 1];
        if (tempStep == -1) {
            tempStep = takeAStep(matrix, hist, startR, startC - 1);
            //hist[startR][startC - 1] = tempStep;
            hist[(startR)*matrix[startR].size() + startC - 1] = tempStep;
        }
        max = max >= tempStep ? max : tempStep;
    }
    if (startC + 1 < matrix[startR].size() && matrix[startR][startC + 1] > matrix[startR][startC]) {
        //int tempStep = hist[startR][startC + 1];
        int tempStep = hist[(startR) * matrix[startR].size() + startC + 1];
        if (tempStep == -1) {
            tempStep = takeAStep(matrix, hist, startR, startC + 1);
            //hist[startR][startC + 1] = tempStep;
            hist[(startR)*matrix[startR].size() + startC + 1] = tempStep;
        }
        max = max >= tempStep ? max : tempStep;
    }
    return max + 1; //返回当前节点能走的最大步数，因为进来就算走了1步，所以+1
}