// 15652.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

int N, M;
int arr[9];

void dfs(int num, int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = num; i <= N; i++) {

        arr[depth] = i;
        dfs(i, depth + 1);
        arr[depth] = 0;
    }
}

int main()
{
    cin >> N >> M;

    dfs(1, 0);
}
