#include "FindItinerary.h"

/*
    ��Ŀ������
        ����һ����Ʊ���ַ�����ά���� [from, to]���������е�������Ա�ֱ��ʾ�ɻ������ͽ���Ļ����ص㣬�Ը��г̽������¹滮����
        ������Щ��Ʊ������һ���� JFK������Ϲ��ʻ��������������������Ը��г̱���� JFK ��ʼ��

    ˵����
        1. ������ڶ�����Ч���г̣�����԰��ַ���Ȼ���򷵻���С���г���ϡ����磬�г� ["JFK", "LGA"] �� ["JFK", "LGB"] ��Ⱦ͸�С���������ǰ
        2. ���еĻ�������������д��ĸ��ʾ���������룩��
        3. �ٶ����л�Ʊ���ٴ���һ�ֺ�����г̡�

    ʾ��1��
        ���룺[["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
        �����["JFK", "MUC", "LHR", "SFO", "SJC"]

    ʾ��2��
        ���룺[["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
        �����["JFK","ATL","JFK","SFO","ATL","SFO"]
        ���ͣ���һ����Ч���г��� ["JFK","SFO","ATL","JFK","ATL","SFO"]����������Ȼ������������

    ʾ��3��
        ���룺[["EZE","AXA"],["TIA","ANU"],["ANU","JFK"],["JFK","ANU"],["ANU","EZE"],["TIA","ANU"],["AXA","TIA"],["TIA","JFK"],["ANU","TIA"],["JFK","TIA"]]
*/
/*
    �ⷨ2����̬�滮��ŷ��ͨ·��
    ȱ�㣺
    ֪ʶ�㣺
        1. 
*/
vector<string> findItinerary(vector<vector<string>>& tickets) {
    vector<string> rslt;

    

    return rslt;
}

/*
    �ⷨ1������
    ȱ�㣺��ʱ
    ֪ʶ�㣺
        1. ������Ϊ�������ݵ����������Զ��˻�Ϊָ��
        2. �����ʼ��ʱ������ֻ��Ϊ����
*/
//vector<string> findItinerary(vector<vector<string>>& tickets) {
//    vector<string> rslt;
//
//    vector<string> path; //��ѡ����г�
//    path.push_back("JFK");
//    vector<bool> visited; //ticketsĳ���±��Ƿ��ѷ���
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
//        if (rslt.size() > 0) { //ȡrslt��path���ַ���Ȼ�����С����Ϊ���
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
//        //��һ��ѡ��
//        if (visited[i] || tickets[i][0] != path.back()) { //�Ѿ���ѡ����ˣ����߲����ϳ����ص㣬����
//            continue;
//        }
//        path.push_back(tickets[i][1]);
//        visited[i] = true;
//        recurse(tickets, rslt, path, visited);
//        //�������ѡ��
//        path.pop_back();
//        visited[i] = false;
//    }
//}