// 여행경로.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> answer;

void dfs(vector<vector<string>> tickets, vector<string> pathes, string departure) {
    // 주어진 모든 항공권을 다 사용하였을 경우
    if (pathes.size() == tickets.size() + 1) {

        if (!answer.empty()) {
            for (int i = 0; i < pathes.size(); i++) {
                if (answer[i] < pathes[i]) {
                    return;
                };
            }
        }
        // answer이 초기화 되지 않았거나 pahtes가 알파벳 순으로 더 작을 때
        answer = pathes;
        return;
    }

    vector<pair<string, int>> departureAirports;
    for (int i = 0; i < tickets.size(); i++) {
        string departureAirport = tickets[i][0];
        if (departureAirport == departure) {
            departureAirports.push_back(make_pair(tickets[i][1], i));
        }
    }

    if (departureAirports.empty()) return;

    sort(departureAirports.begin(), departureAirports.end());

    for (int i = 0; i < departureAirports.size(); i++) {
        string departureAirport = departureAirports[i].first;
        int departureAirportIdx = departureAirports[i].second;

        pathes.push_back(departureAirport);
        tickets[departureAirportIdx][0] = "";
        dfs(tickets, pathes, departureAirport);
        pathes.pop_back();
        tickets[departureAirportIdx][0] = departure;
    }

    return;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> pathes;
    pathes.push_back("ICN");
    dfs(tickets, pathes, "ICN");

    return answer;
}

int main()
{
    vector<vector<string>> tickets = { {"ICN", "BBB"},{"BBB", "ICN"},{"ICN", "AAA"} };
    solution(tickets);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
}