// 11054.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lis(const vector<int>& numbers, int n, bool isAscending = true) {
    vector<int> lis;

    lis.push_back(numbers[0]);

    for (int i = 1; i < n; ++i) {
        if (isAscending) {
            if (lis.back() < numbers[i]) {
                lis.push_back(numbers[i]);
            }
            else {
                int idx = lower_bound(lis.begin(), lis.end(), numbers[i]) - lis.begin();
                lis[idx] = numbers[i];
            }
        }
        else {
            if (lis.back() > numbers[i]) {
                lis.push_back(numbers[i]);
            }
            else {
                for (int j = 0; j < lis.size(); ++j) {
                    if (lis[j] <= numbers[i]) {
                        lis[j] = numbers[i];
                        break;
                    }
                };
            }
        }
    }

    return lis.size();
}

int bitonic(const vector<int>& numbers, int n) {
    int maxSize = 0;

    // 시작점 정하기
    for (int i = 0; i < n; ++i) {
        // 증가 부분의 길이
        int size_up = lis(numbers, i + 1, true);
        // 감소 부분의 길이
        int size_down = lis(vector<int>(numbers.begin() + i, numbers.end()), n - i, false);
        // 중간점이 겹쳐서 포함되므로 1을 빼준다.
        maxSize = max(maxSize, size_up + size_down - 1);
    }

    return maxSize;
}

int main()
{
    int n;
    cin >> n;

    vector<int> numbers(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    cout << bitonic(numbers, n);
    return 0;
}