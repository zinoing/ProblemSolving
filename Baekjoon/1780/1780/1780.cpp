// 1780.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int N;
int board[2188][2188];

int minusCnt = 0;
int zeroCnt = 0;
int plusCnt = 0;

int checkSquare(int row, int col, int size) {
    int first = board[row][col];

    for (int i = row; i < row + size; ++i) {
        for (int j = col; j < col + size; ++j) {
            if (first != board[i][j]) {
                return -2;
            }
        }
    }

    return first;
}

void solve(int row, int col, int size) {
    if (size == 1) {
        if (board[row][col] < 0) {
            ++minusCnt;
        }
        else if (board[row][col] == 0) {
            ++zeroCnt;
        }
        else {
            ++plusCnt;
        }
    }
    else {
        for (int i = row; i < row + size; i += size / 3) {
            for (int j = col; j < col + size; j += size / 3) {

                int result = checkSquare(i, j, size / 3);

                if (result == -2) {
                    solve(i, j, size / 3);
                }
                else {
                    if (result < 0) {
                        ++minusCnt;
                    }
                    else if (result == 0) {
                        ++zeroCnt;
                    }
                    else {
                        ++plusCnt;
                    }
                }
            }
        }

        if (minusCnt == 9 && zeroCnt == 0 && plusCnt == 0) minusCnt = 1;
        if (minusCnt == 0 && zeroCnt == 9 && plusCnt == 0) zeroCnt = 1;
        if (minusCnt == 0 && zeroCnt == 0 && plusCnt == 9) plusCnt = 1;
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }

    solve(0, 0, N);

    cout << minusCnt << endl;
    cout << zeroCnt << endl;
    cout << plusCnt;
}