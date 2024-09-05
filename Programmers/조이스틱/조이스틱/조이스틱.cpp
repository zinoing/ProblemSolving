// 조이스틱.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

int minVal = INT_MAX;

void dfs(string name, vector<bool> visited, int idx, int cnt) {

    if (cnt == name.size()) return;
    visited[idx] = true;

    for (int i = 0; i < name.size(); i++) {
        if (!visited[i] && name[i] != 'A') {
            break;
        }

        if (i == name.size() - 1) {
            minVal = min(minVal, cnt);
            return;
        }
    }
    dfs(name, visited, (idx + 1) % name.size(), cnt + 1);
    dfs(name, visited, (idx - 1 + name.size()) % name.size(), cnt + 1);
}

int solution(string name) {
    int answer = 0;

    vector<bool> visited(name.size());
    dfs(name, visited, 0, 0);
    answer += minVal;
    for (int i = 0; i < name.size(); i++) {
        answer += min('Z' - name[i] + 1, name[i] - 'A');
    }

    return answer;
}