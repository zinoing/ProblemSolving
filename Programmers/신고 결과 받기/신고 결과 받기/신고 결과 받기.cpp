// 신고 결과 받기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

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
    vector<int> reportedCnt(id_list.size());
    vector<int> receivedMailCnt(id_list.size());
    vector<vector<string>> reportedBy(id_list.size());

    for (string reportDetail : report) {
        vector<string> seperatedStr = separate(reportDetail);
        string reporter = seperatedStr[0];
        string reported = seperatedStr[1];

        // find the reporter
        for (int t = 0; t < id_list.size(); t++) {
            if (id_list[t] == reported) {
                // 이미 신고한 사람인지 아닌지 확인
                if (find(reportedBy[t].begin(), reportedBy[t].end(), reporter) == reportedBy[t].end()) {
                    ++reportedCnt[t];
                    reportedBy[t].push_back(reporter);
                }
                break;
            }
        }
    }

    vector<int> answer(id_list.size());

    for (int i = 0; i < reportedCnt.size(); i++) {

        if (reportedCnt[i] >= k) {
            for (int j = 0; j < reportedBy[i].size(); j++) {
                string reporter = reportedBy[i][j];

                // find the reporter
                for (int t = 0; t < id_list.size(); t++) {
                    if (reporter == id_list[t]) {
                        ++answer[t];
                        break;
                    }
                }
            }
        }
    }

    return answer;
}
