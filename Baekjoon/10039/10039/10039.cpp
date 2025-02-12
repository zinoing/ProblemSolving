// 10039.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        int input;
        cin >> input;
        if (input < 40) {
            sum += 40;
        }
        else sum += input;
    }

    cout << sum / 5;
}