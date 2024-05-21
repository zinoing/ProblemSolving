// 9663.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stack>
using namespace std;

int N;
bool board[15][15];
bool previous[15][15][15];
int ans = 0;

void dfs(pair<int,int> start) {

    stack<pair<int, int>> s;
    s.push(start);

    while (!s.empty()) {
        pair<int,int> q = s.top();
        s.pop();

        // 마지막 행에 대한 퀸일때
        if (q.first == N-1) {
            ++ans;
            if (!s.empty()) {
                // 보드를 이전 보드로 초기화 하기
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        board[i][j] = previous[s.top().first - 1][i][j];
                    }
                }
            }
            continue;
        }

        for (int i = 0; i < N; i++) {
            // 열 설정
            board[q.first][i] = false;
            // 행 설정
            board[i][q.second] = false;

            // 오른쪽 아래 대각선 설정
            if(q.first + i !=  N && q.second + i != N)
                board[q.first + i][q.second + i] = false;
            // 왼쪽 위 대각선 설정
            if (q.first - i >= 0 && q.second - i >= 0)
                board[q.first - i][q.second - i] = false;
            // 왼쪽 아래 대각선 설정
            if (q.first + i != N && q.second - i >= 0)
                board[q.first + i][q.second - i] = false;
            // 오른쪽 위 대각선 설정
            if (q.first - i >= 0 && q.second + i != N)
                board[q.first - i][q.second + i] = false;
        }

        // back tracking을 위해 previous에 복사
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                previous[q.first][i][j] = board[i][j];
            }
        }

        bool check = false;
        for (int i = 0; i < N; i++) {
            if (board[q.first + 1][i]) {
                check = true;   
                s.push(make_pair(q.first + 1, i));
            }
        }

        // 다음에 퀸을 놓을 수 없다면
        if (!check && !s.empty()) {
            // 보드를 이전 보드로 초기화 하기
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    board[i][j] = previous[s.top().first - 1][i][j];
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {

        // 보드 초기화
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                board[j][k] = true;
                for (int l = 0; l < N; l++) {
                    previous[j][k][l] = true;
                }
            }
        }

        dfs(make_pair(0, i));
    }

    cout << ans;
}