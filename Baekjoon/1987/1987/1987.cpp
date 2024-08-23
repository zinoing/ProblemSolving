// 1987.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int R, C;
int** arr;
bool visited[26] = { 0, };
int ans = 0;
int cnt = 0;

void dfs(int curCol, int curRow) {
    ++cnt;
    visited[arr[curCol][curRow]] = true;

    // 오른쪽으로 갈 수 있는지 확인
    if (curRow < C - 1 && !visited[arr[curCol][curRow + 1]]) {
        dfs(curCol, curRow + 1);
    }

    // 아래로 갈 수 있는지 확인
    if (curCol < R - 1 && !visited[arr[curCol + 1][curRow]]) {
        dfs(curCol + 1, curRow);
    }
    // 위로 갈 수 있는지 확인
    if (curCol > 0 && !visited[arr[curCol - 1][curRow]]) {
        dfs(curCol - 1, curRow);
    }

    // 왼쪽으로 갈 수 있는지 확인
    if (curRow > 0 && !visited[arr[curCol][curRow - 1]]) {

        dfs(curCol, curRow - 1);
    }

    // 갈 수 있는 곳이 없을 때 돌아가기
    if (cnt > ans)
        ans = cnt;
    --cnt;
    visited[arr[curCol][curRow]] = false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> R >> C;

    arr = new int * [R];
    for (int i = 0; i < R; i++) {
        arr[i] = new int[C];
    }

    char input;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> input;
            arr[i][j] = (int)input - 65;
        }
    }

    dfs(0, 0);

    cout << ans;
}
