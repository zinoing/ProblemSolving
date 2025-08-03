// 9251.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string firstStr, secondStr;
    cin >> firstStr >> secondStr;

    firstStr = "0" + firstStr;
    secondStr = "0" + secondStr;

    vector<vector<int>> dp(firstStr.size(), vector<int>(secondStr.size(), 0));

    for (int i = 0; i < firstStr.size(); ++i) {
        for (int j = 0; j < secondStr.size(); ++j) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (firstStr[i] == secondStr[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[firstStr.size() - 1][secondStr.size() - 1];
}