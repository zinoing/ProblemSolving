// 16954.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef pair<int, int> Pos;

int dy[9] = { -1, 1, 0, 0, -1 ,1, -1, 1, 0};
int dx[9] = { 0, 0, -1 ,1, -1, 1, 1, -1, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<char>> map(8, vector<char>(8));
    vector<vector<vector<char>>> wallCapture(8, vector<vector<char>>(8, vector<char>(8)));

    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            for (int k = 0; k < 8; ++k)
                wallCapture[i][j][k] = '.';

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cin >> map[i][j];

            if (map[i][j] == '#') wallCapture[0][i][j] = '#';
        }
    }

    for (int i = 1; i < 8; ++i) {

        wallCapture[i] = wallCapture[i - 1];

        for (int j = 7; j >= 0; --j) {
            for (int k = 0; k < 8; ++k) {
                if (wallCapture[i][j][k] == '#') {
                    if (j == 7) {
                        wallCapture[i][j][k] = '.';
                        continue;
                    }
                    wallCapture[i][j + 1][k] = '#';
                    wallCapture[i][j][k] = '.';
                }
            }
        }
    }

    stack<pair<Pos, int>> s;
    s.push(make_pair(Pos(7, 0), 0));

    while (!s.empty()) {
        pair<Pos, int> posNcnt = s.top();
        s.pop();

        Pos currentPos = posNcnt.first;
        int cnt = posNcnt.second;

        // cnt가 8 이상이면 통과
        if (cnt >= 8) {
            cout << 1;
            return 0;
        }

        // 현재 위치가 벽과 충돌하는지 확인
        if (wallCapture[cnt][currentPos.first][currentPos.second] == '#') {
            continue;
        }

        for (int i = 0; i < 9; ++i) {
            int dirY = currentPos.first + dy[i];
            int dirX = currentPos.second + dx[i];

            // 범위를 벗어나거나
            if (dirY >= 8 || dirY < 0 || dirX >= 8 || dirX < 0) {
                continue;
            }

            // 벽과 충돌하거나
            if (wallCapture[cnt][dirY][dirX] == '#') {
                continue;
            }

            s.push(make_pair(Pos(dirY, dirX), cnt + 1));
        }
    }

    cout << 0;
    return 0;
}