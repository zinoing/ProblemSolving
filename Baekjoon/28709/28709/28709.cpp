// 28709.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

enum class STAR_STATUS {
    BEFORE_STRING,
    AFTER_STRING,
    NO_STAR
};

int checkCorrectStr(string& str, int start, int end, STAR_STATUS starStatus, int open = 0) {

    for (int i = start; i <= end; ++i) {
        auto& c = str[i];

        switch (c) {
        case '(':
            ++open;
            break;
        case ')':
            --open;
            if (open < 0) return open;
            break;
        case '?':
            str[i] = '(';
            int result = checkCorrectStr(str, i, end, starStatus, open);
            if (result == 0) return result;

            if (starStatus == STAR_STATUS::BEFORE_STRING) {
                if (result < 0) return result;
            }

            if (starStatus == STAR_STATUS::AFTER_STRING) {
                if (result > 0) return result;
            }

            str[i] = ')';
            result = checkCorrectStr(str, i, end, starStatus, open);
            if (result == 0) return result;

            if (starStatus == STAR_STATUS::BEFORE_STRING) {
                if (result < 0) return result;
            }

            if (starStatus == STAR_STATUS::AFTER_STRING) {
                if (result > 0) return result;
            }

            return result;
            break;
        }
    }

    return open;
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

        bool correct = true;
        int star = -1;
        for (int j = 0; j < input.size(); ++j) {
            if (input[j] == '*') {
                // star이 세팅되어있지 않다면 세팅
                if (star == -1) {
                    star = j;
                    int check = checkCorrectStr(input, 0, star - 1, STAR_STATUS::AFTER_STRING);
                    if (check < 0) { // '*'이 나오기 이전의 문자열 비교
                        correct = false;
                        cout << "NO" << endl;
                        break;
                    }
                }
                // 이전에 star가 나온 적이 있다면
                else {
                    star = j; // star의 idx만 업데이트 시켜준다.
                    continue;
                }
            }
        }

        // 이전에 star가 나온적이 있다면
        if (correct && star != -1) {
            cout << (checkCorrectStr(input, star + 1, input.size() - 1, STAR_STATUS::BEFORE_STRING) <= 0 ? "YES" : "NO") << endl; // 마지막으로 나온 '*' 이후의 문자열 비교
        }

        // 이전에 star가 나온적이 없다면
        if (star == -1) {
            cout << (checkCorrectStr(input, 0, input.size() - 1, STAR_STATUS::NO_STAR) == 0 ? "YES" : "NO") << endl;
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

/*
반례들
(*)??)
*/