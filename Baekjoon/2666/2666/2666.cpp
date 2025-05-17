// 2666.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> sequence;

int dp(int a, int b, int idx) {
    if (idx == sequence.size()) {
        return 0;
    }

    int m = sequence[idx];
    /*
    if a < b ¶ó¸é
    1. a < m < b
    2. a < b < m
    3. m < a < b
    4. m == a || m == b
    */

    if (a < m && m < b) {
        return min(dp(m, b, idx + 1) + (m - a), dp(a, m, idx + 1) + (b - m));
    }

    if (b < m) {
        return dp(a, m, idx + 1) + (m - b);
    }

    if (m < a) {
        return dp(m, b, idx + 1) + (a - m);
    }

    if (m == a || m == b) {
        return dp(a, b, idx + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> empty(2);
    cin >> empty[0] >> empty[1];

    int sizeOfSequence;
    cin >> sizeOfSequence;

    sequence.resize(sizeOfSequence);
    for (int i = 0; i < sizeOfSequence; ++i) {
        cin >> sequence[i];
    }

    cout << dp(empty[0], empty[1], 0);

    return 0;
}
