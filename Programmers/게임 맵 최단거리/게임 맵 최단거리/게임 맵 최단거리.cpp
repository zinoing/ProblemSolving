// 게임 맵 최단거리.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

typedef pair<int, int> Pos;

vector<vector<int> > cnt;
int visited[101][101];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int arrived = INT_MAX;

bool checkOutOfRange(int y, int x, int mapHeight, int mapWidth) {
    return (y >= mapHeight || y < 0 || x >= mapWidth || x < 0);
}

void bfs(vector<vector<int> > maps) {
    queue<Pos> posQueue;
    posQueue.push(make_pair(0, 0));
    visited[0][0] = true;
    cnt[0][0] = 1;

    while (!posQueue.empty()) {
        Pos currentPos = posQueue.front();
        posQueue.pop();

        // 먼저 도착한다면 
        if (currentPos.first == maps.size() - 1 && currentPos.second == maps[currentPos.first].size() - 1) {
            arrived = cnt[currentPos.first][currentPos.second];
            return;
        }

        for (int i = 0; i < 4; i++) {
            int dirY = currentPos.first + dy[i];
            int dirX = currentPos.second + dx[i];
            // map 범위를 벗어났는지 확인
            if (checkOutOfRange(dirY, dirX, maps.size(), maps[currentPos.first].size())) continue;
            // 벽인지 확인
            if (maps[dirY][dirX] == 0) continue;
            // 방문했던 지역인지 확인
            if (visited[dirY][dirX]) continue;

            posQueue.push(make_pair(dirY, dirX));
            visited[dirY][dirX] = true;
            cnt[dirY][dirX] = cnt[currentPos.first][currentPos.second] + 1;
        }
    }
}

int solution(vector<vector<int> > maps)
{   
    for (int i = 0; i < maps.size(); i++) {
        vector<int> vec;
        cnt.push_back(vec);
        for (int j = 0; j < maps[i].size(); j++) {
            cnt[i].push_back(0);
        }
    }
    bfs(maps);
    int answer = (arrived == INT_MAX) ? -1 : arrived;
    return answer;
}

int main()
{
    vector<vector<int>> maps = {
            {1, 0, 1, 1, 1},
            {1, 0, 1, 0, 1},
            {1, 0, 1, 1, 1},
            {1, 1, 1, 0, 0},
            {0, 0, 0, 1, 1}
    };
    std::cout << solution(maps);
}