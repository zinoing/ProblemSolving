// 의상.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> clothes_cnt;

    for (auto cloth : clothes) {
        clothes_cnt[cloth[1]] += 1;
    }

    int answer = 1;
    for (auto cnt : clothes_cnt) {
        answer *= (cnt.second + 1);
    }
    answer -= 1;
    return answer;
}