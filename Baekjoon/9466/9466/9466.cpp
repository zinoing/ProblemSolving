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
                // ������ �湮�� �ߴ� ���̶��
                if (visited[next]) {
                    // ����Ŭ�̶�� �̶����� �̷���� ��ΰ� ����Ŭ�� �ƴ϶�� ��
                    if (inCycle[next]) {

                        for (auto node : route) {
                            inCycle[node] = false;
                        }
                    }
                    // ����Ŭ�� �ƴ϶�� �̶����� �̷���� ��� �� ����Ŭ�� �ִٴ� �� => ����Ŭ Ȯ�� �ʿ�
                    // �ƴϸ� ����Ŭ�� �ƴ� ��忡 ���� => �̶����� ���� ��� �� ��� ������ ����Ŭ�� �ƴ�
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