// 2352.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lis(const vector<int>& ports) {
    vector<int> lis;

    lis.push_back(ports[0]);
    for (int i = 1; i < ports.size(); ++i) {
        if (lis.back() < ports[i]) {
            lis.push_back(ports[i]);
        }
        else {
            lis[lower_bound(lis.begin(), lis.end(), ports[i]) - lis.begin()] = ports[i];
        }
    }

    return lis.size();
}

int main()
{
    int n;
    cin >> n;

    vector<int> ports(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> ports[i];
    }

    cout << lis(ports);
    return 0;
}