// 섬 연결하기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int minCost = INT_MAX;

void dfs(int n, vector<vector<int>> costs, vector<int> visitedIslands, int cost, vector<int> costLog) {
    if (visitedIslands.size() == n) {
        for (int island : visitedIslands) cout << island << ' ';
        cout << '\n';
        for (int cl : costLog) cout << cl << ' ';
        cout << '\n';
        cout << cost << '\n';
        minCost = min(minCost, cost);
        return;
    }

    for (int i = 0; i < visitedIslands.size(); i++) {
        for (int j = 0; j < costs.size(); j++) {
            if (costs[j][0] != visitedIslands[i] && costs[j][1] != visitedIslands[i]) continue;
            int dst = 0;

            if (costs[j][0] == visitedIslands[i]) {
                dst = costs[j][1];
            }

            if (costs[j][1] == visitedIslands[i]) {
                dst = costs[j][0];
            }

            if (find(visitedIslands.begin(), visitedIslands.end(), dst) != visitedIslands.end()) continue;

            vector<int> tempVisitedIslands = visitedIslands;
            tempVisitedIslands.push_back(dst);

            vector<int> tempCostLog = costLog;
            tempCostLog.push_back(costs[j][2]);

            if (cost + costs[j][2] > minCost) continue;
            dfs(n, costs, tempVisitedIslands, cost + costs[j][2], tempCostLog);
        }
    }
}

int solution(int n, vector<vector<int>> costs) {
    vector<int> visitedIslands;
    visitedIslands.push_back(0);
    vector<int> costLog;

    dfs(n, costs, visitedIslands, 0, costLog);

    int answer = minCost;
    return answer;
}

int main()
{
    int n = 5;
    vector<vector<int>> costs = { {0, 1, 5},{1, 2, 3},{2, 3, 3},{3, 1, 2},{3, 0, 4},{2, 4, 6},{4, 0, 7} };
    solution(n, costs);
}