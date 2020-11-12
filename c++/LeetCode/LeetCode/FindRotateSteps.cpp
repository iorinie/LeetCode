#include "FindRotateSteps.h"
#include <algorithm>
#include <map>

/*
    题目描述：
        视频游戏“辐射4”中，任务“通向自由”要求玩家到达名为“Freedom Trail Ring”的金属表盘，并使用表盘拼写特定关键词才能开门。
        给定一个字符串 ring，表示刻在外环上的编码；给定另一个字符串 key，表示需要拼写的关键词。您需要算出能够拼写关键词中所有字符的最少步数。
        最初，ring 的第一个字符与12:00方向对齐。您需要顺时针或逆时针旋转 ring 以使 key 的一个字符在 12:00 方向对齐，然后按下中心按钮，以此逐个拼写完 key 中的所有字符。
        旋转 ring 拼出 key 字符 key[i] 的阶段中：
        您可以将 ring 顺时针或逆时针旋转一个位置，计为1步。旋转的最终目的是将字符串 ring 的一个字符与 12:00 方向对齐，并且这个字符必须等于字符 key[i] 。
        如果字符 key[i] 已经对齐到12:00方向，您需要按下中心按钮进行拼写，这也将算作 1 步。按完之后，您可以开始拼写 key 的下一个字符（下一阶段）, 直至完成所有拼写。

    示例1：
        输入：ring = "godding", key = "gd"
        输出：4
        解释：
            对于 key 的第一个字符 'g'，已经在正确的位置, 我们只需要1步来拼写这个字符。 
            对于 key 的第二个字符 'd'，我们需要逆时针旋转 ring "godding" 2步使它变成 "ddinggo"。
            当然, 我们还需要1步进行拼写。
            因此最终的输出是 4。

    提示：
        1. ring 和 key 的字符串长度取值范围均为 1 至 100；
        2. 两个字符串中都只有小写字符，并且均可能存在重复字符；
        3. 字符串 key 一定可以由字符串 ring 旋转拼出。
*/
/*
    解法2：建立树+备忘录剪枝
    缺点：时间复杂度还是太高，应该用动态规划
    知识点：
        1.
*/
map<pair<int, char>, pair<int, int>> cache1; //某个下标为12点时，找某个字符的下一个12点下标分别是多少
map<pair<int, char>, pair<int, int>> cache2; //某个下标为12点时，找某个字符的步数分别是多少

int findRotateSteps(string ring, string key) {
    TreeNode* root = new TreeNode(0);
    dfs(ring, key, 0, 0, root);

    return calMinVal(root);
}

void dfs(string& ring, string& key, int clockIdx, int tarIdx, TreeNode* node) {
    if (tarIdx == key.size()) return;

    if (ring[clockIdx] == key[tarIdx]) {
        TreeNode* newLeft = new TreeNode(1);
        node->left = newLeft;
        dfs(ring, key, clockIdx, tarIdx + 1, newLeft);

        return;
    }

    if (cache2[{clockIdx, key[tarIdx]}].first) {
        if (cache2[{clockIdx, key[tarIdx]}].second) {
            TreeNode* newLeft = new TreeNode(cache2[{clockIdx, key[tarIdx]}].first);
            TreeNode* newRight = new TreeNode(cache2[{clockIdx, key[tarIdx]}].second);
            node->left = newLeft;
            node->right = newRight;
            dfs(ring, key, cache1[{clockIdx, key[tarIdx]}].first, tarIdx + 1, newLeft);
            dfs(ring, key, cache1[{clockIdx, key[tarIdx]}].second, tarIdx + 1, newRight);

            return;
        }
        TreeNode* newLeft = new TreeNode(cache2[{clockIdx, key[tarIdx]}].first);
        node->left = newLeft;
        dfs(ring, key, cache1[{clockIdx, key[tarIdx]}].first, tarIdx + 1, newLeft);

        return;
    }

    int leftStep = 0, rightStep = 0;
    int leftIdx = clockIdx, rightIdx = clockIdx;
    bool isLeftOF = false, isRightOF = false;
    while (ring[leftIdx] != key[tarIdx]) {
        leftStep++;
        if (leftStep > ring.size() / 2) {
            isLeftOF = true;
            break;
        }
        leftIdx--;
        if (leftIdx < 0) leftIdx += ring.size();
    }
    while (ring[rightIdx] != key[tarIdx]) {
        rightStep++;
        if (rightStep > ring.size() / 2) {
            isRightOF = true;
            break;
        }
        rightIdx++;
        if (rightIdx >= ring.size()) rightIdx = 0;
    }
    if (leftIdx == rightIdx) {
        cache1[{clockIdx, key[tarIdx]}].first = leftIdx;
        cache2[{clockIdx, key[tarIdx]}].first = min(leftStep, rightStep) + 1;
        TreeNode* newNode = new TreeNode(min(leftStep, rightStep) + 1);
        node->left = newNode;
        dfs(ring, key, leftIdx, tarIdx + 1, newNode);

        return;
    }
    if (isLeftOF) {
        cache1[{clockIdx, key[tarIdx]}].first = rightIdx;
        cache2[{clockIdx, key[tarIdx]}].first = rightStep + 1;
        TreeNode* newNode = new TreeNode(rightStep + 1);
        node->left = newNode;
        dfs(ring, key, rightIdx, tarIdx + 1, newNode);

        return;
    }
    else if (isRightOF) {
        cache1[{clockIdx, key[tarIdx]}].first = leftIdx;
        cache2[{clockIdx, key[tarIdx]}].first = leftStep + 1;
        TreeNode* newNode = new TreeNode(leftStep + 1);
        node->left = newNode;
        dfs(ring, key, leftIdx, tarIdx + 1, newNode);

        return;
    }
    cache1[{clockIdx, key[tarIdx]}].first = leftIdx;
    cache1[{clockIdx, key[tarIdx]}].second = rightIdx;
    cache2[{clockIdx, key[tarIdx]}].first = leftStep + 1;
    cache2[{clockIdx, key[tarIdx]}].second = rightStep + 1;
    TreeNode* newLeft = new TreeNode(leftStep + 1);
    TreeNode* newRight = new TreeNode(rightStep + 1);
    node->left = newLeft;
    node->right = newRight;
    dfs(ring, key, leftIdx, tarIdx + 1, newLeft);
    dfs(ring, key, rightIdx, tarIdx + 1, newRight);
}

int calMinVal(TreeNode* node) {
    if (!node->left && !node->right) return node->val;

    int sum = calMinVal(node->left);
    if (node->right) sum = min(sum, calMinVal(node->right));

    return node->val + sum;
}

/*
    解法1：双指针二分法
    缺点：超时严重
    知识点：
        1.
*/
//int findRotateSteps(string ring, string key) {
//    return dfs(ring, key, 0, 0);
//}
//
//int dfs(string& ring, string& key, int clockIdx, int tarIdx) {
//    if (tarIdx == key.size()) return 0;
//
//    if (ring[clockIdx] == key[tarIdx]) {
//        return dfs(ring, key, clockIdx, tarIdx + 1) + 1;
//    }
//
//    int leftStep = 0, rightStep = 0;
//    int leftIdx = clockIdx, rightIdx = clockIdx;
//    while (ring[leftIdx] != key[tarIdx]) {
//        leftStep++;
//        leftIdx--;
//        if (leftIdx < 0) leftIdx += ring.size();
//    }
//    while (ring[rightIdx] != key[tarIdx]) {
//        rightStep++;
//        rightIdx++;
//        if (rightIdx >= ring.size()) rightIdx = 0;
//    }
//    if (leftIdx == rightIdx) {
//        return dfs(ring, key, leftIdx, tarIdx + 1) + min(leftStep, rightStep) + 1;
//    }
//
//    return min(dfs(ring, key, leftIdx, tarIdx + 1) + leftStep + 1, dfs(ring, key, rightIdx, tarIdx + 1) + rightStep + 1);
//}