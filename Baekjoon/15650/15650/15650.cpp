// 15650.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool visited[9];
vector<vector<int>> visitedVecs;

bool isVisited(vector<int> vec) {
    int size = visitedVecs.size();
    for (int i = 0; i < size; i++) {
        int cnt = 0;
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < M; k++) {
                if (visitedVecs[i][j] == vec[k]) {
                    ++cnt;
                }

                if (cnt == M)
                    return true;
            }
        }
    }
    return false;
}

void dfs(int depth, vector<int> vec) {
    if (depth == M) {

        if (isVisited(vec))
            return;

        visitedVecs.push_back(vec);

        int idx = 0;
        while (idx < M) {
            int number = vec[idx];
            if (number == 0) break;
            cout << number << " ";
            ++idx;
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            vec[depth] = i;
            dfs(depth + 1, vec);
            vec[depth] = 0;
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> N >> M;

    vector<int> vec(M);
    dfs(0, vec);
}