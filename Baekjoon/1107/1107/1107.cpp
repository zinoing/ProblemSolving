// 1107.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX_VAL 500000

using namespace std;

bool check(int number,
    const vector<bool>& brokenButtons) {
    if (number == 0 && brokenButtons[0]) return false;
    while (number > 0) {
        if (brokenButtons[number % 10]) return false;
        number /= 10;
    }

    return true;
}

int findPressCount(int n,
    const int& number,
    const vector<bool>& brokenButtons) {

    if (number == 0) {
        for (int i = 0; i < 10; ++i) {
            if (!brokenButtons[i]) {
                return i + 1;
            }
        }
        return 100;
    }

    if (n == 10) return abs(100 - number);

    int closestChannel = 0;
    int diff = MAX_VAL;
    for (int i = 0; i <= 2 * MAX_VAL; ++i) {
        if (check(i, brokenButtons)) {
            if (abs(number - i) < diff) {
                diff = abs(number - i);
                closestChannel = i;
            }
        }
    }

    return min(abs(number - closestChannel) + (int)to_string(closestChannel).size(),
        abs(100 - number));
}

int main()
{
    string str;
    getline(cin, str);

    int n;
    cin >> n;

    vector<bool> brokenButtons(10, false);

    for (int i = 0; i < n; ++i) {
        int broke;
        cin >> broke;
        brokenButtons[broke] = true;
    }

    cout << findPressCount(n, stoi(str), brokenButtons);

    return 0;
}