// 20327.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int N, R;
int mapSize;
vector<vector<int>> map;
vector<pair<int, int>> commands(1001);

void upsideDown(int size) {
    vector<int> line;

    for (int i = 0; i < mapSize; i += size) {
        for (int j = 0; j < size/2; ++j) {
            line = map[i + j];
            map[i + j] = map[i + size - 1 - j];
            map[i + size - 1 - j] = line;
        }
    }
    return;
}

void leftRightInversion(int size) {
    int temp;

    for (int i = 0; i < mapSize; ++i) {
        for (int j = 0; j < mapSize; j += size) {
            for (int k = 0; k < size / 2; ++k) {
                temp = map[i][j + k];
                map[i][j + k] = map[i][j + size - 1 - k];
                map[i][j + size - 1 - k] = temp;
            }
        }
    }
    return;
}

void rotateClockwise(int size) {
    int temp = 0;
    vector<vector<int>> tempMap(mapSize, vector<int>(mapSize));

    for (int i = 0; i < mapSize; i += size) {
        for (int j = 0; j < mapSize; j += size) {

            for (int c = 0; c < size; ++c) {
                for (int r = 0; r < size; ++r) {
                    tempMap[i + r][j + size - 1 - c] = map[i + c][j + r];
                }
            }
        }
    }

    map = tempMap;

    return;
}

void rotateCounterClockwise(int size) {
    int temp = 0;
    vector<vector<int>> tempMap(mapSize, vector<int>(mapSize));

    for (int i = 0; i < mapSize; i += size) {
        for (int j = 0; j < mapSize; j += size) {

            for (int c = 0; c < size; ++c) {
                for (int r = 0; r < size; ++r) {
                    tempMap[i - r + size - 1][j + c] = map[i + c][j + r];
                }
            }
        }
    }

    map = tempMap;

    return;
}

void upsideDownByBlock(int size) {
    vector<int> line;

    for (int i = 0; i < mapSize/2; i += size) {
        for (int j = 0; j < size; ++j) {
            line = map[i + j];
            map[i + j] = map[mapSize - size - i + j];
            map[mapSize - size - i + j] = line;
        }
    }
    return;
}

void leftRightInversionByBlock(int size) {
    int temp;

    for (int i = 0; i < mapSize; ++i) {
        for (int j = 0; j < mapSize/2; j += size) {
            for (int k = 0; k < size; ++k) {
                temp = map[i][j + k];
                map[i][j + k] = map[i][mapSize - size - j + k];
                map[i][mapSize - size - j + k] = temp;
            }
        }
    }
    return;
}

void rotateClockwiseByBlock(int size) {

    rotateClockwise(mapSize);
    rotateCounterClockwise(size);

    return;
}

void rotateCounterClockwiseByBlock(int size) {

    rotateCounterClockwise(mapSize);
    rotateClockwise(size);

    return;
}

void solve(pair<int, int> command) {
    int size = pow(2, command.second);
    switch (command.first) {
    case 1:
        upsideDown(size);
        break;
    case 2:
        leftRightInversion(size);
        break;
    case 3:
        rotateClockwise(size);
        break;
    case 4:
        rotateCounterClockwise(size);
        break;
    case 5:
        upsideDownByBlock(size);
        break;
    case 6:
        leftRightInversionByBlock(size);
        break;
    case 7:
        rotateClockwiseByBlock(size);
        break;
    case 8:
        rotateCounterClockwiseByBlock(size);
        break;
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> R;

    mapSize = pow(2, N);
    map.resize(mapSize);
    for (int i = 0; i < mapSize; ++i) {
        map[i].resize(mapSize);
    }
    
    for (int i = 0; i < mapSize; ++i) {
        for (int j = 0; j < mapSize; ++j) {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i <= R; ++i) {
        cin >> commands[i].first >> commands[i].second;
        solve(commands[i]);
    }

    for (int i = 0; i < mapSize; ++i) {
        for (int j = 0; j < mapSize; ++j) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}