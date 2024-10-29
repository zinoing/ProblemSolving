// 14002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getLis(const vector<int>& numbers) {
    int n = numbers.size();
    vector<int> dp(n, 0);

    int maxDP = 1;
    //dp 구하기
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (dp[i] <= dp[j] && numbers[i] > numbers[j]) {
                dp[i] = dp[j] + 1;
            }

            maxDP = max(maxDP, dp[i]);
        }
    }

    vector<int> lis;
    for (int i = n - 1; i >= 0; --i) {
        if (dp[i] == maxDP) {
            lis.push_back(numbers[i]);
            --maxDP;
        }
    }

    reverse(lis.begin(), lis.end());

    return lis;
}

int main()
{
    int n;
    cin >> n;

    vector<int> numbers(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    vector<int> lis = getLis(numbers);

    cout << lis.size() << endl;
    for (auto a : lis) {
        cout << a << " ";
    }
}