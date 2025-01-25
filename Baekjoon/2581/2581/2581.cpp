// 2581.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
using namespace std;

bool checkPrimeNum(int num) {
    if (num == 1) return false;

    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main()
{
    int M, N;
    cin >> M >> N;

    vector<int> primeNums;
    for (int i = M; i <= N; ++i) {
        if (checkPrimeNum(i)) primeNums.push_back(i);
    }

    if (primeNums.empty()) {
        cout << -1;
    }
    else {
        cout << accumulate(primeNums.begin(), primeNums.end(), 0) << endl;
        cout << primeNums[0];
    }
    return 0;
}