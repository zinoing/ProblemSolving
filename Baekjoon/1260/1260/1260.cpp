// 1260.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

vector<int> v[10001];
int visited[10001] = { 0, };

void dfs(int startIndex) {
    visited[startIndex] = 1;
    cout << startIndex << ' ';

    for (int i = 0; i < v[startIndex].size(); i++) {
        if (!visited[v[startIndex][i]]) {
            dfs(v[startIndex][i]);
        }
    }
}

void bfs(int startIndex) {
    queue<int> q;
    q.push(startIndex);
    visited[startIndex] = 1;

    while (!q.empty()) {
        int min = q.front();
        q.pop();
        cout << min << ' ';

        for (int i = 0; i < v[min].size(); i++) {
            int x = v[min][i];
            if (!visited[x]) {
                q.push(x);
                visited[x] = 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;

    int startNode, endNode;
    for (int i = 0; i < M; i++) {
        cin >> startNode >> endNode;
        v[startNode].push_back(endNode);
        v[endNode].push_back(startNode);
    }

    for (int i = 1; i <= M; i++) {
        sort(v[i].begin(), v[i].end());
    }   

    dfs(V);
    cout << '\n';
    memset(visited, NULL, 10001); // memset의 문제점 발견
    bfs(V);
}
