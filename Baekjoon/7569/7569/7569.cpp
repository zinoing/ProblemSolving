// 7569.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
using namespace std;

struct Coord {
    int m_y;
    int m_x;
    int m_z;

    Coord(int y, int x, int z) : m_y(y), m_x(x), m_z(z) {}
};

int M, N, H;
int day = -1;
int boxes[101][101][101];
int dy[6] = { -1, 1, 0, 0, 0, 0 };
int dx[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int todayCnt = 0;
int tomorrowCnt = 0;
queue<Coord> q;

bool checkOuOfRange(int y, int x, int z) {
    if (y >= N || y < 0 || x >= M || x < 0 || z >= H || z < 0)
        return true;

    if (boxes[z][y][x] == -1)
        return true;

    return false;
}

void spread(int y, int x, int z) {
    for (int i = 0; i < 6; i++) {
        int spreadZ = z + dz[i];
        int spreadY = y + dy[i];
        int spreadX = x + dx[i];

        if (!checkOuOfRange(spreadY, spreadX, spreadZ) && boxes[spreadZ][spreadY][spreadX] == 0) {
            boxes[spreadZ][spreadY][spreadX] = 1;
            q.push(Coord(spreadY, spreadX, spreadZ));
            ++tomorrowCnt;
        }
    }
}

bool checkTomatoesAllSpreaded() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (boxes[i][j][k] == 0)
                    return false;
            }
        }
    }

    return true;
}

void bfs() {
    while (!q.empty()) {
        Coord coord = q.front();
        q.pop();
        --todayCnt;

        if (todayCnt <= 0) {
            ++day;
            todayCnt = tomorrowCnt;
            tomorrowCnt = 0;
        }

        if (boxes[coord.m_z][coord.m_y][coord.m_x] == 1) {
            spread(coord.m_y, coord.m_x, coord.m_z);
        }
    }
}

int main()
{
    cin >> M >> N >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                int tomato;
                cin >> tomato;
                boxes[i][j][k] = tomato;
                if (boxes[i][j][k] == 1) {
                    ++tomorrowCnt;
                }
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (boxes[i][j][k] == 1) {
                    q.push(Coord(j, k, i));
                }
            }
        }
    }

    bfs();

    cout << (checkTomatoesAllSpreaded() ? day : -1);
}