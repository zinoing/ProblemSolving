// 15654.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
bool visited[10000];
int arr[9];
vector<int> numbers;

void dfs(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        int number = numbers[i];
        if (!visited[number]) {
            arr[depth] = number;
            visited[number] = true;
            dfs(depth + 1);
            arr[depth] = 0;
            visited[number] = false;
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int number;
        cin >> number;
        numbers.push_back(number);
    }
    sort(numbers.begin(), numbers.end());

    dfs(0);
}
