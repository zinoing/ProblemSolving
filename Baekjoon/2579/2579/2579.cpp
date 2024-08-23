#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numOfStairs;
    cin >> numOfStairs;

    int dp[301] = { 0, };
    int stairs[301] = { 0, };

    for (int i = 0; i < numOfStairs; i++) {
        int input;
        cin >> input;
        stairs[i] = input;
    }

    dp[0] = stairs[0];
    dp[1] = stairs[0] + stairs[1];
    dp[2] = max(stairs[0], stairs[1]) + stairs[2];
    dp[3] = max(dp[1], stairs[0] + stairs[2]) + stairs[3];

    for (int i = 4; i < numOfStairs; i++) {
        dp[i] = max(dp[i - 3] + stairs[i - 1], dp[i - 2]) + stairs[i];
    }

    cout << dp[numOfStairs - 1];

    return 0;
}