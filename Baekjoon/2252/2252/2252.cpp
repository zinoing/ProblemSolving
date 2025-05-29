// 2252.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);
    vector<int> inDegree(N + 1, 0);

    for (int i = 0; i < M; ++i) {
        int front, end;
        cin >> front >> end;
        graph[front].push_back(end);
        inDegree[end] += 1;
    }

    queue<int> q;

    for (int i = 1; i <= N; ++i) {
        // 진입 차수가 0이면 queue에 삽입
        if (inDegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (int next : graph[front]) {
            inDegree[next] -= 1;
            if (inDegree[next] == 0) q.push(next);
        }

        cout << front << " ";
    }
}