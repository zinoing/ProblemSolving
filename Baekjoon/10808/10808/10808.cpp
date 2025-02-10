// 10808.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string str;
    cin >> str;

    vector<int> alphabets(26, 0);

    for (int i = 0; i < str.size(); ++i) {
        alphabets[str[i] - 'a'] += 1;
    }

    for (int i = 0; i < 26; ++i) {
        cout << alphabets[i] << " ";
    }
}