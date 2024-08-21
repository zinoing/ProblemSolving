// 1074.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cmath>
using namespace std;

int N, r, c;

void solve(long long int previousStartPos, pair<int, int> offsets, int cnt) {
    long long int boardSize = pow(2, N - cnt);
    long long int startPos = 0;
    long long int gap = pow(4, N - cnt -1);

    int offsetY = offsets.first;
    int offsetX = offsets.second;

    if (boardSize == 1) {
        cout << previousStartPos;
        return;
    }

    if (r < boardSize / 2 + offsetY) {
        if (c >= boardSize / 2 + offsetX) {
            // 1사분면
            startPos = previousStartPos + gap;
            offsetX += boardSize / 2;
        }
        else {
            // 2사분면
            startPos = previousStartPos;
        }
    }
    else {
        if (c >= boardSize / 2 + offsetX) {
            // 4사분면
            startPos = previousStartPos + 3 * gap;
            offsetY += boardSize / 2;
            offsetX += boardSize / 2;
        }
        else {
            // 3사분면
            startPos = previousStartPos + 2 * gap;
            offsetY += boardSize / 2;
        }
    }

    solve(startPos, make_pair(offsetY, offsetX), cnt + 1);
}

int main()
{
    cin >> N >> r >> c;

    solve(0, make_pair(0, 0), 0);
}