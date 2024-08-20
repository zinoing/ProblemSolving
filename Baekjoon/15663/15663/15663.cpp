// 15663.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr(9);
int visited[9];
vector<int> vec;

void dfs(int depth) {
    if (depth == M) {

        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';

        return;
    }

    int previous = 0;
    for (int i = 1; i <= N; i++) {
        int number = vec[i - 1];

        if (!visited[i] && number != previous) {
            previous = number;
            visited[i] = true;
            arr[depth] = number;
            dfs(depth + 1);
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

    for (int i = 1; i <= N; i++) {
        int number;
        cin >> number;
        vec.push_back(number);
    }

    sort(vec.begin(), vec.end());

    dfs(0);

    return 0;
}