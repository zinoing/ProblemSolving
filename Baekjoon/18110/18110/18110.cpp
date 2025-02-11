// 18110.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    vector<int> opinions(n);
    for (int i = 0; i < n; ++i) {
        cin >> opinions[i];
    }

    sort(opinions.begin(), opinions.end());
    int numberOfOpinionsToExclude = round((float)(n * 15) / 100);
    int left = numberOfOpinionsToExclude;
    int right = n - 1 - numberOfOpinionsToExclude;

    int sum = 0;
    for (int i = left; i <= right; ++i) {
        sum += opinions[i];
    }

    cout << round((float)sum / (right - left + 1));
}