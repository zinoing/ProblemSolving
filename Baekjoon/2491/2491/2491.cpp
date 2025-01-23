// 2491.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int N;
int num[100001];
int ascending[100001];
int descending[100001];

int main()
{
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> num[i];
    }

    for (int i = 0; i < 100001; ++i) {
        ascending[i] = 1;
        descending[i] = 1;
    }

    int maxAscending = 1;
    int maxDescending = 1;

    for (int i = 1; i < N; ++i) {
        if (num[i] > num[i - 1]) {
            ascending[i] = ascending[i - 1] + 1;
            maxAscending = max(maxAscending, ascending[i]);
        }
        else if (num[i] < num[i - 1]) {
            descending[i] = descending[i - 1] + 1;
            maxDescending = max(maxDescending, descending[i]);
        }
        else {
            ascending[i] = ascending[i - 1] + 1;
            descending[i] = descending[i - 1] + 1;
            maxAscending = max(maxAscending, ascending[i]);
            maxDescending = max(maxDescending, descending[i]);
        }
    }

    cout << max(maxAscending, maxDescending);
}