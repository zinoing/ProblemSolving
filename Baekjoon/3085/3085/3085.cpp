// 3085.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int N;
int maxCnt = 0;

void checkCnt(int y, int x, vector<vector<char>> board, bool checkRow) {
    // 확인해야 하는 줄은 총 3줄
    int cCnt = 0;
    int pCnt = 0;
    int zCnt = 0;
    int yCnt = 0;

    int check = checkRow ? board[y][0] : board[0][x];

    for (int k = 0; k < N; ++k) {
        int val = checkRow ? board[y][k] : board[k][x];
        switch (val) {
        case 'C':
            if(check == val)
                ++cCnt;
            else {
                cCnt = 1;
            }
            break;
        case 'P':
            if (check == val)
                ++pCnt;
            else {
                pCnt = 1;
            }            
            break;
        case 'Z':
            if (check == val)
                ++zCnt;
            else {
                zCnt = 1;
            }            
            break;
        case 'Y':
            if (check == val)
                ++yCnt;
            else {
                yCnt = 1;
            }            
            break;
        }
        check = val;

        maxCnt = max(cCnt, maxCnt);
        maxCnt = max(pCnt, maxCnt);
        maxCnt = max(zCnt, maxCnt);
        maxCnt = max(yCnt, maxCnt);
    }

    return;
}

int main()
{
    cin >> N;

    vector<vector<char>> board(N, vector<char>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {

            if (j < N - 1) {
                // 행끼리 변경
                int temp = board[i][j];
                board[i][j] = board[i][j + 1];
                board[i][j + 1] = temp;

                // 확인해야 하는 줄은 총 3줄
                checkCnt(i, j, board, true);
                checkCnt(i, j, board, false);
                checkCnt(i, j + 1, board, false);

                // 원래대로 복구
                temp = board[i][j];
                board[i][j] = board[i][j + 1];
                board[i][j + 1] = temp;
            }

            if (i < N - 1) {
                // 열끼리 변경
                int temp = board[i][j];
                board[i][j] = board[i + 1][j];
                board[i + 1][j] = temp;

                // 확인해야 하는 줄은 총 3줄
                checkCnt(i, j, board, false);
                checkCnt(i, j, board, true);
                checkCnt(i + 1, j, board, true);

                // 원래대로 복구
                temp = board[i][j];
                board[i][j] = board[i + 1][j];
                board[i + 1][j] = temp;
            }
        }
    }

    cout << maxCnt;
}