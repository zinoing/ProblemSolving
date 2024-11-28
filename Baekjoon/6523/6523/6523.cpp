// 6523.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    while (1) {
        int n, a, b;
        cin >> n;
        if (n == 0) break;
        cin >> a >> b;

        unordered_map<unsigned long long, int> map;

        unsigned long long idx = 0;
        map[idx] = 1;

        while (map[idx] != 3) {
            unsigned long long temp = idx * idx % n;
            idx = (a * temp + b) % n;
            map[idx] += 1;
        }

        int drunkCnt = 0;
        for (auto person : map) {
            if (person.second >= 2) ++drunkCnt;
        }
        cout << n - drunkCnt << endl;
    }
    return 0;
}