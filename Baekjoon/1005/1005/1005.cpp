// 1005.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int N, K;
        cin >> N >> K;

        vector<int> buildings(N + 1);
        vector<vector<int>> graph(N + 1);
        vector<int> inDegree(N + 1);
        vector<int> times(N + 1);

        for (int j = 1; j <= N; ++j) {
            cin >> buildings[j];
            times[j] = buildings[j];
        }

        queue<int> q;

        for (int j = 1; j <= K; ++j) {
            int first, next;
            cin >> first >> next;
            graph[next].push_back(first);
            inDegree[next] += 1;
        }

        int W;
        cin >> W;

        for (int j = 1; j <= N; ++j) {
            if (inDegree[j] == 0) {
                graph[j].push_back(0);
                inDegree[j] += 1;
            }
        }

        q.push(W);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            int maxTime = 0;
            for (int previous : graph[curr]) {
                times[previous] = max(buildings[previous] + times[curr], times[previous]);
                q.push(previous);
            }
        }
        cout << times[0] << '\n';
    }
}