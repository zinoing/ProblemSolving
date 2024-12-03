// 1253.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> numbers(n, 0);
    bool nonZero = false;

    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
        if (numbers[i] != 0) nonZero = true;
    }

    if (!nonZero) {
        cout << n;
        return 0;
    }

    sort(numbers.begin(), numbers.end());

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            bool found = false;
            for (int idx = lower_bound(numbers.begin(), numbers.end(), numbers[i] - numbers[j]) - numbers.begin();
                idx < upper_bound(numbers.begin(), numbers.end(), numbers[i] - numbers[j]) - numbers.begin();
                ++idx)
            {
                if (i == idx || j == idx) continue;
                if (numbers[i] == numbers[j] + numbers[idx]) {
                    //cout << i<< " " << j << " " << idx << endl;
                    ++cnt;
                    found = true;
                    break;
                }
            }

            if (found) break;
        }
    }

    cout << cnt;
    return 0;
}