// 9466.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
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
        int N;
        cin >> N;

        vector<int> students(N + 1, 0);
        vector<bool> visited(N + 1, false);
        vector<bool> inCycle(N + 1, false);

        for (int j = 1; j <= N; ++j) {
            cin >> students[j];
        }

        for (int j = 1; j <= N; ++j) {

            if (visited[j]) continue;

            vector<int> route;
            int next = j;
            while (1) {
                // 이전에 방문을 했던 곳이라면
                if (visited[next]) {
                    // 사이클이라면 이때까지 이루어진 경로가 사이클이 아니라는 뜻
                    if (inCycle[next]) {

                        for (auto node : route) {
                            inCycle[node] = false;
                        }
                    }
                    // 사이클이 아니라면 이때까지 이루어진 경로 중 사이클이 있다는 뜻 => 사이클 확인 필요
                    // 아니면 사이클이 아닌 노드에 접근 => 이때까지 갔던 경로 속 모든 노드들이 사이클이 아님
                    else {
                        if (students[next] != -1) {
                            bool cycleStart = false;
                            for (auto node : route) {
                                if (node == next) {
                                    cycleStart = true;
                                }
                                
                                if (cycleStart) {
                                    inCycle[node] = true;
                                }
                                else {
                                    students[node] = -1;
                                }
                            }
                        }
                        else {
                            for (auto node : route) {
                                students[node] = -1;
                            }
                        }
                    }
                    break;
                }

                route.push_back(next);
                visited[next] = true;
                next = students[next];
            }
        }

        int cnt = 0;
        for (int j = 1; j <= N; ++j) {
            if (!inCycle[j]) ++cnt;
        }

        cout << cnt << "\n";
    }
}

/*

2
6
2 3 4 3 6 1
5
5 1 2 3 4
*/