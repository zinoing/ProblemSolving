// 2504.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string str;
    cin >> str;

    int smallOpenCnt = 0;
    int bigOpenCnt = 0;
    int sum = 0;
    int temp = 1;

    for (int i = 0; i < str.size(); ++i) {
        switch (str[i]) {
        case '(':
            ++smallOpenCnt;
            temp *= 2;
            break;
        case ')':
            --smallOpenCnt;
            if (smallOpenCnt < 0) {
                cout << 0;
                return 0;
            }

            if (str[i - 1] == '(') {
                sum += temp;
                temp /= 2;
            }
            else {
                temp /= 2;
            }
            
            break;
        case '[':
            ++bigOpenCnt;
            temp *= 3;
            break;
        case ']':
            --bigOpenCnt;
            if (bigOpenCnt < 0) {
                cout << 0;
                return 0;
            }
            if (str[i - 1] == '[') {
                sum += temp;
                temp /= 3;
            }
            else {
                temp /= 3;
            }
            break;
        }
    }

    if (bigOpenCnt != 0 || smallOpenCnt != 0) {
        cout << 0;
    }
    else {
        cout << sum;
    }

    return 0;
}