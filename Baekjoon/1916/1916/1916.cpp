// 1916.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;

int N, M;
int main()
{
    cin >> N >> M;

    vector<int> dist(N+1);
    vector<vector<int>> weights(N+1, vector<int>(N+1));
    vector<bool> visited(N+1);

    for (int i = 0; i <= N; ++i) {
        fill(weights[i].begin(), weights[i].end(), INT_MAX);
    }

    for (int i = 1; i <= N; ++i) {
        weights[i][i] = 0;
    }

    int start, end, cost;
    for (int i = 0; i < M; ++i) {
        cin >> start >> end >> cost;
        if(weights[start][end] > cost)
            weights[start][end] = cost;
    }

    cin >> start >> end;

    for (int i = 1; i <= N; ++i) {
        dist[i] = weights[start][i];
    }
    visited[start] = true;

    for (int i = 1; i <= N; ++i) {
        // 최단 거리의 노드 검색
        int minNode = 0;
        int minWeight = INT_MAX;
        for (int j = 1; j <= N; ++j) {
            if (!visited[j]) {
                if (minWeight >= weights[start][j]) {
                    minWeight = weights[start][j];
                    minNode = j;
                }
            }
        }

        if (minNode == 0) break;

        // 해당 노드 방문 처리
        visited[minNode] = true;

        // 방문하지 않았던 node들 중 최단 거리의 노드를 경유하여 가는 길 중에 더 가까운 노드가 존재하는지 확인
        for (int j = 1; j <= N; ++j) {
            if (!visited[j]) {
                if ((long long)dist[minNode] + weights[minNode][j] < dist[j]) {
                    dist[j] = (long long)dist[minNode] + weights[minNode][j];
                }
            }
        }
    }
    cout << dist[end];
    return 0;
}