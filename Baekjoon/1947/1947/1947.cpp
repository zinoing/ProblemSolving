// 1947.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define MOD 1000000000

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[1] = 0;
    dp[2] = 1;

    unsigned long a = 1;
    for (int i = 3; i <= n; ++i) {
        dp[i] = (1LL * (i - 1) * (dp[i - 1] + dp[i - 2])) % MOD;
    }

    cout << dp[n];

    return 0;
}