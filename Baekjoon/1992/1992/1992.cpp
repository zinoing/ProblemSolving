// 1992.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

using namespace std;

string compress(int** board, int boardSize, int y, int x) {
    int half = boardSize / 2;

    if (half == 0) // boardSize가 1인 경우
        return to_string(board[y][x]);

    string upperLeft = compress(board, half, y, x);
    string upperRight = compress(board, half, y, x + half);
    string lowerLeft = compress(board, half, y + half, x);
    string lowerRight = compress(board, half, y + half, x + half);

    if (upperLeft == upperRight && upperLeft == lowerLeft && upperLeft == lowerRight && 
        (upperLeft.size() == 1 && upperRight.size() == 1 && lowerLeft.size() == 1 && lowerRight.size() == 1)) {
        return upperLeft;
    }

    return '(' + upperLeft + upperRight + lowerLeft + lowerRight + ')';
}


int main()
{
    int boardSize;
    cin >> boardSize;
    cin.ignore();

    int** board;
    board = new int*[boardSize];
    for (int i = 0; i < boardSize; ++i) {
        board[i] = new int[boardSize];
    }

    for (int i = 0; i < boardSize; ++i) {
        string str;
        getline(cin, str);

        for (int j = 0; j < boardSize; ++j) {
            board[i][j] = str[j] - '0';
        }
    }

    cout << compress(board, boardSize, 0, 0);

    for (int i = 0; i < boardSize; ++i) {
        delete board[i];
    }
    delete[] board;
}