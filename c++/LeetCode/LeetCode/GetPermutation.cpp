#include "GetPermutation.h"

/*
    ��Ŀ������
        �������� [1,2,3,��,n]��������Ԫ�ع��� n! �����С�
        ����С˳���г����������������һһ��ǣ��� n = 3 ʱ, �����������£�
        1. "123"
        2. "132"
        3. "213"
        4. "231"
        5. "312"
        6. "321"
        ���� n �� k�����ص� k �����С�

    ˵����
        1. ���� n �ķ�Χ�� [1, 9]��
        2. ���� k �ķ�Χ��[1,  n!]��

    ʾ��1��
        ���룺n = 3, k = 3
        �����"213"

    ʾ��2��
        ���룺n = 4, k = 9
        �����"2314"

    ʾ��3��
        ���룺n = 8, k = 33856
        �����"?"
*/
/*
    �ⷨ2����ѧ���ɷ������˰ɣ�Ҫ��ֵ�
    ȱ�㣺
    ֪ʶ�㣺
        1.
*/
//string getPermutation(int n, int k) {
//
//}

/*
    �ⷨ1������
    ȱ�㣺��ʱ�����ϼ�֦���������������뵽�ķ���
    ֪ʶ�㣺
        1. string��Ϊ��������ʱ����ֵ�����������Ҫ�ı���ֵ����Ҫ����ַ��ȥ
*/
vector<int> factorial; //�׳���Ϣ

vector<int> visited; //ĳ�������Ƿ��Ѿ����ʹ�

string getPermutation(int n, int k) {
    string rslt;

    factorial.push_back(1);
    for (int i = 1; i <= n; i++) {
        factorial.push_back(factorial[i - 1] * i);
    }
    for (int i = 0; i < n; i++) {
        visited.push_back(false);
    }
    vector<int> tempV;
    recurse(n, k, rslt, tempV);
    rslt = "";
    for (int i = 0; i < tempV.size(); i++) {
        rslt += tempV[i] + '0';
    }

    return rslt;
}

void recurse(int n, int k, string& rslt, vector<int>& tempV) {
    if (tempV.size() == n) {
        return;
    }

    int cnt = factorial[n - 1 - tempV.size()];
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;
        if (cnt < k) {
            k -= cnt;
            continue;
        }
        tempV.push_back(i + 1);
        visited[i] = true;
        recurse(n, k, rslt, tempV);

        return; //����ֱ�ӷ��غ���Ҫ
    }
}