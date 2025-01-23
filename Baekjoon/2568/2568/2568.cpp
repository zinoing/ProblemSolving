// 2568.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> lines;

void lis() {
    // 우선적으로 정렬
    sort(lines.begin(), lines.end());

    vector<int> lis;
    vector<int> record(lines.size());

    lis.push_back(lines[0].second);

    for (int i = 1; i < lines.size(); ++i) {
        if (lis.back() < lines[i].second) {
            lis.push_back(lines[i].second);
            record[i] = lis.size() - 1;
        }
        else {
            int idx = lower_bound(lis.begin(), lis.end(), lines[i].second) - lis.begin();
            lis[idx] = lines[i].second;
            record[i] = idx;
        }
    }

    cout << n - lis.size() << "\n";;

    int cnt = lis.size() - 1;
    vector<bool> visited(lines.size(), false);
    vector<int> linesToRemove;

    for (int i = record.size() - 1; i >= 0; --i) {
        if (record[i] == cnt && !visited[i]) {
            --cnt;
            visited[i] = true;
        }
        else {
            linesToRemove.push_back(lines[i].first);
        }
    }

    sort(linesToRemove.begin(), linesToRemove.end());

    for (auto line : linesToRemove) {
        cout << line << "\n";
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

        lines.push_back(make_pair(from, to));
    }

    lis();

    return 0;
}