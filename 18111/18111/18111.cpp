// 18111.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, B;
    cin >> N >> M >> B;

    int** ground = new int* [N];
    for (int i = 0; i < N; i++) {
        ground[i] = new int[M];
    }
    int numOfBlocks;
    auto minHeight = INT_MAX;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> numOfBlocks;
            ground[i][j] = numOfBlocks;

            if (minHeight > ground[i][j]) {
                minHeight = ground[i][j];
            }
        }
    }

    auto remove = 0;
    auto fill = 0;
    auto leastTime = INT_MAX;
    auto mostHeight = INT_MAX;

    for (int h = minHeight; h <= 256; h++) {
        remove = 0;
        fill = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                // h보다 높다면
                if (ground[i][j] > h) {
                    remove += (ground[i][j] - h);
                }

                if (ground[i][j] < h) {
                    fill += (h - ground[i][j]);
                }
            }
        }

        if (remove + B >= fill) {
            int time = 2 * remove + fill;
            if (leastTime >= time) {
                leastTime = time;
                mostHeight = h;
            }
        }
    }

    cout << leastTime << ' ' << mostHeight;

    for (int i = 0; i < N; i++) {
        delete ground[i];
    }
    delete[] ground;
}