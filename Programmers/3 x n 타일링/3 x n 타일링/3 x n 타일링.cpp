// 3 x n 타일링.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int dp[5001];

int getNumberOfRectangle(int n) {
    // dp[N] = dp[2] * dp[N - 2] + dp[N-4] * 2 + dp[N-6] * 2 + ... + dp[2] * 2
    if (n % 2 == 1) return 0;
    if (dp[n] != 0) return dp[n];

    long long ans = getNumberOfRectangle(n - 2) * dp[2];
    for (int i = n - 4; i >= 0; i-=2) {
        ans += getNumberOfRectangle(i) * 2;
    }
    ans %= 1000000007;
    dp[n] = ans;
    return ans;
}

int solution(int n) {
    dp[0] = 1;
    dp[2] = 3;
    dp[4] = 11;

    // N ==8 일 때,
    // 2인 경우 * 6인 경우(S)
    // 4인 경우(S) * 4인 경우(S)
    // 6인 경우 * 2인 경우
    // += 2

    // N ==10 일 때,
    // 8인 경우(s) * 2인 경우
    // 6인 경우 * 4인 경우(s)
    // 4인 경우 * 6인 경우(S)
    // 2인 경우 * 8인 경우(s)

    // dp[N] = dp[2] * dp[N - 2] + dp[N-4] * 2 + dp[N-6] * 2 + ... + dp[2] * 2

    return getNumberOfRectangle(n);
}

int main()
{
    for (int i = 0; i < 1000; i++) {
        cout << solution(i) << '\n';
    }

    //cout << solution(6) << '\n';

}