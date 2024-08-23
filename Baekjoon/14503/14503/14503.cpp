// 14503.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
using namespace std;

int N, M;
int cleaned[51][51];
int cleanCnt = 0;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

class RobotVacuum {
private:
    pair<int, int> currentPos;
    int currentDir;

public:
    RobotVacuum(int y, int x, int dir) : currentPos(make_pair(y, x)), currentDir(dir) {}

    int Move(int dir) {
        int y = currentPos.first;
        int x = currentPos.second;

        switch (dir) {
        case NORTH:
            y -= 1;
            break;
        case EAST:
            x += 1;
            break;
        case SOUTH:
            y += 1;
            break;
        case WEST:
            x -= 1;
            break;
        }

        if (cleaned[y][x] != 1) {
            currentPos = make_pair(y, x);
        }
        else {
            return -1;
        }

        return 0;
    }

    bool CheckIsSideClean() {
        for (int i = 0; i < 4; i++) {
            int y = currentPos.first + dy[i];
            int x = currentPos.second + dx[i];

            if (!cleaned[y][x]) {
                return false;
            }
        }

        return true;
    }

    void Clean() {
        while (1) {
            // 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
            if (!cleaned[currentPos.first][currentPos.second]) {
                cleaned[currentPos.first][currentPos.second] = 2;
                ++cleanCnt;
            }

            if (CheckIsSideClean()) {
                // 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
                int backward = (currentDir + 2) % 4;
                if (Move(backward) == -1) {
                    // 작동을 멈춘다.
                    break;
                }
            }
            else {
                //반시계 방향으로 90도 회전한다.
                currentDir = (currentDir + 3) % 4;

                int y = currentPos.first;
                int x = currentPos.second;
                switch (currentDir) {
                case NORTH:
                    y -= 1;
                    break;
                case EAST:
                    x += 1;
                    break;
                case SOUTH:
                    y += 1;
                    break;
                case WEST:
                    x -= 1;
                    break;
                }

                if (cleaned[y][x] == 0)
                    currentPos = make_pair(y, x);
            }
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N >> M;
    int y, x, dir;
    cin >> y >> x >> dir;
    RobotVacuum rv(y, x, dir);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            bool isClean;
            cin >> isClean;
            cleaned[i][j] = isClean;
        }
    }

    rv.Clean();

    cout << cleanCnt;
}