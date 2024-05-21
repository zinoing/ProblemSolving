#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define INT_MAX 2147483647

int width;
int height;
char map[1001][1001];
int visited[1001][1001] = { false, };
bool onFire[1001][1001] = { false, };
queue<pair<int, int>> fireQ;

void spreadFire() {

    int numOfFire = fireQ.size();

    for(int i=0; i<numOfFire; i++) {
        pair<int, int> fire = fireQ.front();
        fireQ.pop();

        if (!onFire[fire.first - 1][fire.second] && map[fire.first - 1][fire.second] == '.' && fire.first - 1 >= 0) {
            fireQ.push(make_pair(fire.first - 1, fire.second));
            onFire[fire.first - 1][fire.second] = true;
        }

        if (!onFire[fire.first + 1][fire.second] && map[fire.first + 1][fire.second] == '.' && fire.first + 1 < height) {
            fireQ.push(make_pair(fire.first + 1, fire.second));
            onFire[fire.first + 1][fire.second] = true;
        }

        if (!onFire[fire.first][fire.second - 1] && map[fire.first][fire.second - 1] == '.' && fire.second - 1 >= 0) {
            fireQ.push(make_pair(fire.first, fire.second - 1));
            onFire[fire.first][fire.second - 1] = true;
        }

        if (!onFire[fire.first][fire.second + 1] && map[fire.first][fire.second + 1] == '.' && fire.second - 1 < width) {
            fireQ.push(make_pair(fire.first, fire.second + 1));
            onFire[fire.first][fire.second + 1] = true;
        }
    }
}

void bfs(pair<int, int> start) {
    pair<int, int> previous;
    queue<pair<int, int> > q;
    int previousCount = 1;
    int currCount = 0;

    q.push(start);

    while (!q.empty()) {

        previous = q.front();
        q.pop();
        --previousCount;

        if (previous.first == 0 || previous.first == height - 1 || previous.second == 0 || previous.second == width - 1) {
            cout << visited[previous.first][previous.second] + 1 << endl;
            return;
        }

        // 위로 움직일 수 있는지 확인
        if (!visited[previous.first - 1][previous.second] && !onFire[previous.first - 1][previous.second] && previous.first - 1 >= 0 && map[previous.first - 1][previous.second] == '.') {
            visited[previous.first - 1][previous.second] = visited[previous.first][previous.second] + 1;
            q.push(make_pair(previous.first - 1, previous.second));
            ++currCount;
        }

        // 아래로 움직일 수 있는지 확인
        if (!visited[previous.first + 1][previous.second] && !onFire[previous.first + 1][previous.second] && previous.first + 1 < height && map[previous.first + 1][previous.second] == '.') {
            visited[previous.first + 1][previous.second] = visited[previous.first][previous.second] + 1;
            q.push(make_pair(previous.first + 1, previous.second));
            ++currCount;
        }

        // 왼쪽으로 움직일 수 있는지 확인
        if (!visited[previous.first][previous.second - 1] && !onFire[previous.first][previous.second - 1] && previous.second - 1 >= 0 && map[previous.first][previous.second - 1] == '.') {
            visited[previous.first][previous.second - 1] = visited[previous.first][previous.second] + 1;
            q.push(make_pair(previous.first, previous.second - 1));
            ++currCount;

        }

        // 오른쪽으로 움직일 수 있는지 확인
        if (!visited[previous.first][previous.second + 1] && !onFire[previous.first][previous.second + 1] && previous.second + 1 < width && map[previous.first][previous.second + 1] == '.') {
            visited[previous.first][previous.second + 1] = visited[previous.first][previous.second] + 1;
            q.push(make_pair(previous.first, previous.second + 1));
            ++currCount;
        }

        // 불이 번짐
        if (previousCount == 0) {
            previousCount = currCount;
            currCount = 0;
            spreadFire();
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testCase;
    cin >> testCase;

    for (int i = 0; i < testCase; i++) {
        cin >> width >> height;

        char input;
        pair<int, int> start;

        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                cin >> input;

                // 시작 위치 저장
                if (input == '@') {
                    start = make_pair(j, k);
                }
                if (input == '*') { 
                    visited[j][k] = true;
                    fireQ.push(make_pair(j, k));
                }
                if (input == '#') {
                    visited[j][k] = true;
                }
                map[j][k] = input;
            }
        }

        spreadFire();
        bfs(start);

        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                map[j][k] = 0;
                visited[j][k] = false;
                onFire[j][k] = false;
            }
        }

        int queueSize = fireQ.size();
        for (int i = 0; i < queueSize; i++) {
            fireQ.pop();
        }

    }
    return 0;
}
