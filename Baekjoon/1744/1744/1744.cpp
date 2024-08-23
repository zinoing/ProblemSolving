// 1744.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

auto ans = 0;

bool cmp(int a, int b) {
    return a > b;
}

int main()
{
    int N;
    cin >> N;

    vector<int> positiveNumbers;
    vector<int> negativeNumbers;

    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;

        if(input > 0)
            positiveNumbers.push_back(input);
        else
            negativeNumbers.push_back(input);
    }

    if (!positiveNumbers.empty()) {
        sort(positiveNumbers.begin(), positiveNumbers.end(), cmp);

        for (int i = 0; i < positiveNumbers.size() - 1; i += 2) {
            if (positiveNumbers[i] * positiveNumbers[i + 1] > positiveNumbers[i] + positiveNumbers[i + 1]) {
                ans += positiveNumbers[i] * positiveNumbers[i + 1];
            }
            else {
                ans += positiveNumbers[i] + positiveNumbers[i + 1];
            }
        }

        if (positiveNumbers.size() % 2 == 1) {
            ans += positiveNumbers.back();
        }
    }

    if (!negativeNumbers.empty()) {
        sort(negativeNumbers.begin(), negativeNumbers.end());

        for (int i = 0; i < negativeNumbers.size() - 1; i += 2) {
            ans += negativeNumbers[i] * negativeNumbers[i + 1];
        }

        if (negativeNumbers.size() % 2 == 1) {
            ans += negativeNumbers.back();
        }
    }

    cout << ans;

    return 0;
}
