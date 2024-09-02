// 아이템 줍기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
typedef pair<int, int> Pos;

int dy[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dx[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };
int visited[101][101];

bool checkOufOfRange(int characterY, int characterX) {
    return(characterY < 0 || characterY > 100 || characterX < 0 || characterX > 100);
}

int bfs(vector<vector<int>> maps, int characterX, int characterY, int itemX, int itemY) {
    queue<Pos> posQueue;
    posQueue.push(make_pair(characterY, characterX));
    visited[characterY][characterX] = true;

    while (!posQueue.empty()) {
        Pos currPos = posQueue.front();
        posQueue.pop();

        if (currPos.first == itemY && currPos.second == itemX) {
            return maps[currPos.first][currPos.second] / 2;
        }

        for (int i = 0; i < 4; i++) {
            int newY = currPos.first + dy[i];
            int newX = currPos.second + dx[i];

            if (checkOufOfRange(newY, newX)) continue;
            if (maps[newY][newX] == 0) continue;
            if (visited[newY][newX]) continue;

            posQueue.push(make_pair(newY, newX));
            visited[newY][newX] = true;
            maps[newY][newX] = maps[currPos.first][currPos.second] + 1;
        }
    }
    return 0;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    vector<vector<int>> maps(101, vector<int>(101));

    for (int i = 0; i < rectangle.size(); i++) {
        for (int y = rectangle[i][1] * 2; y <= rectangle[i][3] * 2; y++) {
            for (int x = rectangle[i][0] * 2; x <= rectangle[i][2] * 2; x++) {
                maps[y][x] = 1;
            }
        }
    }

    vector<pair<int, int>> coordinateToRemove;

    for (int i = 0; i < rectangle.size(); i++) {
        for (int y = rectangle[i][1] * 2; y <= rectangle[i][3] * 2; y++) {
            for (int x = rectangle[i][0] * 2; x <= rectangle[i][2] * 2; x++) {
                int cnt = 0;
                for (int i = 0; i < 8; i++) {
                    int newY = y + dy[i];
                    int newX = x + dx[i];
                    if (checkOufOfRange(newY, newX)) continue;
                    if (maps[newY][newX] == 1) ++cnt;
                }

                if (cnt == 8) {
                    coordinateToRemove.push_back(make_pair(y, x));
                }
            }
        }
    }

    for (int i = 0; i < coordinateToRemove.size(); i++) {
        maps[coordinateToRemove[i].first][coordinateToRemove[i].second] = 0;
    }

    int answer = bfs(maps, characterX * 2, characterY * 2, itemX * 2, itemY * 2);

    return answer;
}