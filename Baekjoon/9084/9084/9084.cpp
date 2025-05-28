// 9084.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

        vector<int> coins(N + 1);
        for (int j = 1; j <= N; ++j) {
            cin >> coins[j];
        }

        int M;
        cin >> M;

        vector<vector<int>> dp(N + 1, vector<int>(M + 1));

        for (int j = 1; j <= N; ++j) {
            dp[j][0] = 1;
        }

        for (int j = 1; j <= N; ++j) {
            for (int k = 1; k <= M; ++k) {
                if (k >= coins[j])
                    dp[j][k] = dp[j - 1][k] + dp[j][k - coins[j]];
                else dp[j][k] = dp[j - 1][k];
            }
        }

        cout << dp[N][M] << endl;
    }
}