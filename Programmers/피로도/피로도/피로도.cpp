// 피로도.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>

using namespace std;

int maxDungeon = 0;

void dfs(int k, vector<bool> visited, vector<vector<int>> dungeons, int numOfDungeonsAdventured) {
    maxDungeon = max(maxDungeon, numOfDungeonsAdventured);

    for (int i = 0; i < dungeons.size(); i++) {
        if (k >= dungeons[i][0] && !visited[i]) {
            visited[i] = true;
            dfs(k - dungeons[i][1], visited, dungeons, numOfDungeonsAdventured + 1);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> visited(dungeons.size());

    dfs(k, visited, dungeons, 0);

    int answer = maxDungeon;
    return answer;
}