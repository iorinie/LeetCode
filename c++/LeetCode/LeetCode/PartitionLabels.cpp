#include "PartitionLabels.h"
#include <map>

/*
    ��Ŀ������
        �ַ��� S ��Сд��ĸ��ɡ�����Ҫ������ַ�������Ϊ�����ܶ��Ƭ�Σ�ͬһ����ĸֻ����������е�һ��Ƭ�Ρ�����һ����ʾÿ���ַ���Ƭ�εĳ��ȵ��б�

    ʾ��1��
        ���룺S = "ababcbacadefegdehijhklij"
        �����[9,7,8]
        ���ͣ�
            1. ���ֽ��Ϊ "ababcbaca", "defegde", "hijhklij"��
            2. ÿ����ĸ��������һ��Ƭ���С�
            3. �� "ababcbacadefegde", "hijhklij" �Ļ����Ǵ���ģ���Ϊ���ֵ�Ƭ�������١�

    ��ʾ��
        1. S�ĳ�����[1, 500]֮�䡣
        2. Sֻ����Сд��ĸ 'a' �� 'z' ��
*/
/*
    �ⷨ2��
    ȱ�㣺��¼ÿ���ַ����ֵ�����±꣬����
    ֪ʶ�㣺
        1. �ر�ע�������˵���ַ���Χ������ת��Ϊ����洢
        2. ��һ�α����������ظ�����
*/
vector<int> partitionLabels(string S) {
    vector<int> rslt;

    int sLen = S.size();
    int cache[26];
    for (int i = 0; i < sLen; i++) {
        cache[S[i] - 'a'] = i;
    }
    int start = 0, end = 0;
    for (int i = 0; i < sLen; i++) {
        end = end > cache[S[i] - 'a'] ? end : cache[S[i] - 'a'];
        if (i == end) {
            rslt.push_back(end - start + 1);
            start = end + 1;
        }
    }

    return rslt;
}

/*
    �ⷨ1��
    ȱ�㣺�ܶ��ظ����㣬ʱ�ո��Ӷ�̫��
    ֪ʶ�㣺
        1.
*/
//vector<int> partitionLabels(string S) {
//    vector<int> rslt;
//
//    int sLen = S.size();
//    if (sLen == 1) {
//        rslt.push_back(1);
//        return rslt;
//    }
//    int left = 0;
//    while (left < sLen) {
//        int oriLeft = left;
//        int right = sLen - 1;
//        while (S[right] != S[left]) right--;
//        map<char, bool> m;
//        while (left != right && left != right - 1) {
//            for (int i = left; i < right; i++) {
//                m[S[i]] = true;
//            }
//            left = right;
//            right = sLen - 1;
//            while (!m[S[right]]) right--;
//        }
//        left = right + 1;
//        rslt.push_back(left - oriLeft);
//    }
//
//    return rslt;
//}