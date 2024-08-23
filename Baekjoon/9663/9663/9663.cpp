// 9663.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stack>
using namespace std;

int N;
int col[15];
int ans = 0;

bool check(int x) {
    // 이전에 놓은 퀸들과 겹치지 않는지 체크
    for (int j = 0; j < x; j++) {
        // 열은 겹치지 않으니 행과 대각선만 체크하면 된다.
        if (col[j] == col[x] || abs(col[x] - col[j]) == x - j) {
            return false; // 겹칠 경우 다른 행을 가도록 지정
        }
    }
    return true;
}

void solve(int x) {
    if (x == N) {
        ++ans;
        return;
    }

    for (int i = 0; i < N; i++) {
        // 퀸이 cnt번 열에서 몇 행을 갈지 지정
        col[x] = i;

        if(check(x))
            solve(x + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    solve(0);

    cout << ans;
}