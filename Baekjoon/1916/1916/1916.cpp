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
        // �ִ� �Ÿ��� ��� �˻�
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

        // �ش� ��� �湮 ó��
        visited[minNode] = true;

        // �湮���� �ʾҴ� node�� �� �ִ� �Ÿ��� ��带 �����Ͽ� ���� �� �߿� �� ����� ��尡 �����ϴ��� Ȯ��
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