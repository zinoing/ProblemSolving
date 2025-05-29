// 2580.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> sudoku(9, vector<int>(9));
vector<pair<int, int>> emptyBox;

bool dfs(int idx, vector<vector<int>>& sudoku) {
    if (idx == emptyBox.size()) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cout << sudoku[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }

    vector<bool> numsCantUse(10);
    int y = emptyBox[idx].first;
    int x = emptyBox[idx].second;


    for (int i = 0; i < 9; ++i) {
        // 가로줄 체크
        numsCantUse[sudoku[y][i]] = true;
        // 세로줄 체크
        numsCantUse[sudoku[i][x]] = true;
    }

    for (int i = 3 * (y / 3); i < 3 * (y / 3) + 3; ++i) {
        for (int j = 3 * (x / 3); j < 3 * (x / 3) + 3; ++j) {
            numsCantUse[sudoku[i][j]] = true;
        }
    }

    vector<int> possibleNums;

    for (int i = 1; i <= 9; ++i) {
        if (!numsCantUse[i]) {
            possibleNums.push_back(i);
        }
    }

    // possibleNums가 존재하지 않는다면
    if(possibleNums.empty())
        return false;

    // possibleNums가 존재한다면
    int origin = sudoku[y][x];

    for (int num : possibleNums) {
        sudoku[y][x] = num;
        if (dfs(idx + 1, sudoku)) {
            return true;
        }
        sudoku[y][x] = origin;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0) emptyBox.push_back(make_pair(i, j));
        }
    }

    dfs(0, sudoku);
}