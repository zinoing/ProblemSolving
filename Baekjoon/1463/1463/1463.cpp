// 1463.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define INT_MAX 2147483647
#include <iostream>
using namespace std;

int* dp;
int ans = INT_MAX;

void solve(int input, int cnt) {

    if (input == 1 && cnt < ans) {
        ans = cnt;
        cnt = 0;
        return;
    }

    ++cnt;

    if (input % 3 == 0 && dp[input / 3] > cnt) {
        dp[input / 3] = cnt;
        solve(input / 3, cnt);
    }

    if (input % 2 == 0 && dp[input / 2] > cnt) {
        dp[input / 2] = cnt;
        solve(input / 2, cnt);
    }

    if (dp[input - 1] > cnt) {
        dp[input - 1] = cnt;
        solve(input - 1, cnt);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input;
    cin >> input;
    dp = new int[input + 1];
    for (int i = 0; i < input + 1; i++) {
        dp[i] = INT_MAX;
    }

    solve(input, 0);

    cout << ans;
}