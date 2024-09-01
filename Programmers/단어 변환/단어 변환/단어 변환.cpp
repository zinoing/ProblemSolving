// 단어 변환.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int dfs(string begin, string target, vector<string> words) {
    stack<pair<string, int>> strStack;
    strStack.push(make_pair(begin, 0));

    while (!strStack.empty()) {
        pair<string, int> popedPair = strStack.top();
        strStack.pop();

        if (popedPair.first == target) {
            return popedPair.second;
        }

        for (int i = 0; i < words.size(); i++) {
            int cnt = 0;
            if (words[i] == "") continue;

            for (int j = 0; j < popedPair.first.size(); j++) {
                if (popedPair.first[j] == words[i][j]) {
                    ++cnt;
                }
            }

            if (cnt == popedPair.first.size() - 1) {
                strStack.push(make_pair(words[i], popedPair.second + 1));
                words[i] = "";
            }
        }
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = dfs(begin, target, words);
    return answer;
}