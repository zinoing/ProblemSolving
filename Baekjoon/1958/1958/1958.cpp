// 1958.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str1, str2, str3;
    cin >> str1 >> str2 >> str3;

    str1 = '0' + str1;
    str2 = '0' + str2;
    str3 = '0' + str3;

    vector<vector<vector<int>>> dp(str1.size(), vector<vector<int>>(str2.size(), vector<int>(str3.size() )));

    for (int i = 0; i < str1.size(); ++i) {
        for (int j = 0; j < str2.size(); ++j) {
            for (int k = 0; k < str3.size(); ++k) {
                if (i == 0 || j == 0 || k == 0) {
                    dp[i][j][k] = 0;
                    continue;
                }

                if (str1[i] == str2[j] && str2[j] == str3[k]) {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                }
                else {
                    dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k]);
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1]);
                }
            }
        }
    }

    cout << dp[str1.size() - 1][str2.size() - 1][str3.size() - 1];
}

/*
aaabbc
caab
c
*/