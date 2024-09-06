// 더 맵게.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }

    int cnt = 0;
    int first = -1;
    int second = -1;

    while (!pq.empty()) {
        int food = pq.top();
        pq.pop();

        if (first == -1 && food >= K) break;

        if (first == -1 && pq.empty() && food < K) return -1;

        if (first == -1) {
            first = food;
            continue;
        }

        second = food;
        pq.push(first + 2 * second);
        ++cnt;
        first = -1;
        second = -1;
    }

    int answer = cnt;
    return answer;
}