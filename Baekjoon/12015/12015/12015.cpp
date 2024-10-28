// 12015.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int lis(const vector<int>& numbers) {
    vector<int> lis;

    lis.push_back(numbers[0]);

    for (int i = 1; i < numbers.size(); ++i) {
        if (lis.back() < numbers[i]) {
            lis.push_back(numbers[i]);
        }
        else {
            lis[lower_bound(lis.begin(), lis.end(), numbers[i]) - lis.begin()] = numbers[i];
        }
    }

    return lis.size();
}

int main()
{
    int n;
    cin >> n;

    vector<int> numbers(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    cout << lis(numbers);
}