// 가장 먼 노드.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

unordered_map<int, vector<int>> edgeMap;

int bfs(int n) {
    vector<int> nodes(n + 1, 0);
    vector<int> cnt(n, 0);

    queue<int> nodeQueue;
    nodeQueue.push(1);

    while (!nodeQueue.empty()) {
        int start = nodeQueue.front();
        nodeQueue.pop();

        vector<int> destinations = edgeMap[start];

        for (int dst : destinations) {
            if (dst == 1 || nodes[dst] > 0) continue;
            //cout << "start: " << start << "visits " << dst << endl;
            nodes[dst] = nodes[start] + 1;
            ++cnt[nodes[dst]];

            nodeQueue.push(dst);
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        if (cnt[i] != 0) {
            return cnt[i];
        }
    }
}

int solution(int n, vector<vector<int>> edge) {

    for (int i = 0; i < edge.size(); i++) {
        edgeMap[edge[i][0]].push_back(edge[i][1]);
        edgeMap[edge[i][1]].push_back(edge[i][0]);
    }

    int answer = bfs(n);
    return answer;
}