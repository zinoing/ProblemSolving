// 10972.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> input(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }

    if (next_permutation(input.begin(), input.end())) {
        for (auto c : input) {
            cout << c << " ";
        }
    }
    else {
        cout << -1;
    }

    return 0;
}