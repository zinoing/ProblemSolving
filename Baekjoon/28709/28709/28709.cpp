// 28709.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool checkCorrectStr(string& str, int open, int wildcards, int start, int end) {

    for (int i = start; i <= end; ++i) {
        auto& c = str[i];

        switch (c) {
        case '(':
            ++open;
            break;
        case ')':
            if (open > 0 && wildcards > 0) break;

            if (open > 0) {
                --open;
            }
            else {
                return false;
            }
            break;
        case '?':
            str[i] = '(';
            if (!checkCorrectStr(str, open, wildcards, i, end)) {
                str[i] = ')';
                return checkCorrectStr(str, open, wildcards, i, end);
            }
            else {
                return true;
            }
            break;
        case '*':
            ++wildcards;
            break;
        }
    }

    return open == 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    cin.ignore();

    for (int i = 0; i < T; ++i) {
        string input;
        getline(cin, input);

        string str;
        bool correct = true;
        int star = -1;
        for (int j = 0; j < input.size(); ++j) {
            if (input[j] == '*') {
                // start가 세팅되어있지 않다면 세팅
                if (star == -1) {
                    star = j;

                    // str이 적합하게 짜져 있는지 확인하고, '('와 ')'의 개수를 비교한다.
                    if (!checkCorrectStr(input, 0, 0, 0, j)) {      // *, string 형태, 둘다 틀려야 틀린 것으로 인정
                        correct = false;
                        cout << "NO" << endl;
                        break;
                    }
                }
                // 이전에 star가 나온 적이 있다면
                else {
                    star = j;
                    continue;
                }
            }
            else {
                str += input[j];
            }
        }

        // 이전에 star가 나온적이 있다면
        if (correct && star != -1) {
            correct = false;
            cout << (checkCorrectStr(input, 0, 0, star, input.size() - 1) ? "YES" : "NO") << endl;
        }

        if (correct) {
            cout << (checkCorrectStr(input, 0, 0, 0, input.size() - 1) ? "YES" : "NO") << endl;
        }
    }
}

/*
계속 시간초과가 난다..

눈 여겨 보아야할 특징들
1. '*' 기준 좌측은 '('를 무한정 적용가능하다. 반대로 '*' 기준 우측은 ')'를 무한정 적용가능하다.
2. '?'에 적용될 문자는 재귀적으로 파악하여야 한다. 이때 시간을 절약하는 방식을 계속 고민하여야 한다.

1번 특징을 고려해 볼때
    1.1. string, *의 경우 string은 '('의 개수가 ')'의 개수보다 같거나 많아야 한다. 아닐 시 "NO"를 출력하여야 한다.
    1.2. *,string의 경우 string은 ')'의 개수가 '('의 개수보다 같거나 많아야 한다. 아닐 시 "NO"를 출력하여야 한다.
    1.3. *, string, *의 경우 string은 어떠한 문자열이 와도 안정적이다. (이 경우를 체크하여 해당 구간의 문자열의 연산은 생략해주어야 한다.)

따라서 '*'가 나오기 전까지 '('의 개수와 ')'의 개수를 비교하고
*/