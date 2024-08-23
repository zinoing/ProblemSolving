// 7682.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isValid = true;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /*
    x가 o보다 많거나 같다
    x가 승리하거나, o가 승리하거나, 게임판이 다 차면 최종 상태
    */
    
    while (1) {
        string input;
        cin >> input;

        if (!input.compare("end"))
            break;

        vector<char> board;
        int xCount = 0;
        int oCount = 0;
        int emptyCount = 0;

        for (int i = 0; i < 9; i++) {
            switch (input[i]) {
            case 'X':
                ++xCount;
                break;
            case 'O':
                ++oCount;
                break;
            case '.':
                ++emptyCount;
                break;
            }
            board.push_back(input[i]);
        }

        if (oCount > xCount || xCount - oCount > 1) {
            isValid = false;
        }

        bool xWin = false;
        bool oWin = false;

        for (int i = 0; i < 9; i++) {
            if (board[i] == '.')
                continue;

            // 가로줄 확인
            if (i % 3 == 0 && board[i] == board[i + 1] && board[i] == board[i + 2]) {
                (board[i] == 'X' && board[i] != '.') ? xWin = true : oWin = true;
            }

            // 세로줄 확인
            if (i < 3 && board[i] == board[i + 3] && board[i] == board[i + 6]) {
                (board[i] == 'X' && board[i] != '.') ? xWin = true : oWin = true;
            }
        }

        // 대각선 확인
        if (board[0] == board[4] && board[0] == board[8]) {
            board[0] == 'X' ? xWin = true : oWin = true;
        }

        if (board[2] == board[4] && board[2] == board[6]) {
            board[2] == 'X' ? xWin = true : oWin = true;
        }

        if (emptyCount != 0) {
            if (xWin == oWin) {
                isValid = false;
            }
        }
        else {
            if (oWin)
                isValid = false;
        }


        // xCount - oCount == 1이라면 o는 절대 이겨서는 안된다.
        // xCount - oCount == 0이라면 x는 절대 이겨서는 안된다.
        if ((xCount - oCount == 1 && oWin) || (xCount - oCount == 0 && xWin)) {
            isValid = false;
        }

        isValid ? cout << "valid" << '\n' : cout << "invalid" << '\n';
        isValid = true;
    }
}
