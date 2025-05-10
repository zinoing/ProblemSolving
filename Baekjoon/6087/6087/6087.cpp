// 6087.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <limits.h>
using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int W, H;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> W >> H;
    vector<vector<char>> map(H, vector<char>(W));
    vector<vector<vector<int>>> mirrors(H, vector<vector<int>>(W, vector<int>(4, INT_MAX)));
    vector<pair<int, int>> cPos;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 'C')
                cPos.emplace_back(i, j);
        }
    }

    queue<tuple<int, int, int>> q;
    int sy = cPos[0].first, sx = cPos[0].second;
    int ey = cPos[1].first, ex = cPos[1].second;

    for (int i = 0; i < 4; ++i) {
        mirrors[sy][sx][i] = 0;
        q.emplace(sy, sx, i);
    }

    while (!q.empty()) {
        auto info = q.front(); q.pop();

        int y = get<0>(info);
        int x = get<1>(info);
        int dir = get<2>(info);

        for (int i = 0; i < 4; ++i) {
            int dirY = y + dy[i];
            int dirX = x + dx[i];

            // 범위 확인
            if (dirY < 0 || dirY >= H || dirX < 0 || dirX >= W) continue;

            // 벽 확인
            if (map[dirY][dirX] == '*') continue;

            // 방향이 다를 경우 mirror count 1 추가
            int mirrorCount = mirrors[y][x][dir] + (dir != i);
            if (mirrors[dirY][dirX][i] > mirrorCount) {
                mirrors[dirY][dirX][i] = mirrorCount;
                q.emplace(dirY, dirX, i);
            }
        }
    }

    int result = INT_MAX;
    for (int i = 0; i < 4; ++i)
        result = min(result, mirrors[ey][ex][i]);

    cout << result << '\n';
    return 0;
}
