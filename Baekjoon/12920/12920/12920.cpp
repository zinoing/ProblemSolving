// 12920.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> bags;
    bags.push_back(make_pair(0, 0));

    for (int i = 0; i < N; ++i) {
        int V, S, K;
        cin >> V >> S >> K;
        for (int k = 0; k < K; ++k)
        {
            bags.push_back(make_pair(V, S));
        }
    }

    int numOfBags = (int)bags.size();

    vector<vector<int>> dp(numOfBags, vector<int>(M + 1));

    for (int i = 1; i < numOfBags; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (j >= bags[i].first)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - bags[i].first] + bags[i].second);
            else dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[numOfBags - 1][M];
}