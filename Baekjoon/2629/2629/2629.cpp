// 2629.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numOfWeights;
    cin >> numOfWeights;
    vector<int> weights(numOfWeights);

    for (int i = 0; i < numOfWeights; ++i) {
        cin >> weights[i];
    }

    int numOfMarbles;
    cin >> numOfMarbles;
    vector<int> marbles(numOfMarbles);

    for (int i = 0; i < numOfMarbles; ++i) {
        cin >> marbles[i];
    }

    unordered_set<int> possible_values;
    possible_values.insert(0);

    for (int weight : weights) {
        unordered_set<int> new_values;

        for (int current : possible_values) {
            new_values.insert(current + weight);
            new_values.insert(current > weight ? current - weight : weight - current);  
        }

        for (int new_val : new_values) {
            possible_values.insert(new_val);
        }
    }

    for (int i = 0; i < numOfMarbles; ++i) {
        cout << (possible_values.find(marbles[i]) != possible_values.end() ? 'Y' : 'N') << ' ';
    }

}
