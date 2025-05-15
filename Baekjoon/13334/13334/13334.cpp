// 13334.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> railways(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;

        int start = min(a, b);
        int end = max(a, b);

        railways[i] = make_pair(end, start);
    }

    sort(railways.begin(), railways.end());

    int d;
    cin >> d;

    int maxCnt = 0;

    priority_queue<int, vector<int>, greater<>> railwaysQ;
    int size = 0;

    for (int i = 0; i < n; ++i) {
        int end = railways[i].first;

        // 시작 부분을 우선순위 큐에 입력
        railwaysQ.push(railways[i].second); 
        ++size;

        // 선분 시작점보다 아래에 있는 철로들 제거
        while (!railwaysQ.empty() && railwaysQ.top() < end - d) {
            railwaysQ.pop();
            --size;
        }

        maxCnt = max(maxCnt, size);
    }

    cout << maxCnt;
}