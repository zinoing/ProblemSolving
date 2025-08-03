// 1309.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int main()
{
    int dp[100000] = { 0 };
    dp[0] = 1;
    dp[1] = 3;

    int N;
    cin >> N;

    for (int i = 2; i <= N; ++i) {
        dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
    }

    cout << dp[N];
}