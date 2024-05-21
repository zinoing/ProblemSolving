// 7576.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
using namespace std;

int M, N;
int box[1001][1001];
bool visited[1001][1001];
queue<pair<int, int>> q;
int target = 0;
int day = 0;
int numOfRipedTomatoes = 0;
int ans = 0;

int temp;

void bfs() {

    while (!q.empty()) {
        pair<int, int> coord = q.front();
        q.pop();

        // 상
        if (coord.first - 1 >= 0 && box[coord.first - 1][coord.second]==0) {
            box[coord.first - 1][coord.second] = 1;
            q.push(make_pair(coord.first - 1, coord.second));
            visited[coord.first - 1][coord.second] = true;
            ++numOfRipedTomatoes;
        }
        // 하
        if (coord.first + 1 < N && box[coord.first + 1][coord.second] == 0) {
            box[coord.first + 1][coord.second] = 1;
            q.push(make_pair(coord.first + 1, coord.second));
            visited[coord.first + 1][coord.second] = true;
            ++numOfRipedTomatoes;
        }
        //좌
        if (coord.second - 1 >= 0 && box[coord.first][coord.second - 1] == 0) {
            box[coord.first][coord.second - 1] = 1;
            q.push(make_pair(coord.first, coord.second - 1));
            visited[coord.first][coord.second - 1] = true;
            ++numOfRipedTomatoes;
        }
        //우
        if (coord.second + 1 < M && box[coord.first][coord.second + 1] == 0) {
            box[coord.first][coord.second + 1] = 1;
            q.push(make_pair(coord.first, coord.second + 1));
            visited[coord.first][coord.second + 1] = true;
            ++numOfRipedTomatoes;
        }

        --temp;
        if (temp == 0) {
            temp = q.size();
            ++day;

            if (numOfRipedTomatoes == target) {
                ans = day;
                return;
            }

            //cout << "day: " << day << endl;
            //for (int i = 0; i < N; i++) {
            //    for (int j = 0; j < M; j++) {
            //        cout << box[i][j] << ' ';
            //    }
            //    cout << endl;
            //}
        }
    }

    ans = -1;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    target = N * M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = false;
        }
    }


    int input;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> input;
            if (input == -1)
                --target;

            if (input == 1) {
                q.push(make_pair(i, j));
                visited[i][j] = true;
                ++numOfRipedTomatoes;
            }

            box[i][j] = input;
        }
    }

    if (numOfRipedTomatoes == target) {
        ans = 0;
    }
    else{
        temp = q.size();
        bfs();
    }

    cout << ans;
    return 0;
}