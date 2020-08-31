#include "FindItinerary.h"

/*
    题目描述：
        给定一个机票的字符串二维数组 [from, to]，子数组中的两个成员分别表示飞机出发和降落的机场地点，对该行程进行重新规划排序。
        所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。

    说明：
        1. 如果存在多种有效的行程，你可以按字符自然排序返回最小的行程组合。例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前
        2. 所有的机场都用三个大写字母表示（机场代码）。
        3. 假定所有机票至少存在一种合理的行程。

    示例1：
        输入：[["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
        输出：["JFK", "MUC", "LHR", "SFO", "SJC"]

    示例2：
        输入：[["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
        输出：["JFK","ATL","JFK","SFO","ATL","SFO"]
        解释：另一种有效的行程是 ["JFK","SFO","ATL","JFK","ATL","SFO"]。但是它自然排序更大更靠后。

    示例3：
        输入：[["EZE","AXA"],["TIA","ANU"],["ANU","JFK"],["JFK","ANU"],["ANU","EZE"],["TIA","ANU"],["AXA","TIA"],["TIA","JFK"],["ANU","TIA"],["JFK","TIA"]]
*/
/*
    解法2：动态规划？欧拉通路？
    缺点：
    知识点：
        1. 
*/
vector<string> findItinerary(vector<vector<string>>& tickets) {
    vector<string> rslt;

    

    return rslt;
}

/*
    解法1：回溯
    缺点：超时
    知识点：
        1. 数组最为参数传递到函数，会自动退化为指针
        2. 数组初始化时，长度只能为常数
*/
//vector<string> findItinerary(vector<vector<string>>& tickets) {
//    vector<string> rslt;
//
//    vector<string> path; //已选择的行程
//    path.push_back("JFK");
//    vector<bool> visited; //tickets某个下标是否已访问
//    for (int i = 0; i < tickets.size(); i++) {
//        visited.push_back(false);
//    }
//    recurse(tickets, rslt, path, visited);
//
//    return rslt;
//}
//
//void recurse(vector<vector<string>>& tickets, vector<string>& rslt, vector<string>& path, vector<bool>& visited) {
//    if (path.size() == tickets.size() + 1) {
//        if (rslt.size() > 0) { //取rslt和path中字符自然排序更小的作为结果
//            int smaller = 0;
//            for (int i = 0; i < path.size(); i++) {
//                if (path[i] > rslt[i]) {
//                    break;
//                }
//                else if (path[i] < rslt[i]) {
//                    smaller = 1;
//                    break;
//                }
//            }
//            if (smaller == 1) {
//                for (int i = 0; i < path.size(); i++) {
//                    rslt[i] = path[i];
//                }
//            }
//        }
//        else {
//            for (int i = 0; i < path.size(); i++) {
//                rslt.push_back(path[i]);
//            }
//        }
//        return;
//    }
//
//    for (int i = 0; i < tickets.size(); i++) {
//        //做一个选择
//        if (visited[i] || tickets[i][0] != path.back()) { //已经被选择过了，或者不符合出发地点，跳过
//            continue;
//        }
//        path.push_back(tickets[i][1]);
//        visited[i] = true;
//        recurse(tickets, rslt, path, visited);
//        //撤销这个选择
//        path.pop_back();
//        visited[i] = false;
//    }
//}