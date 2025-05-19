// 1577.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define RIGHT 0
#define UP 1

#include <iostream>
#include <set>
#include <vector>

using namespace std;
typedef pair<int, int> Point;
typedef pair<Point, Point> Road;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<unsigned long long>> dp(M + 1, vector<unsigned long long>(N+1));
    for (int i = 0; i <= M; ++i) {
        for (int j = 0; j <= N; ++j) {
            dp[i][j] = 0;
        }
    }

    set<Road> constructionRoads;

    for (int i = 0; i < K; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Point a = { x1, y1 };
        Point b = { x2, y2 };
        constructionRoads.insert({ a, b });
        constructionRoads.insert({ b, a });
    }

    dp[0][0] = 1;
    for (int y = 0; y <= M; ++y) {
        for (int x = 0; x <= N; ++x) {
            if (x > 0) {
                if (!constructionRoads.count({ {x - 1, y}, {x, y} })) {
                    dp[y][x] += dp[y][x - 1];
                }
            }
            if (y > 0) {
                if (!constructionRoads.count({ {x, y - 1}, {x, y} })) {
                    dp[y][x] += dp[y - 1][x];
                }
            }
        }
    }

    cout << dp[M][N];
}