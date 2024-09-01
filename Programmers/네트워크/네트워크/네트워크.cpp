// 네트워크.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

void dfs(vector<vector<int>> network, vector<bool> visited, int n, int* answer) {

    stack<int> networkStack;

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        networkStack.push(i);

        while (!networkStack.empty()) {
            int nextComputer = networkStack.top();
            networkStack.pop();

            if (network[nextComputer].size() == 0) {
                continue;
            }

            for (int i = 0; i < network[nextComputer].size(); i++) {
                if (visited[network[nextComputer][i]]) continue;
                visited[network[nextComputer][i]] = true;
                networkStack.push(network[nextComputer][i]);
            }
        }

        *answer += 1;
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    vector<vector<int>> network(computers.size());

    for (int i = 0; i < computers.size(); i++) {
        for (int j = 0; j < computers[i].size(); j++) {
            if (i == j) continue;
            if (computers[i][j] == 0) continue;
            network[i].push_back(j);
        }
    }

    for (int i = 0; i < computers.size(); i++) {
        cout << i << ": ";
        for (int j = 0; j < network[i].size(); j++) {
            cout << network[i][j] << ' ';
        }
        cout << endl;
    }

    int answer = 0;

    vector<bool> visited(computers.size());
    for (int i = 0; i < computers.size(); i++) {
        visited[i] = false;
    }
    dfs(network, visited, n, &answer);

    return answer;
}

int main()
{
    int n = 3;
    vector<vector<int>> computers = { {1, 1, 0} ,{1, 1, 1},{0, 1, 1} };
    std::cout << solution(n, computers);
}