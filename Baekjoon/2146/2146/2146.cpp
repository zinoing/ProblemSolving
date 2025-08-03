// 2146.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define INT_MAX 2147483647
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

typedef pair<int, int> Pos;

int sizeOfMap;
int numOfIslands = 1;
int maximumBirdges;
vector<queue<Pos>> cornersByIslands;
int shortestBridge = INT_MAX;

int map[101][101];
int visited[101][101];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1};

bool checkOutOfRange(Pos pos) {
    return (pos.first >= sizeOfMap || pos.first < 0 || pos.second >= sizeOfMap || pos.second < 0);
}

bool checkIsCorner(Pos pos) {
    for (int i = 0; i < 4; i++) {
        int dirY = pos.first + dy[i];
        int dirX = pos.second + dx[i];

        if (checkOutOfRange(make_pair(dirY, dirX)))
            continue;

        if (map[dirY][dirX] == 0)
            return true;
    }
    return false;
}

queue<Pos> islandBFS(Pos startPos) {
    queue<Pos> poses;
    poses.push(startPos);

    queue<Pos> corners;

    while (!poses.empty()) {
        Pos pos = poses.front();
        poses.pop();

        if (visited[pos.first][pos.second]) continue;

        map[pos.first][pos.second] = numOfIslands;
        visited[pos.first][pos.second] = true;


        if (checkIsCorner(pos)) {
            corners.push(pos);
        }

        for (int i = 0; i < 4; i++) {
            int dirY = pos.first + dy[i];
            int dirX = pos.second + dx[i];

            Pos newPos = make_pair(dirY, dirX);

            if (!checkOutOfRange(newPos) && map[dirY][dirX] != numOfIslands && map[dirY][dirX] != 0) {
                poses.push(newPos);
            }
        }
    }

    return corners;
}

void findTheShortestBridge(queue<Pos> poses, int islandIdx) {
    queue<Pos> nextPoses = poses;
    int cnt = 0;

    memset(visited, 0, sizeof(visited));

    while (!nextPoses.empty()) {
        ++cnt;
        poses = nextPoses;
        while (!nextPoses.empty()) {
            nextPoses.pop();
        }

        while (!poses.empty()) {
            Pos pos = poses.front();
            poses.pop();

            if (map[pos.first][pos.second] != islandIdx && map[pos.first][pos.second] != 0) {
                shortestBridge = min(shortestBridge, cnt);
                continue;
            }

            for (int i = 0; i < 4; i++) {
                int dirY = pos.first + dy[i];
                int dirX = pos.second + dx[i];
                Pos newPos = make_pair(dirY, dirX);

                if (checkOutOfRange(newPos)) continue;
                if (visited[newPos.first][newPos.second]) continue;

                visited[newPos.first][newPos.second] = true;
                nextPoses.push(newPos);
            }
        }
    }
    
}

int main()
{
    cin >> sizeOfMap;

    for (int i = 0; i < sizeOfMap; i++) {
        for (int j = 0; j < sizeOfMap; j++) {
            int input;
            cin >> input;
            map[i][j] = input;
        }
    }

    for (int i = 0; i < sizeOfMap; i++) {
        for (int j = 0; j < sizeOfMap; j++) {
            if (map[i][j] == 1) {
                ++numOfIslands;
                queue<Pos> corners = islandBFS(make_pair(i, j));
                cornersByIslands.push_back(corners);
            }
        }
    }

    numOfIslands -= 2;

    // need to find closest island
    for (int i = 0; i < cornersByIslands.size(); i++) {
        int idlandIdx = map[cornersByIslands[i].front().first][cornersByIslands[i].front().second];
        findTheShortestBridge(cornersByIslands[i], idlandIdx);
    }

    cout << shortestBridge - 2;
}