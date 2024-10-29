// 2365.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lis(const vector<pair<int, int>>& wires) {
    int n = wires.size();

    vector<int> lis;
    lis.push_back(wires[0].second);

    for (int i = 1; i < n; ++i) {
        int to = wires[i].second;

        if (lis.back() < to) {
            lis.push_back(to);
        }
        else {
            lis[lower_bound(lis.begin(), lis.end(), to) - lis.begin()] = to;
        }
    }

    return lis.size();
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> wires(n);

    for (int i = 0; i < n; ++i) {
        int from, to;
        cin >> from >> to;
        wires[i] = make_pair(from, to);
    }

    sort(wires.begin(), wires.end());

    cout << n - lis(wires);

    return 0;
}