// 2225.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int solution(int n, int k) {
    // 이차원 배열 동적 할당
    static unsigned dp[201][201];

    dp[0][0] = 1;
    for (int i = 1; i <= k; i++)
    {
        dp[i][0] = 1;
        for (int j = 1; j <= n; j++) dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
    }

    return dp[k][n]; // 이차원 배열 반환
}

void compare(int b[201][201]) {
    for (int i = 1; i <= 200; ++i) {
        for (int j = 1; j <= 200; ++j) {
            int cmp = solution(i, j);
            if (cmp != b[j][i]) {
                cout << i << ", " << j << ": " << cmp << ", " << b[j][i] << endl;
            }
        }
    }
}

int main()
{
    // K개로 만들 수 있는 N의 개수
    int dp[201][201] = { 0 };

    int N, K;
    cin >> N >> K;

    for (int i = 0; i <= K; ++i) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= N; ++i) {
        dp[1][i] = 1;
        dp[i][1] = i;
    }

    for (int i = 2; i <= K; ++i) {
        for (int j = 1; j <= N; ++j) {
            dp[i][j] = (dp[i][j-1] + dp[i - 1][j]) % 1000000000;
        }
    }


    compare(dp);

    cout << dp[K][N] % 1000000000;
}