// 1806.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, S;
    cin >> N >> S;

    vector<int> nums(N + 1);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    
    int left = 0;
    int right = 0;
    int sum = nums[0];
    int minLength = 100001;

    while(right < N && left <= right) {
        if (sum < S) {
            sum += nums[++right];
        }
        else {
            minLength = min(minLength, right - left + 1);
            sum -= nums[left++];
        }
    }

    if (minLength == 100001) minLength = 0;
    cout << minLength;
    return 0;
}