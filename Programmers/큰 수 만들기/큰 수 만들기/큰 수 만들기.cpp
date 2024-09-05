// 큰 수 만들기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    int start = 0;
    int biggestNum = 0;
    int next = 0;
    string answer = "";
    int cnt = 0;
    while (cnt < number.size() - k) {
        for (int i = start; i <= cnt + k; i++) {
            if ((number[i] - '0') > biggestNum) {
                biggestNum = number[i] - '0';
                next = i + 1;
            }
        }
        ++cnt;
        answer += to_string(biggestNum);
        biggestNum = 0;
        start = next;
    }

    return answer;
}