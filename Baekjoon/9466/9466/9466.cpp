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
            route.push_back(next);
            while (1) {
                // ������ �湮�� �ߴ� ���̶��
                if (visited[next]) {
                    // ����Ŭ�̶�� �̶����� �̷���� ��ΰ� ����Ŭ�� �ƴ϶�� ��
                    if (inCycle[next]) {

                        for (auto node : route) {
                            inCycle[node] = false;
                        }
                        break;
                    }
                    // ����Ŭ�� �ƴ϶�� �̶����� �̷���� ��� �� ����Ŭ�� �ִٴ� �� => ����Ŭ Ȯ�� �ʿ�
                    else {
                        bool cycleStart = false;
                        for (auto node : route) {
                            if (node == students[next]) {
                                cycleStart = true;
                            }

                            if (cycleStart) {
                                inCycle[node] = true;
                            }
                        }
                        break;
                    }
                }

                visited[next] = true;
                next = students[next];
                route.push_back(next);
            }
        }

        int cnt = 0;
        for (int j = 1; j <= N; ++j) {
            if (!inCycle[j]) ++cnt;
        }

        cout << cnt << "\n";
    }
}