#include "Exist.h"

/*
    ��Ŀ������
        �����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
        ·�����ԴӾ����е�����һ��ʼ��ÿһ�������ھ����������ҡ��ϡ����ƶ�һ��
        ���һ��·�������˾����ĳһ����ô��·�������ٴν���ø��ӡ�
        ���磬�������3��4�ľ����а���һ���ַ�����bfce����·����·���е���ĸ�üӴֱ������

        [["a","b","c","e"],
        ["s","f","c","s"],
        ["a","d","e","e"]]

        �������в������ַ�����abfb����·������Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���������ӡ�

    ʾ��1��
        ���룺board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
        �����true

    ʾ��2��
        ���룺board = [["a","b"],["c","d"]], word = "abcd"
        �����false
*/
/*
    �ⷨ1�����ݣ�
    ȱ�㣺ʱ�ո��Ӷ��е�
    ֪ʶ�㣺
        1. 
*/
bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == word[0]) {
                if (exist(board, word, i, j, 0))
                    return true;
            }
        }
    }
    return false;
}

bool exist(vector<vector<char>>& board, string word, int curR, int curC, int curTarIdx) {
    if (curTarIdx >= word.size()) {
        return true;
    }

    if (curR < 0 || curR >= board.size() || curC < 0 || curC >= board[curR].size() || board[curR][curC] == '.' || board[curR][curC] != word[curTarIdx]) {
        return false;
    }

    char tempC = board[curR][curC];
    board[curR][curC] = '.';
    bool rslt = exist(board, word, curR - 1, curC, curTarIdx + 1) || exist(board, word, curR + 1, curC, curTarIdx + 1) ||
        exist(board, word, curR, curC - 1, curTarIdx + 1) || exist(board, word, curR, curC + 1, curTarIdx + 1);

    board[curR][curC] = tempC;

    return rslt;
}