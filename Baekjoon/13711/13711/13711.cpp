// 13711.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> subsequence1(N + 1);
    vector<int> subsequence2(N + 1);

    unordered_map<int, int> numMap;
    vector<int> lis;

    for (int i = 1; i <= N; ++i) {
        cin >> subsequence1[i];
        numMap[subsequence1[i]] = i;
    }

    for (int i = 1; i <= N; ++i) {
        cin >> subsequence2[i];
    }

    lis.push_back(0);

    for (int i = 1; i <= N; ++i) {
        if (numMap[subsequence2[i]] < lis.back()) {
            lis[lower_bound(lis.begin(), lis.end(), numMap[subsequence2[i]]) - lis.begin()] = numMap[subsequence2[i]];
        }
        else {
            lis.push_back(numMap[subsequence2[i]]);
        }
    }

    cout << lis.size() - 1;
}

/*
5
3 2 4 1 5
5 4 1 2 3

5
1 3 2 4 5
4 1 2 3 5
*/