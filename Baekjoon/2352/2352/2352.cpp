// 2352.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lis(vector<int> ports) {

}

int main()
{
    int n;
    cin >> n;

    vector<int> ports(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> ports[i];
    }

    cout << lis(ports);
    return 0;
}