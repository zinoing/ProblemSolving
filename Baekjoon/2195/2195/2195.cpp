// 2195.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S, P;cin >> S >> P;

    vector<vector<int>> LIS(S.size(), vector<int>(P.size()));

    for (int i = 0; i < (int)S.size(); ++i) {
        for (int j = 0; j < (int)P.size(); ++j) {
            if (S[i] == P[j]) {
                if (i > 0 && j > 0 && LIS[i - 1][j - 1] > 0) {
                    LIS[i][j] = LIS[i - 1][j - 1] + 1;
                }
                else {
                    LIS[i][j] = 1;
                }
            }
        }
    }

    vector<int> cnt(P.size(), 0);

    for (int i = 0; i < (int)S.size(); ++i) {
        for (int j = 0; j < (int)P.size(); ++j) {
            if (LIS[i][j] >= 1) {
                int idx = 1;
                while (i + idx < (int)S.size() && j + idx < (int)P.size() && LIS[i + idx][j + idx] != 0) {
                    ++idx;
                }
                cnt[j] = max(cnt[j], idx);
            }
        }
    }

    int n = cnt.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0; 

    for (int i = 0; i < n; ++i) {
        if (dp[i] == INT_MAX) continue;

        for (int j = 1; j <= cnt[i] && i + j <= n; ++j) {
            dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
    }

    cout << dp[n];
    return 0;
}
