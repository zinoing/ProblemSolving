// 2526.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
using namespace std;

int N, P;

int main()
{
    cin >> N >> P;

    unordered_map<int, int> nodes;

    int idx = 0;
    nodes[N] = idx;
    int last = N;

    while (1) {
        ++idx;
        int nextVal = (last * N) % P;
        if (nodes[nextVal] != 0) {
            cout << idx - nodes[nextVal];
            return 0;
        }
        else nodes[nextVal] = idx;
        last = nextVal;
    }

    return 0;
}