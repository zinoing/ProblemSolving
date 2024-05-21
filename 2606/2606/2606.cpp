// 2606.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> v[101];
int visited[101] = { 0, };
int ans = 0;

void dfs(int index) {
    for (int i = 0; i < v[index].size(); i++) {

        if (visited[v[index][i]] == 0) {
            visited[v[index][i]] = 1;
            ++ans;
            dfs(v[index][i]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numOfComputers;
    cin >> numOfComputers;

    int numOfConnections;
    cin >> numOfConnections;

    for (int i = 0; i < numOfConnections; i++) {
        int first, second;
        cin >> first >> second;

        v[first].push_back(second);
        v[second].push_back(first);
    }

    visited[1] = 1;
    dfs(1);
    cout << ans;
}