// 9252.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string firstStr;
string secondStr;

string lcsString(vector<vector<int>> dp, int y, int x) {
    int lengthOfStr = dp[y][x];
    int dy[2] = { -1, 0 };
    int dx[2] = { 0, -1 };
    string lcsStr = "";

    while (lengthOfStr > 0) {
        int cnt = 0;

        for (int i = 0; i < 2; ++i) {
            int dirY = y + dy[i];
            int dirX = x + dx[i];

            if (dp[dirY][dirX] != lengthOfStr) {
                ++cnt;
            }
            else {
                y = dirY;
                x = dirX;
                break;
            }
        }

        // 더 이상 갈 수 없을 때
        if (cnt == 2) {
            lcsStr += secondStr[x];
            y = y - 1;
            x = x - 1;
        }

        lengthOfStr = dp[y][x];
    }

    reverse(lcsStr.begin(), lcsStr.end());
    return lcsStr;
}

void lcs() {
    firstStr = "0" + firstStr;
    secondStr = "0" + secondStr;

    int firstStrLength = firstStr.size();
    int secondStrLength = secondStr.size();

    vector<vector<int>> dp(firstStrLength, vector<int>(secondStrLength));

    for (int i = 0; i < firstStrLength; ++i) {
        for (int j = 0; j < secondStrLength; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if (firstStr[i] == secondStr[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // lcs 길이 구하기
    cout << dp[firstStrLength - 1][secondStrLength - 1] << "\n";

    string lcsStr = lcsString(dp, firstStrLength - 1, secondStrLength - 1);
    cout << lcsStr;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> firstStr >> secondStr;

    lcs();
}