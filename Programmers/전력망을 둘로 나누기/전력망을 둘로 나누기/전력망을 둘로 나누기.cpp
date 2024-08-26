// 전력망을 둘로 나누기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minConnection = INT_MAX;
int maxConnection = 0;

int dfs(vector<vector<int>> wireConnections, int depth, vector<bool> visited, int nextNode) {

    maxConnection = max(maxConnection, depth);

    if (!visited[nextNode]) {
        visited[nextNode] = true;

        int idx = 0;
        int nextNextNode = 0;
        while (idx < wireConnections[nextNode].size()) {
            if (!visited[wireConnections[nextNode][idx]]) {
                nextNextNode = wireConnections[nextNode][idx];
                depth = dfs(wireConnections, depth + 1, visited, nextNextNode);
            }
            ++idx;
        }
    }

    return depth;
}

int solution(int n, vector<vector<int>> wires) {


    for (int i = 0; i < wires.size(); i++) {
        vector<vector<int>> wireConnections(101);

        for (int j = 0; j < wires.size(); j++) {
            if (i == j) continue;

            int first = wires[j][0];
            int second = wires[j][1];

            wireConnections[first].push_back(second);
            wireConnections[second].push_back(first);
        }

        vector<bool> visited(101);
        dfs(wireConnections, 0, visited, wires[0][0]);

        int diff = abs(maxConnection - (n - 2 - maxConnection));
        if (minConnection > diff) {
            minConnection = diff;
        }
        maxConnection = 0;
    }

    int answer = minConnection;
    return answer;
}

int main() {
    int n = 9;
    vector<vector<int>> wires = { {1, 3},{2, 3},{3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9} };

    //int n = 7;
    //vector<vector<int>> wires = { {1, 2},{2, 7},{3, 7}, {3, 4}, {4, 5}, {6, 7} };

    //int n = 4;
    //vector<vector<int>> wires = { {1, 2},{2, 3},{3, 4} };

    //int n = 14;
    //vector<vector<int>> wires =  {{1, 6}, {1, 3}, {1, 4}, {2, 4}, {4, 9}, {5, 6}, {6, 8}, {6, 7}, {6, 13}, {6, 14}, {9, 10}, {10, 11}, {11, 12}};
    cout << solution(n, wires);
    return 0;
}