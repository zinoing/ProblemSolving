// 16236.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
using namespace std;

struct Shark {
    pair<int, int> pos;
    int numOfFishEaten;
    int size;

    Shark() {
        pos = make_pair(0, 0);
        numOfFishEaten = 0;
        size = 2;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int space[21][21];
    int visited[21][21];
    int ans = 0;

    Shark babyShark;
    priority_queue<int, vector<int>, greater<int>> fishesLeft;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int input;
            cin >> input;

            if (input == 9) {
                babyShark.pos = make_pair(i, j);
                space[i][j] = 0;
                continue;
            }

            if (input != 0 && input != 9) {
                fishesLeft.push(input);
            }

            space[i][j] = input;
        }
    }

    // visited 초기화
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = 0;
        }
    }

    int dy[4] = { -1, 0, 0, 1 };
    int dx[4] = { 0, -1, 1, 0 };

    queue<pair<int, int>> movableQ;
    movableQ.push(babyShark.pos);

    while (!movableQ.empty()) {
        pair<int, int> currentPos = movableQ.front();
        movableQ.pop();
        int immovableCnt = 0;

        // 이동이 이뤄지지 않은 경우, 더 이상 먹을 물고기가 없는 경우
        if (immovableCnt == 4 || fishesLeft.empty() || (!fishesLeft.empty() && fishesLeft.top() >= babyShark.size)) {
            ans = visited[currentPos.first][currentPos.second];
            break;
        }

        for (int i = 0; i < 4; i++) {

            pair<int, int> nextPos = make_pair(currentPos.first + dy[i], currentPos.second + dx[i]);

            // 범위 밖 체크
            if (nextPos.first >= N || nextPos.second >= N ||
                nextPos.first < 0 || nextPos.second < 0) {
                ++immovableCnt;
                continue;
            }

            // 이동 불가능
            int temp = space[nextPos.first][nextPos.second];
            if (temp > babyShark.size) {
                ++immovableCnt;
                continue;
            }

            // 이동 가능
            if (temp == 0 || temp == babyShark.size) {
                /*
                switch (i) {
                case 0:
                    cout << "up" << '\n';
                    break;
                case 1:
                    cout << "left" << '\n';
                    break;
                case 2:
                    cout << "right" << '\n';
                    break;
                case 3:
                    cout << "down" << '\n';
                    break;
                }
                */
                movableQ.push(nextPos);

                if(!visited[nextPos.first][nextPos.second])
                    visited[nextPos.first][nextPos.second] = visited[currentPos.first][currentPos.second] + 1;
            }

            // 잡아 먹기 가능
            if (temp != 0 && temp < babyShark.size) {
                cout << "eat " << temp <<  " nextPos: " << nextPos.first << ", " << nextPos.second << '\n';

                // 먹은 물고기 제거
                space[nextPos.first][nextPos.second] = 0;
                fishesLeft.pop();

                movableQ = queue<pair<int, int>>(); // 큐 초기화

                if (!visited[nextPos.first][nextPos.second])
                    visited[nextPos.first][nextPos.second] = visited[currentPos.first][currentPos.second] + 1;
                int moveCnt = visited[nextPos.first][nextPos.second];

                // visited 초기화
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        visited[i][j] = 0;
                    }
                }   

                movableQ.push(nextPos); // 이동한 위치에서 시작하게끔 입력
                visited[nextPos.first][nextPos.second] = moveCnt;

                // 상어 크기 체크
                ++babyShark.numOfFishEaten;
                if (babyShark.numOfFishEaten == babyShark.size) {
                    ++babyShark.size;
                    babyShark.numOfFishEaten = 0;
                }

                break;
            }
        }
    }

    cout << ans;
}