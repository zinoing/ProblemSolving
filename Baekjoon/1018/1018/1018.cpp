// 1018.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minCnt = 64;

void checkMin(vector<string> board, char c, int sy, int sx) {
	int cnt = 0;
	for (int y = sy; y < sy + 8; ++y) {
		for (int x = sx; x < sx + 8; ++x) {
			if ((y + x) % 2 == 0) {
				if (board[y][x] != c) ++cnt;
			}
			else {
				if (board[y][x] == c) ++cnt;
			}
		}
	}
	if (cnt < minCnt) minCnt = cnt;
}

int main()
{
    int h, w;
    cin >> h >> w;
    
    vector<string> board(h);

    cin.ignore();
    for (int i = 0; i < h; ++i) {
        getline(cin, board[i]);
    }

    for (int i = 0; i < h - 7; ++i) {
		for (int j = 0; j < w - 7; ++j) {
			checkMin(board, 'B', i, j);
			checkMin(board, 'W', i, j);
		}
    }

	cout << minCnt;

    return 0;
}