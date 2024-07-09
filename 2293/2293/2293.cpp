// 2293.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

int dp[10001] = { 0, };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> coins;
    for (int i = 0; i < n; i++) {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= k; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    cout << dp[k];

    return 0;
}