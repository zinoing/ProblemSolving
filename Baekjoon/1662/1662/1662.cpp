// 1662.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

string str;
int len[51];
int lenIdx = 0;
stack<char> letters;
int numOfLettersInParentheses;

void Solve(int idx) {
    numOfLettersInParentheses = 0;

    while (1) {
        char letter = letters.top();
        if (letter == '(') {
            letters.pop();
            break;
        }
        ++numOfLettersInParentheses;
        letters.pop();
    }

    for (int i = idx; i < 51; i++) {
        if (len[i] == 0) break;
        numOfLettersInParentheses += len[i];
        len[i] = 0;
    }

    int count = (int)letters.top() - '0';
    letters.pop();

    len[--lenIdx] += count * numOfLettersInParentheses;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> str;

    char input;
    int idx = 0;
    while (idx < str.size()) {
        input = str[idx];

        if (input == ')') {
            Solve(lenIdx);
        }
        else if (input == '(') {
            ++lenIdx;
            letters.push(input);
        }
        else {
            letters.push(input);
        }
        idx++;
    }

    while (!letters.empty()) {
        ++len[0];
        letters.pop();
    }

    cout << len[0];

    return 0;
}