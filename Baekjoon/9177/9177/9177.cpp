// 9177.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <tuple>
using namespace std;

string a, b, c;

void solve(int i) {
    bool possible = false;

    vector<vector<bool>> visited(a.size() + 1, vector<bool>(b.size() + 1));

    int aIdx = 0;
    int bIdx = 0;
    int cIdx = 0;

    queue<tuple<int, int, int>> q;
    q.push(make_tuple(aIdx, bIdx, cIdx));

    while (!q.empty()) {
        auto idxes = q.front();
        q.pop();

        aIdx = get<0>(idxes);
        bIdx = get<1>(idxes);
        cIdx = get<2>(idxes);

        if (aIdx == a.size() && bIdx == b.size() && cIdx == c.size()) {
            possible = true;
            break;
        }
        if (visited[aIdx][bIdx]) continue;

        visited[aIdx][bIdx] = true;

        if (a[aIdx] == c[cIdx]) {
            q.push(make_tuple(aIdx + 1, bIdx, cIdx + 1));
        }

        if (b[bIdx] == c[cIdx]) {
            q.push(make_tuple(aIdx, bIdx + 1, cIdx + 1));
        }
    }

    cout << "Data set " << i << ": " << (possible ? "yes" : "no") << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c;
        solve(i + 1);
    }

    return 0;
}