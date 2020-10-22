#include "PartitionLabels.h"
#include <map>

/*
    题目描述：
        字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。

    示例1：
        输入：S = "ababcbacadefegdehijhklij"
        输出：[9,7,8]
        解释：
            1. 划分结果为 "ababcbaca", "defegde", "hijhklij"。
            2. 每个字母最多出现在一个片段中。
            3. 像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。

    提示：
        1. S的长度在[1, 500]之间。
        2. S只包含小写字母 'a' 到 'z' 。
*/
/*
    解法2：
    缺点：记录每个字符出现的最大下标，遍历
    知识点：
        1. 特别注意题干中说明字符范围，可以转换为数组存储
        2. 能一次遍历，避免重复计算
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
    解法1：
    缺点：很多重复计算，时空复杂度太高
    知识点：
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