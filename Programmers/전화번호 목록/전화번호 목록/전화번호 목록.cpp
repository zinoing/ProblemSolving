// 전화번호 목록.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    unordered_map<string, int> number_map;
    int n = phone_book.size();
    for (int i = 0; i < n; ++i) {
        number_map[phone_book[i]] = 1;
    }

    for (int i = 0; i < n; ++i) {
        string phone = phone_book[i];

        for (int j = 0; j < phone.size(); ++j) {
            string newStr = phone.substr(0, j);
            if (number_map[newStr] == 1) return false;
        }
    }

    return answer;
}