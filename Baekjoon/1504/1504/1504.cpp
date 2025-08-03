// 1504.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
using namespace std;

int N, E;
unordered_map<int, vector<pair<int, int>>> edges;

int getShortestPathBetweenEdges(int edgeA, int edgeB) {
    int minPath = INT_MAX;

    for (auto edge : edges[edgeA]) {
        if (edge.first == edgeB)
            return edge.second;
        minPath = min(minPath, getShortestPathBetweenEdges(edge.first, edgeB));
    }

    return minPath;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> E;

    for (int i = 0; i < E; ++i) {
        int from, to, distance;
        cin >> from >> to >> distance;

        edges[from].push_back(make_pair(to, distance));
        edges[to].push_back(make_pair(from, distance));
    }

    int essentialEdgeA, essentialEdgeB;
    cin >> essentialEdgeA >> essentialEdgeB;

    int minPath = 0;
    int startDistance = min(getShortestPathBetweenEdges(1, essentialEdgeB), getShortestPathBetweenEdges(1, essentialEdgeA));
    int middleDistance = getShortestPathBetweenEdges(essentialEdgeA, essentialEdgeB);
    int endDistance = min(getShortestPathBetweenEdges(essentialEdgeB, N), getShortestPathBetweenEdges(essentialEdgeA, N));

    minPath += startDistance;
    minPath += middleDistance;
    minPath += endDistance;

    if (startDistance == INT_MAX || middleDistance == INT_MAX || endDistance == INT_MAX)
        minPath = -1;

    cout << minPath;
}