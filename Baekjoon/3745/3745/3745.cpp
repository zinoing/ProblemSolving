// 3745.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int lis(vector<int>& stockPrices) {
    vector<int> lis;

    lis.push_back(stockPrices[0]);

    for (int i = 1; i < stockPrices.size(); ++i) {
        if (lis.back() < stockPrices[i]) {
            lis.push_back(stockPrices[i]);
        }
        else {
            lis[lower_bound(lis.begin(), lis.end(), stockPrices[i]) - lis.begin()] = stockPrices[i];
        }
    }

    return lis.size();
}

int main()
{
    int n;
    while (cin >> n) {
        vector<int> stockPrices(n, 0);

        for (int i = 0; i < n; ++i) {
            cin >> stockPrices[i];
        }

        cout << lis(stockPrices) << endl;
    }
}