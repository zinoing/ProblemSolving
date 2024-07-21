// 1520.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stack>
using namespace std;

int M, N;
int map[501][501];
int visited[501][501];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int ans;

int dfs(int y, int x) {
    // 끝까지 도달
    if (y == M - 1 && x == N - 1) {
        return 1;
    }

    int& cnt = visited[y][x];
    if (cnt != -1) return cnt; // 방문했던 곳이라면 즉시 반환
    cnt = 0;

    for (int i = 0; i < 4; i++) {

        // 맵 이동 가능 여부 확인
        if (y + dy[i] >= M || y + dy[i] < 0 || x + dx[i] >= N || x + dx[i] < 0)
            continue;

        // 내리막길 확인
        if (map[y + dy[i]][x + dx[i]] >= map[y][x])
            continue;

        cnt += dfs(y + dy[i], x + dx[i]);
    }

    //for (int i = 0; i < M; i++) {
    //    for (int j = 0; j < N; j++) {
    //        cout << visited[i][j] << " ";
    //    }
    //    cout << '\n';
    //}
    //cout << '\n';

    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    cin >> M >> N;
    int value;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> value;
            map[i][j] = value;
            visited[i][j] = -1;
        }
    }

    // dfs
    cout << dfs(0, 0) << '\n';;
}
