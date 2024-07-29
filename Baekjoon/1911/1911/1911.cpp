#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L;
    cin >> N >> L;

    vector<pair<int, int>> pools(N);
    for (int i = 0; i < N; ++i) {
        cin >> pools[i].first >> pools[i].second;
    }

    // 웅덩이들을 시작 위치 기준으로 정렬
    sort(pools.begin(), pools.end());

    int numPlanks = 0;
    int coveredUntil = 0;

    for (const auto& pool : pools) {
        int start = pool.first;
        int end = pool.second;

        // 현재 널빤지로 커버할 수 있는 범위를 넘어서는 경우 새로운 널빤지를 배치
        if (coveredUntil < start) {
            coveredUntil = start;
        }

        while (coveredUntil < end) {
            coveredUntil += L;  // 널빤지 하나 추가
            numPlanks++;
        }
    }

    cout << numPlanks << "\n";
    return 0;
}
