// 7476.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t hash = 0;
        for (const auto& num : v) {
            hash ^= hash * 31 + std::hash<int>()(num);
        }
        return hash;
    }
};

void lis(const vector<int>& sequence, unordered_map<vector<int>, int, VectorHash>& map, vector<int> increasingSequence, int start) {
    int n = (int)sequence.size();

    if (start == n) return;

    for (int i = start; i < n; ++i) {
        if (increasingSequence.empty() || increasingSequence.back() < sequence[i]) {
            increasingSequence.push_back(sequence[i]);
            map[increasingSequence] += 1;
            // 재귀적으로 호출
            lis(sequence, map, increasingSequence, i + 1);
            increasingSequence.pop_back();
        }
    }
}

void findCommonNumbers(vector<int>& firstSequence, vector<int>& secondSequence) {
    unordered_set<int> firstSet(firstSequence.begin(), firstSequence.end());
    unordered_set<int> secondSet(secondSequence.begin(), secondSequence.end());
    vector<int> newFirst, newSecond;

    for (int num : secondSequence) {
        if (firstSet.count(num)) {
            newSecond.push_back(num);
        }
    }

    for (int num : firstSequence) {
        if (secondSet.count(num)) {
            newFirst.push_back(num);
        }
    }

    firstSequence = newFirst;
    secondSequence = newSecond;
    return;
}

int main()
{
    // 첫 번째 수열 입력
    int m1;
    cin >> m1;

    vector<int> firstSequence(m1, 0);

    for (int i = 0; i < m1; ++i) {
        cin >> firstSequence[i];
    }

    // 두 번째 수열 입력
    int m2;
    cin >> m2;

    vector<int> secondSequence(m2, 0);

    for (int i = 0; i < m2; ++i) {
        cin >> secondSequence[i];
    }

    // 공통 숫자로 이루어진 vector로 구성
    findCommonNumbers(firstSequence, secondSequence);

    unordered_map<vector<int>, int, VectorHash> map;
    vector<int> increasingSequence;
    // 첫 번째 수열의 increasing subsequence들 모두 구하기
    lis(firstSequence, map, increasingSequence, 0);
    increasingSequence.clear();
    // 두 번째 수열의 increasing subsequence들 모두 구하기
    lis(secondSequence, map, increasingSequence, 0);

    int maxVal = 0;
    vector<int> maxVec;
    for (auto c : map) {
        if (c.second == 2 && c.second > maxVal) {
            maxVec = c.first;
            maxVal = maxVec.size();
        }
    }

    cout << maxVal << endl;
    for (auto c : maxVec) {
        cout << c << " ";
    }
    return 0;
}