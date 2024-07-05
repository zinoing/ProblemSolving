#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int N;
long long int map[101][101];
long long int dp[101][101];

void solve() {
    dp[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dp[i][j] == 0 || (i == N - 1 && j == N - 1))
                continue;

            int value = map[i][j];
            int down = i + value;
            int right = j + value;

            if (down < N) {
                dp[down][j] += dp[i][j];
            }

            if (right < N) {
                dp[i][right] += dp[i][j];
            }
        }
    }

    cout << dp[N - 1][N - 1];
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int input;
            cin >> input;
            map[i][j] = input;
            dp[i][j] = 0;
        }
    }

    solve();
    return 0;
}