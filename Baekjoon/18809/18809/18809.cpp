// 18809.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#define GREEN 3
#define RED 4
#define FLOWER 5

using namespace std;

int n, m, g, r;
vector<pair<int, int>> fertileSoil;

int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };
int maxFlower = 0;

bool checkOutOfRange(vector<vector<int>> garden, int y, int x) {
    if (y >= n || y < 0 || x >= m || x < 0)
        return true;

    // 호수일 경우 or FLOWER일 경우
    if (garden[y][x] == 0 || garden[y][x] == FLOWER) {
        return true;
    }
    return false;
}

int getFlower(vector<vector<int>> garden, vector<pair<int, int>> gSpread, vector<pair<int, int>> rSpread) {

    vector<pair<int, int>> tempSpread;
    int numOfFlowers = 0;

    do {
        tempSpread.clear();

        // 초록색 배양액을 먼저 상하좌우로 spread
        for (auto pos : gSpread) {
            if (garden[pos.first][pos.second] == FLOWER) continue;

            for (int i = 0; i < 4; ++i) {
                int dirY = pos.first + dy[i];
                int dirX = pos.second + dx[i];

                if (checkOutOfRange(garden, dirY, dirX)) continue;
                if (garden[dirY][dirX] == GREEN) continue;
                if (garden[dirY][dirX] == RED) continue;

                tempSpread.push_back(make_pair(dirY, dirX));
                garden[dirY][dirX] = GREEN;
            }
        }

        gSpread = tempSpread;
        tempSpread.clear();

        // 붉은색 배양액을 상하좌우로 spread
        for (auto pos : rSpread) {
            if (garden[pos.first][pos.second] == FLOWER) continue;

            for (int i = 0; i < 4; ++i) {
                int dirY = pos.first + dy[i];
                int dirX = pos.second + dx[i];

                if (checkOutOfRange(garden, dirY, dirX)) continue;
                if (garden[dirY][dirX] == RED) continue;

                // 초록색 배양액을 만난다면 flower 탄생
                if (garden[dirY][dirX] == GREEN) {
                    for (auto pos : gSpread) {
                        if (pos != make_pair(dirY, dirX)) continue;
                        garden[dirY][dirX] = FLOWER;
                        ++numOfFlowers;
                    }
                    continue;
                }

                tempSpread.push_back(make_pair(dirY, dirX));
                garden[dirY][dirX] = RED;
            }
        }

        rSpread = tempSpread;
    } while (!tempSpread.empty());

    return numOfFlowers;
}

void selectSoil(int start, vector<vector<int>> garden, vector<pair<int, int>> gSpread, vector<pair<int, int>> rSpread) {

    // 배양액을 다 사용하였거나 남은 배양액 보다 땅이 적을 경우 종료
    if ((g == 0 && r == 0) || fertileSoil.size() - start < g + r) {
        int numOfFlowers = getFlower(garden, gSpread, rSpread);
        maxFlower = max(maxFlower, numOfFlowers);
        return;
    }

    pair<int, int> pos = fertileSoil[start];
    int y = pos.first;
    int x = pos.second;
     
    if (g > 0) {
        int origin = garden[y][x];
        garden[y][x] = GREEN;
        --g;
        gSpread.push_back(pos);
        
        selectSoil(start + 1, garden, gSpread, rSpread);
        
        gSpread.pop_back();
        ++g;
        garden[y][x] = origin;
    }

    if (r > 0) {
        int origin = garden[y][x];
        garden[y][x] = RED;
        --r;
        rSpread.push_back(pos);
        
        selectSoil(start + 1, garden, gSpread, rSpread);
        
        rSpread.pop_back();
        ++r;
        garden[y][x] = origin;
    }

    selectSoil(start + 1, garden, gSpread, rSpread);

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> g >> r;

    vector<vector<int>> garden(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> garden[i][j];

            if (garden[i][j] == 1) {
                fertileSoil.push_back(make_pair(i, j));
            }
        }
    }

    vector<pair<int, int>> gSpread;
    vector<pair<int, int>> rSpread;
    selectSoil(0, garden, gSpread, rSpread);

    cout << maxFlower;

    return 0;
}