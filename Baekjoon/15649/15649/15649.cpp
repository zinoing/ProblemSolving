// 15649.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N, M;
int arr[9];
bool visited[9];
int idx = 1;

void dfs(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < cnt; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=1; i<= N; i++) {
        if (!visited[i]) {
            arr[cnt] = i;
            visited[i] = true;
            dfs(cnt + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    
    dfs(0);
}