// 4485.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
using namespace std;

int N;
int cave[126][126] = { 0, };
int visited[126][126] = { 0, };
int ans = INT_MAX;

int dfs(int col, int row) {
    queue<int> q;
    q.push(cave[col][row]);
    int front = 0;

    while (!q.empty()) {
        front = q.front();
        q.pop();
        
        if (col < N - 1) {
            // 이미 누가 값을 추가해둔 상태일 경우
            if (cave[col + 1][row] != visited[col + 1][row] && cave[col + 1][row] + front < visited[col + 1][row]) {
                visited[col + 1][row] = cave[col + 1][row] + front;
            }

            if (cave[col + 1][row] == visited[col + 1][row]) {
                visited[col + 1][row] = cave[col + 1][row] + front;
            }

            q.push(cave[col + 1][row]);
            ++col;
            continue;
        }

        if (row < N - 1) {
            if (cave[col][row + 1] != visited[col][row + 1] && cave[col][row + 1] + front < visited[col][row + 1]) {
                visited[col][row + 1] = cave[col][row + 1] + front;
            }

            if (cave[col][row + 1] == visited[col][row + 1]) {
                visited[col][row + 1] = cave[col][row + 1] + front;
            }

            q.push(cave[col][row + 1]);
            ++row;
            continue;
        }
    }

    return front;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count = 1;
    while (1) {
        cin >> N;

        if (N == 0)
            break;

        int input = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> input;
                cave[i][j] = input;
                visited[i][j] = input;
            }
        }

        dfs(0, 0);

        cout << "Problem " << count++ << ": " << ans << endl;
        ans = INT_MAX;
    }
}