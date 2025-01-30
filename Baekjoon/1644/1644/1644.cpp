// 1644.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> primeNumbers(N + 1);
    vector<int> primeNumberSum;
    bool isPrime = true;

    for (int i = 2; i <= N; ++i) {
        primeNumbers[i] = i;
    }

    for (int i = 2; i <= sqrt(N); ++i) {
        if (primeNumbers[i] == 0) continue;

        for (int j = i*i; j <= N; j += i) {
            primeNumbers[j] = 0;
        }
    }
    primeNumberSum.push_back(0);
    for (int i = 2; i <= N; ++i) {
        if (primeNumbers[i] != 0) {
            primeNumberSum.push_back(primeNumberSum.back() + i);
        }
    }

    int numOfPrimeNums = primeNumberSum.size();
    int left = 0;
    int right = 1;
    int cnt = 0;
    int sum = primeNumberSum[right] - primeNumberSum[left];

    while (left < right && right < numOfPrimeNums) {
        sum = primeNumberSum[right] - primeNumberSum[left];

        if (sum < N) {
            ++right;
        }
        else if (sum > N) {
            ++left;
        }
        else {
            ++cnt;
            ++right;
        }
    }

    cout << cnt;
}