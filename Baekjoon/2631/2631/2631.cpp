// 2631.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int lis(const vector<int> vec) {
    int n = vec.size();

    vector<int> lis;
    lis.push_back(vec[0]);

    for (int i = 1; i < n; ++i) {
        if (lis.back() < vec[i]) {
            lis.push_back(vec[i]);
        }
        else {
            lis[lower_bound(lis.begin(), lis.end(), vec[i]) - lis.begin()] = vec[i];
        }
    }

    return lis.size();
}

int main()
{
    int N;
    cin >> N;
    vector<int> children(N, 0);

    for (int i = 0; i < N; ++i) {
        cin >> children[i];
    }

    cout << N - lis(children);
}