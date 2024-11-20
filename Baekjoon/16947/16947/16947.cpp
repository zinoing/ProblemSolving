// 16947.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#define MAX_EDGE 3001
using namespace std;

int N;
unordered_map<int, vector<int>> edges;
bool visited[MAX_EDGE];
int previousEdges[MAX_EDGE];
bool cycleEdges[MAX_EDGE];
int distanceFromCycle[MAX_EDGE];

bool isCycle = false;

void findCycle(int edge) {
    visited[edge] = true;
    int parent = previousEdges[edge];

    for (int i = 0; i < edges[edge].size(); ++i) {
        if (isCycle) return;

        int next = edges[edge][i];
        if (visited[next]) {
            if (next != parent) {
                isCycle = true;
                cycleEdges[edge] = true;

                while (edge != next) {
                    edge = previousEdges[edge];
                    cycleEdges[edge] = true;
                }
                return;
            }
        }
        else {
            previousEdges[next] = edge;
            findCycle(next);
        }
    }
    return;
}

void findDistanceFromCycle() {
    queue<int> q;

    for (int i = 1; i <= N; ++i) {
        if (cycleEdges[i]) {
            q.push(i);
            distanceFromCycle[i] = 0;
        }
        else {
            distanceFromCycle[i] = -1;
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (cycleEdges[i]) {
            q.push(i);
            distanceFromCycle[i] = 0;
        }
        else {
            distanceFromCycle[i] = -1;
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int next : edges[node]) {
            if (distanceFromCycle[next] == -1) {
                distanceFromCycle[next] = distanceFromCycle[node] + 1;
                q.push(next);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        int from, to;
        cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }

    findCycle(1);
    findDistanceFromCycle();

    for (int i = 1; i <= N; ++i) {
        cout << distanceFromCycle[i] << " ";
    }
    return 0;
}