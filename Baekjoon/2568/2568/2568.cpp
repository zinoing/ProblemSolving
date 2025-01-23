// 2568.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> lines(500001, 0);

void lis(const vector<int>& lines) {
    vector<int> lis;
    vector<int> record(500001, -1);

    int start = 1;
    while (lines[start] == 0) {
        ++start;
    }

    lis.push_back(lines[start]);
    record[start] = 0;

    for (int i = start + 1; i < 500001; ++i) {
        if (lines[i] == 0) continue;

        if (lis.back() < lines[i]) {
            lis.push_back(lines[i]);
            record[i] = lis.size() - 1;
        }
        else {
            int idx = lower_bound(lis.begin(), lis.end(), lines[i]) - lis.begin();
            lis[idx] = lines[i];
            record[i] = idx;
        }
    }

    cout << n - lis.size() << endl;
    int cnt = lis.size() - 1;

    vector<bool> visited(cnt + 1, false);
    vector<int> linesToRemove;

    for (int i = 500000; i >= 0; --i) {
        if (record[i] == -1) continue;

        if (record[i] == cnt) {
            if (visited[cnt]) {
                cout << i << endl;
            }
            else {
                visited[cnt] = true;
                --cnt;
            }
            continue;
        }

        if (record[i] != -1) {
            linesToRemove.push_back(i);
        }
    }

    sort(linesToRemove.begin(), linesToRemove.end());

    for (auto line : linesToRemove) {
        cout << line << endl;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin >> n;

    int from, to;
    for (int i = 0; i < n; ++i) {
        cin >> from >> to;

        lines[from] = to;
    }

    lis(lines);

    return 0;
}