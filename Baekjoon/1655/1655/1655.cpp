// 1655.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> max_heap;
    priority_queue<int> min_heap;

    int n;
    cin >> n;

    int input;
    for (int i = 0; i < n; ++i) {
        cin >> input;

        if (max_heap.size() == min_heap.size()) {
            min_heap.push(input);
        }else if (max_heap.size() + 1 == min_heap.size()) {
            max_heap.push(input);
        }

        if (max_heap.size() && min_heap.top() > max_heap.top()) {
            int smaller = max_heap.top();
            int bigger = min_heap.top();

            min_heap.pop();
            max_heap.pop();

            min_heap.push(smaller);
            max_heap.push(bigger);
        }

        cout << min_heap.top() << '\n';
    }
}