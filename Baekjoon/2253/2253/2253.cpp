// 2253.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define K 150

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int dp[10001][K + 1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int fail;
        cin >> fail;

        if (fail == 2) {
            cout << -1;
            return 0;
        }

        for (int j = 0; j <= K; ++j) {
            dp[fail][j] = -1;
        }
    }

    dp[1][1] = 1;
    dp[2][1] = 2;

    for (int i = 3; i <= N; ++i) {
        for (int j = 1; j < K; ++j) { // 점프 거리
            if (j >= i) break;
            if (i - j == 1) break;

            // 점프를 할 수 없는 돌일 경우
            if (dp[i][j] == -1) break;
            if (dp[i - j][j] == -1) continue;

            // 이전 상태에서 점프를 뛴 적이 없는 경우
            if (dp[i - j][j - 1] == 0 && dp[i - j][j + 1] == 0 && dp[i - j][j] == 0) continue;

            int left = (dp[i - j][j - 1] == 0) ? INT_MAX : dp[i - j][j - 1];
            int mid = (dp[i - j][j] == 0) ? INT_MAX : dp[i - j][j];
            int right = (dp[i - j][j + 1] == 0) ? INT_MAX : dp[i - j][j + 1];

            dp[i][j] = min(left, mid);
            dp[i][j] = min(dp[i][j], right);
            dp[i][j] += 1;
        }
    }   

    int minCnt = INT_MAX;
    for (int i = 1; i < K; ++i) {
        if (dp[N][i] == 0) continue;
        minCnt = min(minCnt, dp[N][i]);
    }

    if (minCnt == INT_MAX) minCnt = -1;
    else minCnt -= 1;

    cout << minCnt;
}