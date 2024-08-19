// 1799.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

int boardSize;
int board[11][11];
int maxBishopOnBlackTile;
int maxBishopOnWhiteTile;

int dy[4] = { -1, -1, 1, 1 };
int dx[4] = { 1, -1, 1, -1 };

bool checkOutOfRange(int y, int x) {
    if (y >= boardSize || y < 0 || x >= boardSize || x < 0)
        return true;
    return false;
}

void putBishop(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int dirY = y;
        int dirX = x;
        while (true) {
            dirY += dy[i];
            dirX += dx[i];
            if (checkOutOfRange(dirY, dirX)) break;
            board[dirY][dirX] = 0;
        }
    }
}

void dfs(int row, int col, int numOfBishops, bool isOnBlackTile) {

    if (col >= boardSize) {
        ++row;
        col = col % 2 == 1 ? 0 : 1;
    }

    if (row == boardSize) {
        int* maxBishop = isOnBlackTile ? &maxBishopOnBlackTile : &maxBishopOnWhiteTile;
        *maxBishop = max(*maxBishop, numOfBishops);
        return;
    }
    
    if (board[row][col] == 1) {
        int backupBoard[11][11];
        copy(&board[0][0], &board[0][0] + 11 * 11, &backupBoard[0][0]);
        putBishop(row, col);
        dfs(row, col + 2, numOfBishops + 1, isOnBlackTile);
        copy(&backupBoard[0][0], &backupBoard[0][0] + 11 * 11, &board[0][0]);
    }

    dfs(row, col + 2, numOfBishops, isOnBlackTile);
}

int main()
{
    cin >> boardSize;
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            int block;
            cin >> block;

            board[i][j] = block;
        }
    }

    dfs(0, 0, 0, true);
    dfs(0, 1, 0, false);

    cout << maxBishopOnBlackTile + maxBishopOnWhiteTile;
}