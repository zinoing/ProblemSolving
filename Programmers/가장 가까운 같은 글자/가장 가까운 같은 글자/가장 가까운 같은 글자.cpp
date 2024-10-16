// 가장 가까운 같은 글자.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    unordered_map<char, int> map;

    for (int i = 0; i < s.size(); ++i) {
        map[s[i]] = -1;
    }

    vector<int> answer;
    for (int i = 0; i < s.size(); ++i) {
        if (map[s[i]] == -1) answer.push_back(map[s[i]]);
        else answer.push_back(i - map[s[i]]);
        map[s[i]] = i;
    }
    return answer;
}