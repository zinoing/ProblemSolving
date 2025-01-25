// 3460.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int n;
        cin >> n;

        int cnt = 0;
        while (n > 0) {
            if (n % 2 == 1) {
                cout << cnt << " ";
            }
            n /= 2;
            ++cnt;
        }
    }
}