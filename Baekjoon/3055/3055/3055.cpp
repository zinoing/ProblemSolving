// 3055.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
using namespace std;

int R, C;
char map[51][51];
bool visited[51][51];

int dy[4] = { -1, 1, 0, 0, };
int dx[4] = { 0, 0, -1, 1 };

typedef pair<int, int> Pos;
Pos bieberPos;
Pos hedgehogStartPos;
queue<Pos> flood;
queue<Pos> nextFlood;
queue<Pos> hedgehogPosQueue;
queue<Pos> hedgehogNextPosQueue;


bool checkOutOfRange(int y, int x) {
    return (y >= R || y < 0 || x >= C || x < 0);
}

void floodOccurs() {
    if (nextFlood.empty()) return;

    flood = nextFlood;
    while (!nextFlood.empty()) {
        nextFlood.pop();
    }

    while (!flood.empty()) {
        Pos water = flood.front();
        flood.pop();

        for (int i = 0; i < 4; i++) {
            int dirY = dy[i] + water.first;
            int dirX = dx[i] + water.second;
            if (!checkOutOfRange(dirY, dirX) && map[dirY][dirX] != '*' && map[dirY][dirX] != 'D' && map[dirY][dirX] != 'X') {
                map[dirY][dirX] = '*';
                nextFlood.push(make_pair(dirY, dirX));
            }
        }
    }
}

int findWayToBieber(int cnt) {

    while (!hedgehogNextPosQueue.empty()) {

        hedgehogPosQueue = hedgehogNextPosQueue;
        ++cnt;
        while (!hedgehogNextPosQueue.empty()) {
            hedgehogNextPosQueue.pop();
        }

        while (!hedgehogPosQueue.empty()) {

            Pos hedgehogPos = hedgehogPosQueue.front();
            hedgehogPosQueue.pop();

            if (hedgehogPos.first == bieberPos.first && hedgehogPos.second == bieberPos.second) {
                return cnt;
            }

            if (map[hedgehogPos.first][hedgehogPos.second] == '*')
                continue;

            for (int i = 0; i < 4; i++) {
                int dirY = dy[i] + hedgehogPos.first;
                int dirX = dx[i] + hedgehogPos.second;

                char bakupMap[51][51];
                copy(&map[0][0], &map[0][0] + 51 * 51, &bakupMap[0][0]);

                if (!checkOutOfRange(dirY, dirX) && map[dirY][dirX] != '*' && map[dirY][dirX] != 'X' && !visited[dirY][dirX]) {
                    // move
                    map[hedgehogPos.first][hedgehogPos.second] = '.';
                    map[dirY][dirX] = 'S';
                    visited[dirY][dirX] = true;

                    hedgehogNextPosQueue.push(make_pair(dirY, dirX));

                    copy(&bakupMap[0][0], &bakupMap[0][0] + 51 * 51, &map[0][0]);
                }
            }
        }

        floodOccurs();
    }

    return -1;
}

int main()
{
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char input;
            cin >> input;

            if (input == 'D')
                bieberPos = make_pair(i, j);

            if (input == 'S') {
                hedgehogStartPos = make_pair(i, j);
                map[i][j] = '.';
                visited[i][j] = false;
                continue;
            }

            if (input == '*')
                nextFlood.push(make_pair(i, j));

            map[i][j] = input;
            visited[i][j] = false; 
        }
    }

    // if, nowhere to go print out "KAKTUS"
    hedgehogNextPosQueue.push(hedgehogStartPos);
    visited[hedgehogStartPos.first][hedgehogStartPos.second] = true;
    int ans = findWayToBieber(-1);
    if (ans == -1) {
        cout << "KAKTUS";
    }
    else cout << ans;
}