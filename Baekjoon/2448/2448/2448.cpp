// 2448.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

char map[3072][6144];
int N;

typedef pair<int, int> Pos;

void initMap() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 2 * N - 1; ++j) {
            map[i][j] = ' ';
        }
    }
}

void drawMap() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 2 * N-1; ++j) {
            cout << map[i][j];
        }
        cout << '\n';
    }
}

void drawTree(int N, Pos startPos) {
    if (N == 3) {
        map[startPos.first][startPos.second + 2] = '*';
        map[startPos.first+1][startPos.second + 1] = '*';
        map[startPos.first+1][startPos.second + 3] = '*';
        map[startPos.first+2][startPos.second] = '*';
        map[startPos.first+2][startPos.second + 1] = '*';
        map[startPos.first+2][startPos.second + 2] = '*';
        map[startPos.first+2][startPos.second + 3] = '*';
        map[startPos.first+2][startPos.second + 4] = '*';
        return;
    }
    drawTree(N / 2, Pos(startPos.first, startPos.second + (2 * N - 1) / 4 + 1));
    drawTree(N / 2, Pos(startPos.first + N/2, startPos.second));
    drawTree(N / 2, Pos(startPos.first + N/2, startPos.second + (2 * N - 1)/2 + 1));
    return;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    initMap();
    drawTree(N, Pos(0, 0));
    drawMap();

    return 0;
}