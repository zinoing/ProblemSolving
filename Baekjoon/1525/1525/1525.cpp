// 1525.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
set<string> visited;

struct Info {
    vector<vector<int>> m_puzzle;
    pair<int, int> m_emptyPlace;
    int m_cnt;

    Info(vector<vector<int>> puzzle, pair<int, int> emptyPlace, int cnt) : m_puzzle(puzzle), m_emptyPlace(emptyPlace), m_cnt(cnt) {}
};

bool checkOutOfRange(int y, int x) {
    return (y >= 3 || y < 0 || x >= 3 || x < 0);
}

bool areAllPiecesSet(vector<vector<int>> puzzle) {
    int idx = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (puzzle[i][j] == idx % 9) {
                idx += 1;
            }
            else return false;
        }
    }

    return (idx == 10);
}

string toString(vector<vector<int>> puzzle) {
    string str;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            str += puzzle[i][j];
        }
    }

    return str;
}

int bfs(Info infoArg) {
    // check
    queue<Info> q;
    q.push(infoArg);

    while (!q.empty()) {
        Info info = q.front();
        q.pop();

        vector<vector<int>> puzzle = info.m_puzzle;
        pair<int, int> emptyPlace = info.m_emptyPlace;
        int cnt = info.m_cnt;

        /*cout << '\n';
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << puzzle[i][j] << ' ';
            }
            cout << '\n';
        }*/

        if (areAllPiecesSet(puzzle)) {
            return info.m_cnt;
        }

        for (int i = 0; i < 4; i++) {
            int dirY = emptyPlace.first + dy[i];
            int dirX = emptyPlace.second + dx[i];

            if (!checkOutOfRange(dirY, dirX)) {
                // swap
                vector<vector<int>> backupPuzzle = puzzle;

                int temp = puzzle[dirY][dirX];
                puzzle[emptyPlace.first][emptyPlace.second] = temp;
                puzzle[dirY][dirX] = 0;

                string puzzleStr = toString(puzzle);
                if (visited.find(puzzleStr) == visited.end()) {
                    visited.insert(toString(puzzle));

                    Info newInfo = Info(puzzle, make_pair(dirY, dirX), cnt + 1);
                    q.push(newInfo);

                }

                puzzle = backupPuzzle;
            }
        }
    }

    return -1;
}

int main()
{
    vector<vector<int>> puzzle(3);
    pair<int, int> emptyPlace;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int piece;
            cin >> piece;

            if (piece == 0)
                emptyPlace = make_pair(i, j);
            puzzle[i].push_back(piece);
        }
    }

    cout << bfs(Info(puzzle, emptyPlace, 0));
}