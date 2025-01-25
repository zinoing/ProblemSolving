// 14888.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int N;
vector<int> nums;
int minNum = INT_MAX;
int maxNum = INT_MIN;

void dfs(int idx, int result, vector<int> operators) {
    if (idx == N) {
        minNum = min(minNum, result);
        maxNum = max(maxNum, result);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if (operators[i] == 0) continue;
        operators[i] -= 1;

        switch (i) {
        case 0:
            dfs(idx + 1, result + nums[idx], operators);
            break;
        case 1:
            dfs(idx + 1, result - nums[idx], operators);
            break;
        case 2:
            dfs(idx + 1, result * nums[idx], operators);
            break;
        case 3:
            dfs(idx + 1, result / nums[idx], operators);
            break;
        }

        operators[i] += 1;
    }
}

int main()
{
    cin >> N;

    nums.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    vector<int> operators(4);
    for (int i = 0; i < 4; ++i) {
        cin >> operators[i];
    }

    dfs(1, nums[0], operators);

    cout << maxNum << "\n";
    cout << minNum;
}