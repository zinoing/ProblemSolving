// 15683.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define MAX 65
#include <iostream>
#include <vector>
using namespace std;

int N, M;
int numOfCCTVs;
int minBlindSpots = MAX;
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int map[9][9];

int findBlindSpots() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0)
                ++cnt;
        }
    }

    return cnt;
}

bool checkOutOfRange(int y, int x) {
    if (y >= N || y < 0 || x >= M || x < 0)
        return true;

    return false;
}

bool wallOnFront(int y, int x) {
    if (map[y][x] == 6)
        return true;

    return false;
}

bool cctvOnFront(int y, int x) {
    if (map[y][x] < 6 && map[y][x] > 0)
        return true;

    return false;
}

enum class CCTV_Type {
    first = 1,
    second,
    third,
    fourth,
    fifth,
};

class CCTV {
    CCTV_Type type;
    int y, x;
    int dir; 

public:

    CCTV(CCTV_Type cctvType, int cctvY, int cctvX) : type(cctvType), y(cctvY), x(cctvX), dir(0) {}

    void watch() {
        int dirY = y;
        int dirX = x;

        switch (type) {
        case CCTV_Type::first:
            while (true) {
                dirY += dy[dir];
                dirX += dx[dir];
                if (checkOutOfRange(dirY, dirX) || wallOnFront(dirY, dirX)) break;
                if (cctvOnFront(dirY, dirX)) continue;
                map[dirY][dirX] = 9;
            }
            break;
        case CCTV_Type::second:
            for (int k = 0; k < 2; k++) {
                dirY = y;
                dirX = x;
                while (true) {
                    dirY += dy[(dir + k * 2) % 4];
                    dirX += dx[(dir + k * 2) % 4];
                    if (checkOutOfRange(dirY, dirX) || wallOnFront(dirY, dirX)) break;
                    if (cctvOnFront(dirY, dirX)) continue;
                    map[dirY][dirX] = 9;
                }
            }
            break;
        case CCTV_Type::third:
            for (int k = 0; k < 2; k++) {
                dirY = y;
                dirX = x;
                while (true) {
                    dirY += dy[(dir + k) % 4];
                    dirX += dx[(dir + k) % 4];
                    if (checkOutOfRange(dirY, dirX) || wallOnFront(dirY, dirX)) break;
                    if (cctvOnFront(dirY, dirX)) continue;
                    map[dirY][dirX] = 9;
                }
            }
            break;
        case CCTV_Type::fourth:
            for (int k = 0; k < 3; k++) {
                dirY = y;
                dirX = x;
                while (true) {
                    dirY += dy[(dir + k) % 4];
                    dirX += dx[(dir + k) % 4];
                    if (checkOutOfRange(dirY, dirX) || wallOnFront(dirY, dirX)) break;
                    if (cctvOnFront(dirY, dirX)) continue;
                    map[dirY][dirX] = 9;
                }
            }
            break;
        case CCTV_Type::fifth:
            for (int k = 0; k < 4; k++) {
                dirY = y;
                dirX = x;
                while (true) {
                    dirY += dy[k];
                    dirX += dx[k];
                    if (checkOutOfRange(dirY, dirX) || wallOnFront(dirY, dirX)) break;
                    if (cctvOnFront(dirY, dirX)) continue;
                    map[dirY][dirX] = 9;
                }
            }
            break;
        }
    }

    void rotate() {
        dir = (dir + 1) % 4;
    }
};

vector<CCTV> cctvs;

void dfs(int depth) {
    if (depth == numOfCCTVs) {
        int blindSpots = findBlindSpots();
        minBlindSpots = min(minBlindSpots, blindSpots);

        return;
    }
    int backupMap[9][9];
    copy(&map[0][0], &map[0][0] + 9 * 9, &backupMap[0][0]);

    for (int i = 0; i < 4; i++) {
        cctvs[depth].rotate();
        cctvs[depth].watch();

        dfs(depth + 1);

        copy(&backupMap[0][0], &backupMap[0][0] + 9 * 9, &map[0][0]);
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int input;
            cin >> input;
            map[i][j] = input;
            if (input < 6 && input > 0) {
                ++numOfCCTVs;
                CCTV cctv = CCTV((CCTV_Type)input, i, j);
                cctvs.push_back(cctv);
            }
        }
    }

    dfs(0);

    cout << minBlindSpots;
}