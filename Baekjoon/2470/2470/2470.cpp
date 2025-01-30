// 2470.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

    vector<int> solutions;

    int N;
    cin >> N;

    int input = 0;
    for (int i = 0; i < N; ++i) {
        cin >> input;
        solutions.push_back(input);
    }

    sort(solutions.begin(), solutions.end());

    int solutionSize = solutions.size();
    
    int start = 0;
    int end = solutionSize - 1;
    int sum = solutions[start] + solutions[end];

    int minVal = 2000000001;
    pair<int, int> solution;
    while (start < end) {

        sum = solutions[start] + solutions[end];

        if (minVal > abs(sum)) {
            minVal = abs(sum);
            solution = make_pair(solutions[start], solutions[end]);
        }

        if (sum > 0) {
            --end;
        }
        else if(sum < 0) {
            ++start;
        }
        else {
            cout << solutions[start] << " " << solutions[end];
            return 0;
        }
    }

    cout << solution.first << " " << solution.second;
    return 0;
}

/*
5

100 -1 -2 -3 -4

정답 : -2, -1

5

-100 1 2 3 4

정답 : 1,2
*/