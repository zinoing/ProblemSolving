// 신고 결과 받기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

vector<string> separate(string str) {
    vector<string> vec;
    string temp = "";

    for (char c : str) {
        if (c == ' ') {
            if (!temp.empty()) {
                vec.push_back(temp);
                temp = "";
            }
        }
        else {
            temp += c;
        }
    }
    if (!temp.empty()) {
        vec.push_back(temp);
    }

    return vec;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {

    int n = id_list.size();

    unordered_map<string, int> reportedCnt;
    unordered_map<string, set<string>> reportedBy;
    unordered_map<string, int> receivedMailCnt;

    for (string id : id_list) {
        reportedCnt.insert(make_pair(id, 0));
        set<string> newSet;
        reportedBy.insert(make_pair(id, newSet));
        receivedMailCnt.insert(make_pair(id, 0));
    }

    for (string reportDetail : report) {
        vector<string> seperatedStr = separate(reportDetail);
        string reporter = seperatedStr[0];
        string reported = seperatedStr[1];

        // find the reporter
        set<string> reporters = reportedBy.find(reported)->second;

        if (find(reporters.begin(), reporters.end(), reporter) != reporters.end()) continue;

        reportedBy.find(reported)->second.insert(reporter);
        ++reportedCnt.find(reported)->second;
    }

    for (auto iter : reportedCnt) {
        string reported = iter.first;
        int cnt = iter.second;

        if (cnt >= k) {
            for (auto reporter : reportedBy.find(reported)->second) {
                ++receivedMailCnt.find(reporter)->second;
            }
        }
    }

    vector<int> answer;

    for (int i = 0; i < n; i++) {
        string id = id_list[i];

        answer.push_back(receivedMailCnt.find(id)->second);
    }

    return answer;
}

int main() {
    vector<string> id_list = { "muzi", "frodo", "apeach", "neo" };
    vector<string> report = {"muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"};
    int k = 2;

    solution(id_list, report, k);

    return 0;
}