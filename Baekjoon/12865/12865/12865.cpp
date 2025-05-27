// 12865.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> dp(100002, vector<int>(101));
vector<pair<int, int>> bags;
int N, K;

int main()
{
    cin >> N >> K;

    bags.resize(N + 1);

    for (int i = 1; i <= N; ++i) {
        int W, V;
        cin >> W >> V;

        bags[i].first = W;
        bags[i].second = V;
    }

    for (int i = 1; i <= K; ++i) {
        for (int j = 1; j <= N; ++j) {
            // 배낭 무게가 무게 제한을 초과한다면
            if (i < bags[j].first) {
                dp[i][j] = dp[i][j - 1];
                continue;
            }

            // 이전 가치와 비교하여 더 큰 가치 선택
            dp[i][j] = max(dp[i][j - 1], dp[i - bags[j].first][j - 1] + bags[j].second);
        }
    }

    cout << dp[K][N];
    return 0;
}