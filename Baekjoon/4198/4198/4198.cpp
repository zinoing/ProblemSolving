// 4198.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int lis(const vector<int>& trains, int include) {
    vector<int> lis;

    lis.push_back(trains[include]);

    for (int i = include + 1; i < (int)trains.size(); ++i) {
        if (lis.back() < trains[i]) {
            lis.push_back(trains[i]);
        }
        else {
            auto it = lower_bound(lis.begin(), lis.end(), trains[i]);
            *it = trains[i];
        }
    }

    return lis.size();
}

int lds(const vector<int>& trains, int include) {
    vector<int> lds;

    lds.push_back(trains[include]);

    for (int i = include + 1; i < (int)trains.size(); ++i) {
        if (lds.back() > trains[i]) {
            lds.push_back(trains[i]);
        }
        else {
            auto it = lower_bound(lds.begin(), lds.end(), trains[i], greater<int>());
            if (it != lds.end()) {
                *it = trains[i];
            }
        }
    }

    return lds.size();
}

int solution(const vector<int>& trains) {
    int n = trains.size();

    int maxCnt = 0;
    for (int i = 0; i < n; ++i) {
        int leftCnt = lis(trains, i);
        int rightCnt = lds(trains, i);
        int cnt = leftCnt + rightCnt - 1;
        maxCnt = max(maxCnt, cnt);
    }

    return maxCnt;
}

int main()
{
    int n;
    cin >> n;

    vector<int> trains(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> trains[i];
    }

    cout << solution(trains);
    return 0;
}

/*
10
1 2 3 4 5 2 3 4 5 6

5
3 2 1 7 8

6
3 2 1 7 9 8

--
5
1 2 9 7 8
--

5
9 4 3 2 1

5
1 2 3 4 5

5
1 5 2 3 4
*/