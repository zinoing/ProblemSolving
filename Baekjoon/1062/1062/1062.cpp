// 1062.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
기존에 이미 a, c, n, t, i 5글자를 알고 있다.
*/
int N, K;
vector<bool> alphabets;
vector<string> strs;
int maxWord = 0;

void dfs(int start, int knownCharCount) {
    if (knownCharCount > K) return;
    
    if (knownCharCount == K) {
        int word = 0;
        for (auto str : strs) {
            bool know = true;
            for (auto c : str) {
                if (!alphabets[c - 'a']) {
                    know = false;
                    break;
                }
            }

            if (know) {
                ++word;
            }
        }

        maxWord = max(maxWord, word);
        if (maxWord == N) {
            cout << N << '\n';
            exit(0);
        }
        return;
    }
    
    for (int i = start; i < 26; ++i) {
        if (alphabets[i]) continue;
        alphabets[i] = true;
        dfs(i + 1, knownCharCount + 1);
        alphabets[i] = false;
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    if (K < 5) {
        cout << 0;
        return 0;
    }

    alphabets.resize(26);

    alphabets['a' - 'a'] = true;
    alphabets['c' - 'a'] = true;
    alphabets['t' - 'a'] = true;
    alphabets['n' - 'a'] = true;
    alphabets['i' - 'a'] = true;

    string inputStr;
    for (int i = 0; i < N; ++i) {
        cin >> inputStr;
        strs.push_back(inputStr.substr(4, inputStr.size() - 8));
    }

    dfs(0, 5);

    cout << maxWord;
}