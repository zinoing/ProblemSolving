// 2133.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int dp[31] = { 0 };
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;

    for (int i = 4; i <= N; i+=2) {
        dp[i] = dp[i - 2] * dp[2];
        for (int j = i-4; j >= 0; j -= 2) {
            dp[i] = dp[i] + dp[j] * 2;
        }
    }
    cout << dp[N];
}