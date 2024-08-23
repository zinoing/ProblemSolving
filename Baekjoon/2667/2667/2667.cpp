// 2667.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int N;
int apartments[26][26];
bool visited[26][26];

vector<int> answers;
int ans = 0;

void dfs(int y, int x) {
    if (!apartments[y][x])
        return;

    if (visited[y][x])
        return;

    stack<pair<int, int>> s;
    s.push(make_pair(y, x));
    visited[y][x] = true;
    ++ans;

    while (!s.empty()) {
        pair<int, int> coord = s.top();
        s.pop();

        if (coord.first + 1 < N && apartments[coord.first + 1][coord.second] && !visited[coord.first + 1][coord.second]) {
            visited[coord.first + 1][coord.second] = true;
            s.push(make_pair(coord.first + 1, coord.second));
            ++ans;
        }

        if (coord.first - 1 >= 0 && apartments[coord.first - 1][coord.second] && !visited[coord.first - 1][coord.second]) {
            visited[coord.first - 1][coord.second] = true;
            s.push(make_pair(coord.first - 1, coord.second));
            ++ans;
        }

        if (coord.second + 1 < N && apartments[coord.first][coord.second + 1] && !visited[coord.first][coord.second + 1]) {
            visited[coord.first][coord.second + 1] = true;
            s.push(make_pair(coord.first, coord.second + 1));
            ++ans;
        }
    
        if (coord.second - 1 >= 0 && apartments[coord.first][coord.second - 1] && !visited[coord.first][coord.second - 1]) {
            visited[coord.first][coord.second - 1] = true;
            s.push(make_pair(coord.first, coord.second - 1));
            ++ans;
        }
    }

    answers.push_back(ans);
    ans = 0;
}

int main()
{
    cout.tie(NULL);

    cin >> N;

    int input;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &input);
            apartments[i][j] = input;
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dfs(i, j);
        }
    }
    int size = answers.size();
    cout << size << endl;
    sort(answers.begin(), answers.end());
    for (int i = 0; i < size; i++) {
        cout << answers[i] << endl;
    }
}
