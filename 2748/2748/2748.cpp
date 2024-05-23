// 2748.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long sum = 0;
    long long first = 0;
    long long second = 1;

    int n = 0;
    cin >> n;

    if (n == 0) {
        cout << first;
        return 0;
    }

    if (n == 1) {
        cout << second;
        return 0;
    }

    for (int i = 0; i < n-1; i++) {
        sum = first + second;
        first = second;
        second = sum;
    }

    cout << sum;

    return 0;
}